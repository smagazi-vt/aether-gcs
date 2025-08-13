#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import math
import time
from aether_interfaces.msg import FleetState
from mavros_msgs.srv import CommandBool, SetMode, CommandTOL
from mavros_msgs.msg import State
from geometry_msgs.msg import TwistStamped # Import for velocity commands
from nav_msgs.msg import Odometry
from std_srvs.srv import Trigger

class SwarmCoordinatorNode(Node):
    """
    The definitive 'brain' for the Aether GCS MVP. It provides GCS-based
    collision avoidance via direct velocity override and executes a simple,
    hardcoded mission for a single drone.
    """
    def __init__(self):
        super().__init__('swarm_coordinator_node')
        self.get_logger().info("--- Aether GCS Swarm Coordinator (MVP) Starting ---")

        # --- State ---
        self.active_drones = {}  # {id: {"odom": Odometry, "state": State, "velocity_pub": Publisher}}
        self.active_subs = {}

        # --- Configuration ---
        self.safety_distance = 15.0  # meters
        self.mission_altitude = 5.0 # meters

        # --- ROS 2 Interfaces ---
        self.fleet_state_sub = self.create_subscription(
            FleetState, '/aether/fleet_state', self.fleet_state_callback, 10)

        self.start_mission_service = self.create_service(Trigger, '/aether/start_mission', self.start_mission_callback)
        self.land_service = self.create_service(Trigger, '/aether/swarm_land', self.swarm_land_callback)
        self.rtl_service = self.create_service(Trigger, '/aether/swarm_rtl', self.swarm_rtl_callback)

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
        state_topic = f'/drone{drone_id}/mavros/state'
        velocity_topic = f'/drone{drone_id}/mavros/setpoint_velocity/cmd_vel_unstamped'

        self.active_drones[drone_id] = {
            "odom": None,
            "state": None,
            "velocity_pub": self.create_publisher(TwistStamped, velocity_topic, 10)
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
            self.destroy_publisher(self.active_drones[drone_id]["velocity_pub"])
            del self.active_drones[drone_id]

    def position_callback(self, msg, drone_id):
        if drone_id in self.active_drones:
            self.active_drones[drone_id]["odom"] = msg
            
    def state_callback(self, msg, drone_id):
        if drone_id in self.active_drones:
            self.active_drones[drone_id]["state"] = msg

    def check_collisions(self):
        """The core loop for the collision avoidance."""
        id1 = 1 # The physical drone
        id2 = 2 # The virtual drone

        if id1 not in self.active_drones or id2 not in self.active_drones:
            return

        odom1 = self.active_drones[id1].get("odom")
        odom2 = self.active_drones[id2].get("odom")

        if odom1 is None or odom2 is None:
            return

        pos1 = odom1.pose.pose.position
        pos2 = odom2.pose.pose.position

        dist = math.sqrt((pos1.x - pos2.x)**2 + (pos1.y - pos2.y)**2)

        if dist < self.safety_distance:
            self.get_logger().warn(f"Collision alert! Drone {id1} stopping. Distance to Drone {id2}: {dist:.2f}m")
            self.send_stop_command(id1)

    def send_stop_command(self, drone_id):
        """Sends a zero-velocity TwistStamped message to make the drone hold position."""
        if drone_id in self.active_drones:
            msg = TwistStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "map"
            self.active_drones[drone_id]["velocity_pub"].publish(msg)

    def start_mission_callback(self, request, response):
        """Commands the primary drone (ID 1) to execute a simple mission."""
        self.get_logger().info("Received START MISSION command for Drone 1.")
        drone_id = 1

        if drone_id not in self.active_drones:
            response.success = False
            response.message = "Drone 1 is not currently active."
            return response

        set_mode_client = self.create_client(SetMode, f'/drone{drone_id}/mavros/set_mode')
        arming_client = self.create_client(CommandBool, f'/drone{drone_id}/mavros/cmd/arming')
        takeoff_client = self.create_client(CommandTOL, f'/drone{drone_id}/mavros/cmd/takeoff')

        try:
            self.get_logger().info("Setting mode to OFFBOARD...")
            set_mode_client.wait_for_service(timeout_sec=2.0)
            set_mode_client.call(SetMode.Request(custom_mode="OFFBOARD"))
            time.sleep(1)

            self.get_logger().info("Arming drone...")
            arming_client.wait_for_service(timeout_sec=2.0)
            arming_client.call(CommandBool.Request(value=True))
            time.sleep(2)

            self.get_logger().info(f"Taking off to {self.mission_altitude} meters...")
            takeoff_client.wait_for_service(timeout_sec=2.0)
            takeoff_client.call(CommandTOL.Request(altitude=self.mission_altitude))
            
            response.success = True
            response.message = "Mission sequence initiated for Drone 1."
        except Exception as e:
            response.success = False
            response.message = f"Failed to execute mission sequence: {e}"
            self.get_logger().error(response.message)
            
        return response

    def swarm_land_callback(self, request, response):
        """Commands all active drones to land."""
        self.get_logger().info(f"Received LAND command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            land_client = self.create_client(CommandTOL, f'/drone{drone_id}/mavros/cmd/land')
            if land_client.wait_for_service(timeout_sec=1.0):
                land_client.call_async(CommandTOL.Request())
        response.success = True
        response.message = "Land command sent."
        return response

    def swarm_rtl_callback(self, request, response):
        """Commands all active drones to Return to Launch."""
        self.get_logger().info(f"Received RTL command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            set_mode_client = self.create_client(SetMode, f'/drone{drone_id}/mavros/set_mode')
            if set_mode_client.wait_for_service(timeout_sec=1.0):
                mode_req = SetMode.Request(custom_mode="AUTO.RTL")
                set_mode_client.call_async(mode_req)
        response.success = True
        response.message = "RTL command sent to all active drones."
        return response

def main(args=None):
    rclpy.init(args=args)
    node = SwarmCoordinatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
