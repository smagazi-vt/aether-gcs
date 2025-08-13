#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import math
import time
from aether_interfaces.msg import FleetState
from mavros_msgs.srv import CommandBool, SetMode, CommandTOL
# from mavros_msgs.msg import ObstacleDistance, State
from mavros_msgs.msg import State
from nav_msgs.msg import Odometry
from nav_msgs.msg import Odometry
from std_srvs.srv import Trigger

class SwarmCoordinatorNode(Node):
    """
    For the MVP, this node provides GCS-based collision avoidance and
    executes a simple, hardcoded mission for a single drone.
    """
    def __init__(self):
        super().__init__('swarm_coordinator_node')
        self.get_logger().info("--- Aether GCS Swarm Coordinator (MVP) Starting ---")

        # --- State ---
        self.active_drones = {}  # {id: {"odom": Odometry, "publisher": Publisher, "state": State}}
        self.active_subs = {}

        # --- Configuration ---
        self.safety_distance = 15.0  # meters
        self.mission_altitude = 5.0 # meters

        # --- ROS 2 Interfaces ---
        self.fleet_state_sub = self.create_subscription(
            FleetState, '/aether/fleet_state', self.fleet_state_callback, 10)

        self.start_mission_service = self.create_service(Trigger, '/aether/start_mission', self.start_mission_callback)

        self.collision_check_timer = self.create_timer(0.1, self.check_collisions) # 10 Hz

        self.get_logger().info("Swarm Coordinator is ready.")

    def fleet_state_callback(self, msg):
        """Dynamically creates and destroys subscribers based on the active fleet."""
        current_drone_ids = {drone.system_id for drone in msg.drones}
        known_drone_ids = set(self.active_drones.keys())

        for drone_id in current_drone_ids - known_drone_ids:
            self.add_drone(drone_id)

        for drone_id in known_drone_ids - current_drone_ids:
            self.remove_drone(drone_id)

    def add_drone(self, drone_id):
        """Sets up the necessary publishers and subscribers for a new drone."""
        self.get_logger().info(f"Coordinator discovering new drone: {drone_id}")
        odom_topic = f'/drone{drone_id}/mavros/global_position/local'
        obstacle_topic = f'/drone{drone_id}/mavros/obstacle/send'
        state_topic = f'/drone{drone_id}/mavros/state'

        self.active_drones[drone_id] = {
            "odom": None,
            "state": None,
            "publisher": self.create_publisher(ObstacleDistance, obstacle_topic, 10)
        }
        
        odom_sub = self.create_subscription(
            Odometry, odom_topic, lambda msg, id=drone_id: self.position_callback(msg, id), 10)
        state_sub = self.create_subscription(
            State, state_topic, lambda msg, id=drone_id: self.state_callback(msg, id), 10)
        self.active_subs[drone_id] = {'odom': odom_sub, 'state': state_sub}

    def remove_drone(self, drone_id):
        """Cleans up resources for a disconnected drone."""
        self.get_logger().info(f"Coordinator losing drone: {drone_id}")
        if drone_id in self.active_subs:
            self.destroy_subscription(self.active_subs[drone_id]['odom'])
            self.destroy_subscription(self.active_subs[drone_id]['state'])
            del self.active_subs[drone_id]
        if drone_id in self.active_drones:
            self.destroy_publisher(self.active_drones[drone_id]["publisher"])
            del self.active_drones[drone_id]

    def position_callback(self, msg, drone_id):
        if drone_id in self.active_drones:
            self.active_drones[drone_id]["odom"] = msg
            
    def state_callback(self, msg, drone_id):
        if drone_id in self.active_drones:
            self.active_drones[drone_id]["state"] = msg

    def check_collisions(self):
        """The core loop for the 'virtual sensor' collision avoidance."""
        drone_ids = list(self.active_drones.keys())
        if len(drone_ids) < 2:
            return

        # For the MVP, we assume Drone 1 is real and Drone 2 is the virtual intruder
        id1 = 1
        id2 = 2

        if id1 not in self.active_drones or id2 not in self.active_drones:
            return

        odom1 = self.active_drones[id1].get("odom")
        odom2 = self.active_drones[id2].get("odom")

        if odom1 is None or odom2 is None:
            return

        pos1 = odom1.pose.pose.position
        pos2 = odom2.pose.pose.position

        dx = pos1.x - pos2.x
        dy = pos1.y - pos2.y
        dist = math.sqrt(dx*dx + dy*dy)

        if dist < self.safety_distance:
            self.get_logger().warn(f"Collision alert between Drone {id1} and {id2}! Distance: {dist:.2f}m")
            # Send an obstacle message ONLY to the physical drone
            self.send_obstacle_message(id1, id2, dist)

    def send_obstacle_message(self, own_id, intruder_id, distance):
        """Sends an OBSTACLE_DISTANCE message to a drone."""
        own_odom = self.active_drones.get(own_id, {}).get("odom")
        intruder_odom = self.active_drones.get(intruder_id, {}).get("odom")
        
        if own_odom is None or intruder_odom is None:
            return

        dx = intruder_odom.pose.pose.position.x - own_odom.pose.pose.position.x
        dy = intruder_odom.pose.pose.position.y - own_odom.pose.pose.position.y
        angle_rad = math.atan2(dy, dx)
        angle_deg = math.degrees(angle_rad)

        msg = ObstacleDistance()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.sensor_type = 3 # MAV_SENSOR_ROTATION_CUSTOM
        msg.increment_f = 360.0
        msg.min_distance = 100
        msg.max_distance = 10000
        
        # TODO: understand reasoning for the math behind this...
        distances = [65535] * 72
        angle_index = int((angle_deg + 180) / 5) % 72
        distances[angle_index] = int(distance * 100)
        msg.distances = distances

        self.active_drones[own_id]["publisher"].publish(msg)

    def start_mission_callback(self, request, response):
        """Commands the primary drone (ID 1) to execute a simple mission."""
        self.get_logger().info("Received START MISSION command for Drone 1.")
        drone_id = 1

        if drone_id not in self.active_drones:
            response.success = False
            response.message = "Drone 1 is not currently active."
            return response

        # Create clients for the necessary services
        set_mode_client = self.create_client(SetMode, f'/drone{drone_id}/mavros/set_mode')
        arming_client = self.create_client(CommandBool, f'/drone{drone_id}/mavros/cmd/arming')
        takeoff_client = self.create_client(CommandTOL, f'/drone{drone_id}/mavros/cmd/takeoff')

        # This is a simple, blocking sequence for the demo.
        # A full system would use asynchronous calls and state machines.
        try:
            # 1. Set mode to OFFBOARD
            self.get_logger().info("Setting mode to OFFBOARD...")
            set_mode_client.wait_for_service(timeout_sec=2.0)
            mode_req = SetMode.Request(custom_mode="OFFBOARD")
            set_mode_client.call(mode_req)
            time.sleep(1)

            # 2. Arm the drone
            self.get_logger().info("Arming drone...")
            arming_client.wait_for_service(timeout_sec=2.0)
            arm_req = CommandBool.Request(value=True)
            arming_client.call(arm_req)
            time.sleep(2)

            # 3. Takeoff
            self.get_logger().info(f"Taking off to {self.mission_altitude} meters...")
            takeoff_client.wait_for_service(timeout_sec=2.0)
            takeoff_req = CommandTOL.Request(altitude=self.mission_altitude)
            takeoff_client.call(takeoff_req)
            
            response.success = True
            response.message = "Mission sequence initiated for Drone 1."
        except Exception as e:
            response.success = False
            response.message = f"Failed to execute mission sequence: {e}"
            self.get_logger().error(response.message)
            
        return response

def main(args=None):
    rclpy.init(args=args)
    node = SwarmCoordinatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
