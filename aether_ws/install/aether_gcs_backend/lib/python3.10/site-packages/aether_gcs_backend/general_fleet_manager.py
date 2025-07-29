# fleet_manager_node.py
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from mavros_msgs.msg import State, ParamValue
from mavros_msgs.srv import ParamGet
import re
import yaml

# --- Configuration ---
TOPIC_SCAN_INTERVAL = 5.0  # seconds

class StandardizedDroneState:
    """A class to hold state in a standardized format, independent of firmware."""
    def __init__(self, system_id, firmware_type="Unknown"):
        self.system_id = system_id
        self.firmware_type = firmware_type
        self.flight_mode = "UNKNOWN"  # Standardized mode
        self.is_armed = False
        self.is_connected = False

    def __str__(self):
        return (f"Drone {self.system_id} ({self.firmware_type}): "
                f"Mode='{self.flight_mode}', Armed={self.is_armed}, Connected={self.is_connected}")

class FleetManagerNode(Node):
    """
    An advanced Fleet Manager that uses configuration files to support multiple
    drone firmware types (e.g., PX4, ArduPilot) simultaneously.
    """
    def __init__(self):
        super().__init__('fleet_manager_node')
        self.get_logger().info("--- Aether GCS Configurable Fleet Manager Starting ---")
        
        # Declare and get the path to the drone profiles YAML file
        self.declare_parameter('drone_profiles_path', '')
        profiles_path = self.get_parameter('drone_profiles_path').get_parameter_value().string_value
        if not profiles_path:
            self.get_logger().fatal("'drone_profiles_path' parameter not set! Shutting down.")
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
        self.param_clients = {}

        self.discovery_timer = self.create_timer(TOPIC_SCAN_INTERVAL, self.discover_drones)
        self.get_logger().info("Node initialized. Starting drone discovery...")

    def discover_drones(self):
        """Scans for MAVROS topics to discover new drones."""
        topic_names_and_types = self.get_topic_names_and_types()
        state_topic_pattern = re.compile(r'/mavros_(\d+)/state')

        for topic_name, _ in topic_names_and_types:
            match = state_topic_pattern.match(topic_name)
            if match:
                drone_id = int(match.group(1))
                if drone_id not in self.subscribed_drones:
                    self.get_logger().info(f"Discovered potential drone: ID {drone_id}. Identifying firmware...")
                    self.identify_and_subscribe(drone_id)
                    self.subscribed_drones.add(drone_id)

    def identify_and_subscribe(self, drone_id):
        """Identifies the drone's firmware type and creates subscribers based on its profile."""
        # For this example, we'll use a MAVLink parameter to identify the firmware.
        # AUTOPILOT_VERSION_TYPE: 3 = ArduPilot, 8 = PX4
        param_id = "AUTOPILOT_VER" # A parameter that can hint at the firmware type
        client = self.create_client(ParamGet, f'/mavros_{drone_id}/param/get')
        self.param_clients[drone_id] = client

        if not client.wait_for_service(timeout_sec=3.0):
            self.get_logger().error(f"Parameter service for Drone {drone_id} not available. Cannot identify firmware.")
            return

        request = ParamGet.Request()
        request.param_id = param_id
        
        future = client.call_async(request)
        future.add_done_callback(lambda fut, id=drone_id: self.on_identify_response(fut, id))

    def on_identify_response(self, future, drone_id):
        """Callback for when the firmware identification is complete."""
        try:
            response = future.result()
            firmware_type = "Unknown"
            if response.success:
                # This is a simplified check. A real implementation might be more robust.
                # PX4 uses AUTOPILOT_VERSION_TYPE = 8
                # ArduPilot uses MAV_AUTOPILOT = 3
                # This requires more logic, for now we'll assume a simple mapping.
                # Let's pretend we have a way to map this to our profile names.
                # For this example, we'll just default to px4.
                firmware_type = "px4" # Placeholder
                self.get_logger().info(f"Identified Drone {drone_id} as type '{firmware_type}' (placeholder).")
            else:
                self.get_logger().warn(f"Failed to get firmware type for Drone {drone_id}. Defaulting to 'px4'.")
                firmware_type = "px4"

            self.setup_drone_from_profile(drone_id, firmware_type)

        except Exception as e:
            self.get_logger().error(f"Exception while identifying Drone {drone_id}: {e}")

    def setup_drone_from_profile(self, drone_id, firmware_type):
        """Uses the loaded profile to create the correct subscribers for a drone."""
        if firmware_type not in self.drone_profiles:
            self.get_logger().error(f"No profile found for firmware type '{firmware_type}'. Cannot setup Drone {drone_id}.")
            return

        profile = self.drone_profiles[firmware_type]
        self.fleet_state[drone_id] = StandardizedDroneState(drone_id, firmware_type)

        # Create subscriber using the topic name from the profile
        state_topic = profile['topics']['state'].format(id=drone_id)
        self.create_subscription(
            State,
            state_topic,
            lambda msg, id=drone_id, p=profile: self.state_callback(msg, id, p),
            10
        )
        self.get_logger().info(f"Created state subscriber for Drone {drone_id} on topic {state_topic}")
        # Here you would create other subscribers (e.g., for position) in the same way.

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

def main(args=None):
    rclpy.init(args=args)
    fleet_manager_node = FleetManagerNode()
    if rclpy.ok():
        rclpy.spin(fleet_manager_node)
    fleet_manager_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()