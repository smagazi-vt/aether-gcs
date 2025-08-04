#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import re
from mavros_msgs.msg import StatusText
from mavros_msgs.srv import CommandLong
from aether_interfaces.srv import StartCalibration
from aether_interfaces.msg import CalibrationStatus

class CalibrationManagerNode(Node):
    """
    Manages the state of a sensor calibration process for a single drone at a time.
    It acts as a bridge between a simple UI request and the complex MAVLink
    calibration state machine.
    """
    def __init__(self):
        super().__init__('calibration_manager_node')
        self.get_logger().info("--- Aether GCS Calibration Manager Starting ---")

        # State machine variables
        self.calibrating_drone_id = None
        self.is_calibrating = False

        # Dictionaries to hold dynamically created clients and subscribers
        self.command_clients = {}
        self.statustext_subs = {}

        # The service the UI will call to start a calibration
        self.start_calibration_service = self.create_service(
            StartCalibration,
            '/aether/start_calibration',
            self.start_calibration_callback
        )

        # The topic the UI will listen to for live updates
        self.status_publisher = self.create_publisher(
            CalibrationStatus,
            '/aether/calibration_status',
            10
        )
        self.get_logger().info("Calibration service and status publisher are ready.")

    def start_calibration_callback(self, request, response):
        """Handles a request from the UI to start a calibration."""
        if self.is_calibrating:
            response.success = False
            response.message = f"Cannot start calibration. GCS is already busy calibrating Drone {self.calibrating_drone_id}."
            self.get_logger().warn(response.message)
            return response

        drone_id = request.target_system_id
        sensor_type = request.sensor_type.lower()
        self.get_logger().info(f"Received request to start '{sensor_type}' calibration for Drone {drone_id}.")

        # Map sensor type string to MAVLink command parameters
        # MAV_CMD_PREFLIGHT_CALIBRATION params: gyro, mag, baro, rc, accel, esc
        params = {'gyro': 1.0, 'mag': 2.0, 'baro': 3.0, 'accel': 5.0}
        if sensor_type not in params:
            response.success = False
            response.message = f"Unknown sensor type '{sensor_type}'. Valid types are gyro, mag, accel."
            self.get_logger().error(response.message)
            return response
        
        param_index = params[sensor_type]

        # Set state machine
        self.is_calibrating = True
        self.calibrating_drone_id = drone_id

        # Dynamically create subscriber and client if they don't exist
        self.setup_drone_comms(drone_id)

        # Send the MAVLink command to start the calibration
        self.send_start_command(drone_id, param_index)

        response.success = True
        response.message = "Calibration start command sent."
        return response

    def setup_drone_comms(self, drone_id):
        """Creates the necessary client and subscriber for a drone if not already present."""
        if drone_id not in self.command_clients:
            service_name = f'/drone{drone_id}/mavros/cmd/command'
            self.command_clients[drone_id] = self.create_client(CommandLong, service_name)
            self.get_logger().info(f"Created command client for Drone {drone_id}")

        if drone_id not in self.statustext_subs:
            topic_name = f'/drone{drone_id}/mavros/statustext/recv'
            self.statustext_subs[drone_id] = self.create_subscription(
                StatusText,
                topic_name,
                self.statustext_callback,
                10
            )
            self.get_logger().info(f"Created statustext subscriber for Drone {drone_id}")

    def send_start_command(self, drone_id, param_index):
        """Sends the MAV_CMD_PREFLIGHT_CALIBRATION command to the drone."""
        client = self.command_clients[drone_id]
        if not client.wait_for_service(timeout_sec=3.0):
            self.get_logger().error(f"Command service for Drone {drone_id} not available.")
            self.reset_state()
            return

        request = CommandLong.Request()
        request.command = 241  # MAV_CMD_PREFLIGHT_CALIBRATION
        
        # Set the correct parameter to 1.0 to start the specific calibration
        # FUTURE IMPROVEMENT: THIS IS A RUDIMENTARY WAY TO SET PARAMS. A MORE
        # ROBUST IMPLEMENTATION WOULD HANDLE THIS MORE ELEGANTLY.
        if param_index == 1.0: request.param1 = 1.0
        elif param_index == 2.0: request.param2 = 1.0
        elif param_index == 3.0: request.param3 = 1.0
        elif param_index == 5.0: request.param5 = 1.0
        
        self.get_logger().info(f"Sending start calibration command to Drone {drone_id}...")
        client.call_async(request)

    def statustext_callback(self, msg):
        """Listens for feedback from the drone and publishes standardized status."""
        # Ignore messages that are not from the drone we are currently calibrating
        if not self.is_calibrating:
            return

        text = msg.text.lower()
        
        # PX4 calibration messages are prefixed with "[cal]"
        if not text.startswith('[cal]'):
            return

        self.get_logger().debug(f"Received calibration text: '{msg.text}'")
        
        status_msg = CalibrationStatus()
        status_msg.system_id = self.calibrating_drone_id
        status_msg.is_complete = False
        status_msg.success = False

        # Use regular expressions to parse progress and completion messages
        progress_match = re.search(r'progress <(\d+)>', text)
        
        if "calibration successful" in text or "calibration done" in text:
            status_msg.is_complete = True
            status_msg.success = True
            status_msg.instruction_text = "Calibration Successful!"
            status_msg.progress_percentage = 100.0
            self.reset_state()
        elif "calibration failed" in text or "calibration timed out" in text:
            status_msg.is_complete = True
            status_msg.success = False
            status_msg.instruction_text = "Calibration Failed!"
            self.reset_state()
        elif progress_match:
            status_msg.progress_percentage = float(progress_match.group(1))
            # Extract the instruction text before the progress part
            status_msg.instruction_text = msg.text.split("progress")[0].strip()
        else:
            # If it's just an instruction without progress
            status_msg.instruction_text = msg.text
            status_msg.progress_percentage = -1.0 # Indicate no progress update

        self.status_publisher.publish(status_msg)

    def reset_state(self):
        """Resets the state machine after a calibration is finished or failed."""
        self.get_logger().info(f"Calibration process for Drone {self.calibrating_drone_id} finished. Resetting state.")
        self.is_calibrating = False
        self.calibrating_drone_id = None

def main(args=None):
    rclpy.init(args=args)
    node = CalibrationManagerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
