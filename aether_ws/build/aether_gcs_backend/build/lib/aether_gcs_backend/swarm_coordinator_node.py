#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from aether_interfaces.msg import FleetState
from mavros_msgs.srv import CommandBool, SetMode, CommandTOL
import time

# FUTURE IMPROVEMENT: INSTEAD OF A SIMPLE STRING, A DEDICATED SWARMCOMMAND
# SERVICE DEFINITION SHOULD BE CREATED IN AETHER_INTERFACES FOR BETTER TYPE
# SAFETY AND MORE COMPLEX COMMANDS (E.G., WITH ALTITUDE ARGUMENTS).
from std_srvs.srv import Trigger # Using a simple standard service for the MVP

class SwarmCoordinatorNode(Node):
    """
    Coordinates high-level commands for the entire drone fleet.
    """
    def __init__(self):
        # --- THIS IS THE CRITICAL FIX ---
        # The super().__init__() call MUST be the first line to initialize the Node.
        super().__init__('swarm_coordinator_node')
        
        self.get_logger().info("--- Aether GCS Swarm Coordinator Starting ---")

        self.active_drones = []
        self.service_clients = {}

        # Subscribe to the fleet state to know which drones are active
        self.fleet_state_sub = self.create_subscription(
            FleetState,
            '/aether/fleet_state',
            self.fleet_state_callback,
            10
        )

        # --- Services for the UI to call ---
        self.arm_service = self.create_service(Trigger, '/aether/swarm_arm', self.swarm_arm_callback)
        self.disarm_service = self.create_service(Trigger, '/aether/swarm_disarm', self.swarm_disarm_callback)
        self.takeoff_service = self.create_service(Trigger, '/aether/swarm_takeoff', self.swarm_takeoff_callback)
        self.land_service = self.create_service(Trigger, '/aether/swarm_land', self.swarm_land_callback)

        self.get_logger().info("Swarm Coordinator is ready to command the fleet.")

    def fleet_state_callback(self, msg):
        """Updates the list of active drones."""
        self.active_drones = [drone.system_id for drone in msg.drones if drone.is_connected]
        self.get_logger().debug(f"Active drones updated: {self.active_drones}")

    def get_client(self, drone_id, service_type, service_name_template):
        """Dynamically creates and returns a service client."""
        key = (drone_id, service_type)
        if key not in self.service_clients:
            service_name = service_name_template.format(id=drone_id)
            self.service_clients[key] = self.create_client(service_type, service_name)
            self.get_logger().info(f"Created client for Drone {drone_id}: {service_name}")
        return self.service_clients[key]

    def swarm_arm_callback(self, request, response):
        """Arms all active drones."""
        self.get_logger().info(f"Received ARM command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            # First, set mode to OFFBOARD (or GUIDED for ArduPilot)
            set_mode_client = self.get_client(drone_id, SetMode, '/drone{id}/mavros/set_mode')
            if set_mode_client.wait_for_service(timeout_sec=1.0):
                mode_req = SetMode.Request()
                mode_req.custom_mode = "OFFBOARD" # PX4 specific
                set_mode_client.call_async(mode_req)
                time.sleep(0.1) # Small delay between commands

            # Then, send the arm command
            arm_client = self.get_client(drone_id, CommandBool, '/drone{id}/mavros/cmd/arming')
            if arm_client.wait_for_service(timeout_sec=1.0):
                arm_req = CommandBool.Request()
                arm_req.value = True
                arm_client.call_async(arm_req)
            else:
                self.get_logger().warn(f"Arming service for Drone {drone_id} not available.")
        
        response.success = True
        response.message = "Arm command sent to all active drones."
        return response

    def swarm_disarm_callback(self, request, response):
        """Disarms all active drones."""
        self.get_logger().info(f"Received DISARM command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            arm_client = self.get_client(drone_id, CommandBool, '/drone{id}/mavros/cmd/arming')
            if arm_client.wait_for_service(timeout_sec=1.0):
                req = CommandBool.Request()
                req.value = False
                arm_client.call_async(req)
        response.success = True
        response.message = "Disarm command sent."
        return response

    def swarm_takeoff_callback(self, request, response):
        """Commands all active drones to take off."""
        self.get_logger().info(f"Received TAKEOFF command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            takeoff_client = self.get_client(drone_id, CommandTOL, '/drone{id}/mavros/cmd/takeoff')
            if takeoff_client.wait_for_service(timeout_sec=1.0):
                req = CommandTOL.Request()
                req.altitude = 10.0  # FUTURE IMPROVEMENT: ALTITUDE SHOULD BE A PARAMETER.
                takeoff_client.call_async(req)
        response.success = True
        response.message = "Takeoff command sent."
        return response

    def swarm_land_callback(self, request, response):
        """Commands all active drones to land."""
        self.get_logger().info(f"Received LAND command for swarm: {self.active_drones}")
        for drone_id in self.active_drones:
            land_client = self.get_client(drone_id, CommandTOL, '/drone{id}/mavros/cmd/land')
            if land_client.wait_for_service(timeout_sec=1.0):
                land_client.call_async(CommandTOL.Request())
        response.success = True
        response.message = "Land command sent."
        return response


def main(args=None):
    rclpy.init(args=args)
    node = SwarmCoordinatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
