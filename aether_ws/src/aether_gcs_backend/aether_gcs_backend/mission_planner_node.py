#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import json
from mavros_msgs.msg import Waypoint
from mavros_msgs.srv import WaypointPush
from aether_interfaces.srv import UploadMission # Import our new custom service

class MissionPlannerBackendNode(Node):
    """
    Provides a service to upload mission plans to drones.
    It parses QGC .plan files and uses MAVROS services to send the mission.
    """
    def __init__(self):
        super().__init__('mission_planner_backend_node')
        self.get_logger().info("--- Aether GCS Mission Planner Backend Starting ---")

        # Create the service server that the UI will call
        self.upload_service = self.create_service(
            UploadMission,
            '/aether/upload_mission',
            self.upload_mission_callback
        )
        
        # A dictionary to hold clients for each drone's mission push service
        # FUTURE IMPROVEMENT: A PRODUCTION GCS SHOULD MANAGE THE LIFECYCLE OF THESE CLIENTS,
        # INCLUDING CLEANING THEM UP IF A DRONE DISCONNECTS.
        self.mission_push_clients = {}

        self.get_logger().info("UploadMission service is ready.")

    def upload_mission_callback(self, request, response):
        """
        This function is called when the UI requests to upload a mission.
        """
        drone_id = request.target_system_id
        file_path = request.file_path
        
        self.get_logger().info(f"Received request to upload mission '{file_path}' to Drone {drone_id}")

        try:
            # FUTURE IMPROVEMENT: ADD A MISSION VALIDATION STEP HERE.
            # A REAL GCS SHOULD VALIDATE THE MISSION FOR SAFETY (E.G., CHECK FOR REASONABLE
            # ALTITUDES, COORDINATES WITHIN A GEOFENCE) BEFORE PARSING OR UPLOADING.

            # Step 1: Parse the mission plan file
            waypoints = self.parse_plan_file(file_path)
            if not waypoints:
                response.success = False
                response.message = "Failed to parse mission file or file is empty."
                self.get_logger().error(response.message)
                return response

            # Step 2: Get a client for the drone's mission push service
            if drone_id not in self.mission_push_clients:
                service_name = f'/mavros_{drone_id}/mission/push'
                self.mission_push_clients[drone_id] = self.create_client(WaypointPush, service_name)
            
            client = self.mission_push_clients[drone_id]

            if not client.wait_for_service(timeout_sec=3.0):
                response.success = False
                response.message = f"MAVROS mission push service for Drone {drone_id} not available."
                self.get_logger().error(response.message)
                return response

            # Step 3: Call the MAVROS service to upload the waypoints
            push_request = WaypointPush.Request()
            push_request.waypoints = waypoints
            
            future = client.call_async(push_request)
            
            # FUTURE IMPROVEMENT: THE HANDLING OF THE SERVICE CALL RESPONSE IS RUDIMENTARY.
            # A ROBUST GCS MUST HANDLE THE 'FUTURE' OBJECT ASYNCHRONOUSLY. IT SHOULD
            # WAIT FOR THE SERVICE CALL TO COMPLETE AND CHECK THE ACTUAL 'SUCCESS'
            # AND 'WP_TRANSFER_SENT' FIELDS IN THE RESPONSE FROM MAVROS TO CONFIRM
            # THAT THE MISSION WAS ACTUALLY ACCEPTED BY THE DRONE.
            self.get_logger().info(f"Sending {len(waypoints)} waypoints to Drone {drone_id}...")
            
            response.success = True
            response.message = f"Mission upload initiated for Drone {drone_id}."
            return response

        except Exception as e:
            response.success = False
            response.message = f"An unexpected error occurred: {e}"
            self.get_logger().error(response.message)
            # FUTURE IMPROVEMENT: ERRORS SHOULD BE PROPAGATED TO THE UI IN A
            # USER-FRIENDLY FORMAT, NOT JUST LOGGED TO THE CONSOLE.
            return response

    def parse_plan_file(self, file_path):
        """
        Parses a QGroundControl .plan file (which is JSON) and converts it
        into a list of mavros_msgs/msg/Waypoint objects.
        """
        waypoints = []
        try:
            with open(file_path, 'r') as f:
                plan_data = json.load(f)
            
            mission_items = plan_data.get('mission', {}).get('items', [])

            for item in mission_items:
                # FUTURE IMPROVEMENT: THIS PARSER IS RUDIMENTARY AND ONLY HANDLES A FEW COMMANDS.
                # A FULL GCS WOULD NEED TO SUPPORT A MUCH WIDER RANGE OF MAVLINK MISSION
                # COMMANDS (E.G., ROI, LOITER, JUMP) AND COMPLEX ITEMS LIKE SURVEYS.
                if item.get('type') == 'SimpleItem' and item.get('command') in [16, 22]: # 16=WAYPOINT, 22=TAKEOFF
                    wp = Waypoint()
                    
                    wp.frame = int(item.get('frame', 3)) # FRAME_GLOBAL_REL_ALT is common
                    wp.command = int(item.get('command', 16))
                    wp.is_current = False
                    wp.autocontinue = True
                    
                    params = item.get('params', [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
                    wp.param1 = float(params[0]) if params[0] is not None else 0.0
                    wp.param2 = float(params[1]) if params[1] is not None else 0.0
                    wp.param3 = float(params[2]) if params[2] is not None else 0.0
                    wp.param4 = float(params[3]) if params[3] is not None else 0.0
                    wp.x_lat = float(params[4]) if params[4] is not None else 0.0
                    wp.y_long = float(params[5]) if params[5] is not None else 0.0
                    wp.z_alt = float(params[6]) if params[6] is not None else 0.0
                    
                    waypoints.append(wp)
            
            self.get_logger().info(f"Successfully parsed {len(waypoints)} waypoints from {file_path}")
            return waypoints

        except FileNotFoundError:
            self.get_logger().error(f"Mission file not found at: {file_path}")
            return []
        except json.JSONDecodeError:
            self.get_logger().error(f"Error decoding JSON from mission file: {file_path}")
            return []
        except Exception as e:
            self.get_logger().error(f"Failed to parse plan file: {e}")
            return []


def main(args=None):
    rclpy.init(args=args)
    node = MissionPlannerBackendNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
