#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from mavros_msgs.msg import State
import re

"""Scans for new drone connections periodically"""

# --- Configuration ---
MAX_DRONES = 10  # The maximum number of drones the GCS will look for.
TOPIC_SCAN_INTERVAL = 5.0  # seconds

class DroneState:
    """A simple class to hold the state of a single drone."""
    def __init__(self, system_id):
        self.system_id = system_id
        self.flight_mode = "Unknown"
        self.is_armed = False
        self.is_connected = False

    def __str__(self):
        return f"Drone {self.system_id}: Mode='{self.flight_mode}', Armed={self.is_armed}, Connected={self.is_connected}"

class FleetManagerNode(Node):
    """
    The main backend node for the GCS. It discovers drones dynamically by scanning
    for MAVROS topics and subscribes to their state to monitor the fleet.
    """
    def __init__(self):
        super().__init__('fleet_manager_node')
        self.get_logger().info("--- Aether GCS Fleet Manager Starting ---")
        
        # A dictionary to store the state of each drone, keyed by system ID
        self.fleet_state = {}
        
        # A set to keep track of which drone IDs we have already created subscribers for
        self.subscribed_drones = set()

        # A timer to periodically scan for new drones
        self.discovery_timer = self.create_timer(
            TOPIC_SCAN_INTERVAL, 
            self.discover_drones
        )
        
        self.get_logger().info("Node initialized. Starting drone discovery...")

    def discover_drones(self):
        """
        Scans all available topics and creates subscribers for any new drones found.
        """
        self.get_logger().debug("Scanning for new drones...")
        
        # Get a list of all topic names in the ROS 2 graph
        topic_names_and_types = self.get_topic_names_and_types()
        
        # Use a regular expression to find MAVROS state topics
        # It looks for topics like '/mavros_1/state', '/mavros_2/state', etc.
        state_topic_pattern = re.compile(r'/mavros_(\d+)/state')

        for topic_name, _ in topic_names_and_types:
            match = state_topic_pattern.match(topic_name)
            if match:
                # Extract the drone's system ID from the topic name
                drone_id = int(match.group(1))
                
                # If we haven't already subscribed to this drone, create a new subscription
                if drone_id not in self.subscribed_drones:
                    self.get_logger().info(f"Discovered new drone: ID {drone_id}")
                    self.create_drone_subscriber(drone_id)
                    self.subscribed_drones.add(drone_id)

    def create_drone_subscriber(self, drone_id):
        """
        Creates the necessary state subscriber for a newly discovered drone.
        """
        # Initialize the state for the new drone
        if drone_id not in self.fleet_state:
            self.fleet_state[drone_id] = DroneState(drone_id)

        topic_name = f'/mavros_{drone_id}/state'
        
        # The lambda function is a neat way to pass the drone_id to the callback
        self.create_subscription(
            State,
            topic_name,
            lambda msg, id=drone_id: self.state_callback(msg, id),
            10
        )
        self.get_logger().info(f"Created state subscriber for Drone {drone_id} on topic {topic_name}")

    def state_callback(self, msg, drone_id):
        """
        This function is called every time a new State message is received for a drone.
        It updates the internal state for that drone.
        """
        if drone_id in self.fleet_state:
            drone = self.fleet_state[drone_id]
            
            # Check if there's a change in state to avoid spamming the log
            if (drone.flight_mode != msg.mode or 
                drone.is_armed != msg.armed or 
                drone.is_connected != msg.connected):
                
                drone.flight_mode = msg.mode
                drone.is_armed = msg.armed
                drone.is_connected = msg.connected
                
                # In a real GCS, you would emit this updated state to the UI.
                # For now, we just log it.
                self.get_logger().info(f"State Update -> {drone}")
        else:
            self.get_logger().warn(f"Received state for unknown drone ID: {drone_id}")


def main(args=None):
    rclpy.init(args=args)
    fleet_manager_node = FleetManagerNode()
    rclpy.spin(fleet_manager_node)
    fleet_manager_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
