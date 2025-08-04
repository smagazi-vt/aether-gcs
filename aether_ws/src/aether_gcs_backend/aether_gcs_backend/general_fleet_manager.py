#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from mavros_msgs.msg import State
from mavros_msgs.srv import ParamGet
import re
import yaml
from std_msgs.msg import Header
from aether_interfaces.msg import DroneState, FleetState # IMPORT OUR NEW MESSAGES

# --- Configuration ---
TOPIC_SCAN_INTERVAL = 5.0  # seconds
FLEET_STATE_PUBLISH_INTERVAL = 1.0 # seconds

class StandardizedDroneState:
    """A class to hold state in a standardized format, independent of firmware."""
    def __init__(self, system_id, firmware_type="Unknown"):
        self.system_id = system_id
        self.firmware_type = firmware_type
        self.flight_mode = "UNKNOWN"
        self.is_armed = False
        self.is_connected = False

    def to_msg(self):
        """Converts the class instance to a ROS 2 message."""
        msg = DroneState()
        msg.system_id = self.system_id
        msg.firmware_type = self.firmware_type
        msg.flight_mode = self.flight_mode
        msg.is_armed = self.is_armed
        msg.is_connected = self.is_connected
        return msg

    def __str__(self):
        return (f"Drone {self.system_id} ({self.firmware_type}): "
                f"Mode='{self.flight_mode}', Armed={self.is_armed}, Connected={self.is_connected}")

class FleetManagerNode(Node):
    """
    The main backend node for the GCS. It discovers drones dynamically over the network,
    identifies their firmware, and publishes a standardized fleet state.
    THIS NODE RUNS ON THE GCS COMPUTER.
    """
    def __init__(self):
        super().__init__('fleet_manager_node')
        self.get_logger().info("--- Aether GCS Fleet Manager Starting (Distributed & Robust Mode) ---")
        
        self.declare_parameter('drone_profiles_path', '')
        profiles_path = self.get_parameter('drone_profiles_path').get_parameter_value().string_value
        if not profiles_path:
            self.get_logger().fatal("'drone_profiles_path' parameter not set! Shutting down.")
            self.destroy_node()
            return
            
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
        self.active_subscriptions = {}

        # --- NEW: Create the publisher for the fleet state ---
        self.fleet_state_publisher = self.create_publisher(FleetState, '/aether/fleet_state', 10)

        self.discovery_timer = self.create_timer(TOPIC_SCAN_INTERVAL, self.discover_drones)
        # --- NEW: Create a timer to publish the fleet state periodically ---
        self.publish_timer = self.create_timer(FLEET_STATE_PUBLISH_INTERVAL, self.publish_fleet_state)
        
        self.get_logger().info("Node initialized. Starting drone discovery and state publishing...")

    def discover_drones(self):
        """Scans all available topics on the network for new drones."""
        self.get_logger().debug("Scanning for new drones...")
        topic_names_and_types = self.get_topic_names_and_types()
        state_topic_pattern = re.compile(r'/drone(\d+)/mavros/state')

        for topic_name, _ in topic_names_and_types:
            match = state_topic_pattern.match(topic_name)
            if match:
                drone_id = int(match.group(1))
                if drone_id not in self.subscribed_drones:
                    self.get_logger().info(f"Discovered potential drone: ID {drone_id}. Identifying firmware...")
                    self.identify_and_subscribe(drone_id)
                    self.subscribed_drones.add(drone_id)

    def identify_and_subscribe(self, drone_id):
        """Identifies the drone's firmware type via a MAVLink parameter and then subscribes."""
        service_name = f'/drone{drone_id}/mavros/param/get'
        client = self.create_client(ParamGet, service_name)
        self.param_clients[drone_id] = client

        if not client.wait_for_service(timeout_sec=3.0):
            self.get_logger().error(f"Parameter service for Drone {drone_id} not available. Cannot identify firmware.")
            # FUTURE IMPROVEMENT: SHOULD IMPLEMENT A RETRY MECHANISM.
            return

        request = ParamGet.Request()
        request.param_id = "MAV_AUTOPILOT"
        future = client.call_async(request)
        future.add_done_callback(lambda fut, id=drone_id: self.on_identify_response(fut, id))

    def on_identify_response(self, future, drone_id):
        """Callback for when the firmware identification is complete."""
        firmware_type = "unknown"
        try:
            response = future.result()
            if response.success:
                autopilot_id = response.value.integer
                if autopilot_id == 3:
                    firmware_type = "ardupilot"
                elif autopilot_id == 12:
                    firmware_type = "px4"
                
                self.get_logger().info(f"Successfully identified Drone {drone_id} as type '{firmware_type}'.")
            else:
                self.get_logger().warn(f"Failed to get MAV_AUTOPILOT param for Drone {drone_id}. Defaulting to px4.")
                firmware_type = "px4"

        except Exception as e:
            self.get_logger().error(f"Exception while identifying Drone {drone_id}: {e}")
            firmware_type = "px4" # Default on error
        
        if firmware_type in self.drone_profiles:
            self.setup_drone_from_profile(drone_id, firmware_type)
        else:
            self.get_logger().error(f"No profile found for firmware type '{firmware_type}'. Cannot setup Drone {drone_id}.")

    def setup_drone_from_profile(self, drone_id, firmware_type):
        """Uses the loaded profile to create the correct subscribers for a drone."""
        profile = self.drone_profiles[firmware_type]
        self.fleet_state[drone_id] = StandardizedDroneState(drone_id, firmware_type)
        state_topic = profile['topics']['state'].format(id=drone_id)
        sub = self.create_subscription(
            State, state_topic,
            lambda msg, id=drone_id, p=profile: self.state_callback(msg, id, p), 10)
        self.active_subscriptions[drone_id] = sub
        self.get_logger().info(f"Created state subscriber for Drone {drone_id} on topic {state_topic}")

    def state_callback(self, msg, drone_id, profile):
        """Updates the drone's internal state dictionary."""
        if drone_id in self.fleet_state:
            drone = self.fleet_state[drone_id]
            drone.flight_mode = profile['mode_mapping'].get(msg.mode, "UNKNOWN")
            drone.is_armed = msg.armed
            drone.is_connected = msg.connected
    
    def publish_fleet_state(self):
        """
        Gathers all individual drone states from the internal dictionary,
        assembles them into a single FleetState message, and publishes it.
        """
        fleet_msg = FleetState()
        fleet_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id="gcs")
        
        # Convert all tracked drone states to messages and add to the list
        for drone_state_obj in self.fleet_state.values():
            fleet_msg.drones.append(drone_state_obj.to_msg())
            
        self.fleet_state_publisher.publish(fleet_msg)
        self.get_logger().debug(f"Published fleet state with {len(fleet_msg.drones)} drones.")


def main(args=None):
    rclpy.init(args=args)
    node = FleetManagerNode()
    if node.get_name() != 'fleet_manager_node': return
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
