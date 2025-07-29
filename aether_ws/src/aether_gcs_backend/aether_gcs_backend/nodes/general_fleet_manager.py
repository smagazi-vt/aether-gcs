#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from mavros_msgs.msg import State
import re
import yaml

# --- Configuration ---
TOPIC_SCAN_INTERVAL = 5.0  # seconds

class StandardizedDroneState:
    """A class to hold state in a standardized format, independent of firmware."""
    def __init__(self, system_id, firmware_type="Unknown"):
        self.system_id = system_id
        self.firmware_type = firmware_type
        self.flight_mode = "UNKNOWN"
        self.is_armed = False
        self.is_connected = False

    def __str__(self):
        return (f"Drone {self.system_id} ({self.firmware_type}): "
                f"Mode='{self.flight_mode}', Armed={self.is_armed}, Connected={self.is_connected}")

class FleetManagerNode(Node):
    """
    The main backend node for the GCS. It discovers drones dynamically over the network
    and uses configuration files to support multiple firmware types.
    THIS NODE RUNS ON THE GCS COMPUTER.
    """
    def __init__(self):
        super().__init__('fleet_manager_node')
        self.get_logger().info("--- Aether GCS Fleet Manager Starting (Distributed Mode) ---")
        
        # Declare and get the path to the drone profiles YAML file from the launch file
        self.declare_parameter('drone_profiles_path', '')
        profiles_path = self.get_parameter('drone_profiles_path').get_parameter_value().string_value
        if not profiles_path:
            self.get_logger().fatal("'drone_profiles_path' parameter not set! Shutting down.")
            # FUTURE IMPROVEMENT: A MORE GRACEFUL SHUTDOWN IS NEEDED.
            self.destroy_node()
            return
            
        # Load the drone profiles from the YAML file
        try:
            with open(profiles_path, 'r') as f:
                self.drone_profiles = yaml.safe_load(f)['drone_profiles']
            self.get_logger().info(f"Successfully loaded {len(self.drone_profiles)} drone profiles.")
        except Exception as e:
            self.get_logger().fatal(f"Failed to load drone profiles from {profiles_path}. Error: {e}")
            self.destroy_node()
            return

        self.fleet_state = {}
        self.subscribed_drones = set()
        # FUTURE IMPROVEMENT: A ROBUST GCS WOULD MANAGE THE LIFECYCLE OF SUBSCRIBERS,
        # REMOVING THEM IF A DRONE DISCONNECTS FOR A LONG TIME.
        self.active_subscriptions = {}

        self.discovery_timer = self.create_timer(TOPIC_SCAN_INTERVAL, self.discover_drones)
        self.get_logger().info("Node initialized. Starting drone discovery over the network...")

    def discover_drones(self):
        """
        Scans all available topics on the network and creates subscribers for any new drones found.
        """
        self.get_logger().debug("Scanning for new drones...")
        
        topic_names_and_types = self.get_topic_names_and_types()
        
        # This regex pattern is looking for topics like '/drone1/mavros/state', '/drone2/mavros/state' etc.
        # which are broadcast by each drone's companion computer over the network.
        # NOTE: This assumes the onboard launch file starts mavros in a namespace.
        state_topic_pattern = re.compile(r'/drone(\d+)/mavros/state')

        for topic_name, _ in topic_names_and_types:
            match = state_topic_pattern.match(topic_name)
            if match:
                drone_id = int(match.group(1))
                if drone_id not in self.subscribed_drones:
                    self.get_logger().info(f"Discovered new drone over network: ID {drone_id}")
                    # FUTURE IMPROVEMENT: A PRODUCTION GCS WOULD HAVE A MORE ROBUST IDENTIFICATION
                    # MECHANISM TO DETERMINE THE DRONE'S FIRMWARE TYPE (E.G., VIA A MAVLINK PARAMETER).
                    # For now, we'll default to the first profile in the config file (e.g., 'px4').
                    default_firmware_type = list(self.drone_profiles.keys())[0]
                    self.setup_drone_from_profile(drone_id, default_firmware_type)
                    self.subscribed_drones.add(drone_id)

    def setup_drone_from_profile(self, drone_id, firmware_type):
        """Uses the loaded profile to create the correct subscribers for a drone."""
        if firmware_type not in self.drone_profiles:
            self.get_logger().error(f"No profile found for firmware type '{firmware_type}'. Cannot setup Drone {drone_id}.")
            return

        profile = self.drone_profiles[firmware_type]
        self.fleet_state[drone_id] = StandardizedDroneState(drone_id, firmware_type)

        # Create subscriber using the topic name from the profile
        # The topic name is now namespaced for the specific drone.
        state_topic = profile['topics']['state'].format(id=drone_id)
        
        sub = self.create_subscription(
            State,
            state_topic,
            lambda msg, id=drone_id, p=profile: self.state_callback(msg, id, p),
            10
        )
        self.active_subscriptions[drone_id] = sub # Store the subscription object
        self.get_logger().info(f"Created state subscriber for Drone {drone_id} on topic {state_topic}")
        # FUTURE IMPROVEMENT: HERE YOU WOULD CREATE SUBSCRIBERS FOR OTHER TELEMETRY
        # (LIKE POSITION, BATTERY, ETC.) IN THE SAME WAY.

    def state_callback(self, msg, drone_id, profile):
        """Updates the drone's state, standardizing the flight mode."""
        if drone_id in self.fleet_state:
            drone = self.fleet_state[drone_id]
            
            # Standardize the flight mode using the profile's mapping
            standard_mode = profile['mode_mapping'].get(msg.mode, "UNKNOWN")

            if (drone.flight_mode != standard_mode or 
                drone.is_armed != msg.armed or 
                drone.is_connected != msg.connected):
                
                drone.flight_mode = standard_mode
                drone.is_armed = msg.armed
                drone.is_connected = msg.connected
                
                self.get_logger().info(f"State Update -> {drone}")
                # FUTURE IMPROVEMENT: INSTEAD OF LOGGING, THIS IS WHERE YOU WOULD PUBLISH
                # THE STANDARDIZED STATE O