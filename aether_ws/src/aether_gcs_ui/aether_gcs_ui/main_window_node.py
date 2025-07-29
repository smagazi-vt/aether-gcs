#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, 
                             QLabel, QTableWidget, QTableWidgetItem, QPushButton, 
                             QFileDialog, QHeaderView, QComboBox)
from PyQt6.QtCore import QTimer
from aether_interfaces.srv import UploadMission
from aether_interfaces.msg import FleetState # IMPORT THE NEW FLEET STATE MESSAGE

class GCSMainWindow(QMainWindow, Node):
    """
    The main graphical user interface for the Aether GCS.
    It subscribes to the centralized fleet state topic for all its data.
    """
    def __init__(self):
        super(GCSMainWindow, self).__init__()
        Node.__init__(self, 'aether_gcs_ui_node')

        self.setWindowTitle("Aether GCS")
        self.setGeometry(100, 100, 800, 600)

        # --- Data Storage ---
        self.fleet_state = {} # This will now be populated by one subscriber

        # --- UI Elements ---
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        self.title_label = QLabel("Aether Ground Control Station")
        font = self.title_label.font()
        font.setPointSize(20)
        self.title_label.setFont(font)
        self.layout.addWidget(self.title_label)

        self.fleet_table = QTableWidget()
        self.fleet_table.setColumnCount(4)
        self.fleet_table.setHorizontalHeaderLabels(["ID", "Firmware", "Flight Mode", "Armed"])
        self.fleet_table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.layout.addWidget(self.fleet_table)

        self.mission_label = QLabel("Mission Control")
        self.layout.addWidget(self.mission_label)
        
        self.drone_selector = QComboBox()
        self.layout.addWidget(self.drone_selector)

        self.upload_button = QPushButton("Upload Mission Plan...")
        self.upload_button.clicked.connect(self.on_upload_mission)
        self.layout.addWidget(self.upload_button)

        # --- ROS 2 Integration ---
        self.upload_mission_client = self.create_client(UploadMission, '/aether/upload_mission')

        # Create a single subscriber to the fleet state topic
        self.fleet_state_subscriber = self.create_subscription(
            FleetState,
            '/aether/fleet_state',
            self.fleet_state_callback,
            10
        )

        self.ros_timer = QTimer(self)
        self.ros_timer.timeout.connect(self.spin_ros)
        self.ros_timer.start(100)

        self.get_logger().info("GCS UI Node has started and is listening for fleet state.")

    def spin_ros(self):
        """Processes one ROS 2 event loop iteration."""
        rclpy.spin_once(self, timeout_sec=0)

    def fleet_state_callback(self, msg):
        """
        Receives the state of the entire fleet and updates the UI.
        This is much simpler than the old discovery logic.
        """
        new_state = {}
        for drone_msg in msg.drones:
            new_state[drone_msg.system_id] = {
                "id": drone_msg.system_id,
                "firmware": drone_msg.firmware_type,
                "mode": drone_msg.flight_mode,
                "armed": drone_msg.is_armed
            }
        self.fleet_state = new_state
        self.update_fleet_display()

    def update_fleet_display(self):
        """Redraws the fleet status table and drone selector with the latest data."""
        self.fleet_table.setRowCount(len(self.fleet_state))
        self.drone_selector.clear()

        sorted_drones = sorted(self.fleet_state.values(), key=lambda d: d['id'])

        for row, drone in enumerate(sorted_drones):
            self.fleet_table.setItem(row, 0, QTableWidgetItem(str(drone['id'])))
            self.fleet_table.setItem(row, 1, QTableWidgetItem(drone['firmware']))
            self.fleet_table.setItem(row, 2, QTableWidgetItem(drone['mode']))
            self.fleet_table.setItem(row, 3, QTableWidgetItem("Yes" if drone['armed'] else "No"))
            self.drone_selector.addItem(f"Drone {drone['id']}", userData=drone['id'])

    def on_upload_mission(self):
        """Opens a file dialog and calls the mission upload service."""
        selected_drone_id = self.drone_selector.currentData()
        if selected_drone_id is None:
            self.get_logger().warn("No drone selected for mission upload.")
            return

        file_path, _ = QFileDialog.getOpenFileName(self, "Open Mission Plan", "", "Mission Plan Files (*.plan)")

        if file_path:
            if not self.upload_mission_client.wait_for_service(timeout_sec=1.0):
                self.get_logger().error("Mission upload service not available.")
                return

            request = UploadMission.Request()
            request.target_system_id = selected_drone_id
            request.file_path = file_path
            
            self.get_logger().info(f"UI sending request to upload {file_path} to Drone {selected_drone_id}")
            future = self.upload_mission_client.call_async(request)
            future.add_done_callback(self.on_upload_response)

    def on_upload_response(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Mission upload response: Success={response.success}, Message='{response.message}'")
            # FUTURE IMPROVEMENT: SHOW A POP-UP MESSAGE BOX TO THE USER.
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    app = QApplication(sys.argv)
    gcs_window = GCSMainWindow()
    gcs_window.show()
    sys.exit(app.exec())

if __name__ == '__main__':
    main()

