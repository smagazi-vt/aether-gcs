#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, 
                             QLabel, QTableWidget, QTableWidgetItem, QPushButton, 
                             QFileDialog, QHeaderView, QComboBox, QMessageBox)
from PyQt6.QtCore import QTimer
from PyQt6.QtGui import QAction

from aether_interfaces.srv import UploadMission, StartCalibration
from aether_interfaces.msg import FleetState
from .calibration_wizard import CalibrationWizard # IMPORT THE WIZARD UI

class GCSMainWindow(QMainWindow, Node):
    """
    The main graphical user interface for the Aether GCS.
    It subscribes to the centralized fleet state topic for all its data.
    """
    def __init__(self):
        # The correct way to initialize multiple inheritance with required args:
        # Call super() with arguments that satisfy ALL base classes' __init__ methods
        # In this case, Node needs 'node_name'. QMainWindow does not.
        # So, we pass 'node_name' when calling super() in a way that Node.__init__
        # will receive it.
        #
        # Python's super() mechanism, when used correctly, will ensure that
        # each __init__ method in the MRO is called exactly once.
        
        # Pass the node_name argument to the Node constructor through super()
        # The MRO will determine which __init__ gets called first.
        # For GCSMainWindow(QMainWindow, Node), the MRO is:
        # GCSMainWindow -> QMainWindow -> Node -> object.
        #
        # The key is that Node's __init__ expects 'node_name' as a positional argument.
        # So we include it in the super() call here, and it will be consumed
        # by Node's __init__ when it's its turn in the MRO chain.

        super().__init__(node_name='aether_gcs_ui_node')

        self.setWindowTitle("Aether GCS")
        self.setGeometry(100, 100, 800, 600)

        # --- Data Storage ---
        self.fleet_state = {}

        # --- UI Elements ---
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # --- NEW: Create a Menu Bar ---
        self.menu_bar = self.menuBar()
        self.sensors_menu = self.menu_bar.addMenu("Sensors")
        
        self.calibrate_accel_action = QAction("Calibrate Accelerometer", self)
        self.calibrate_accel_action.triggered.connect(self.on_calibrate_accel)
        self.sensors_menu.addAction(self.calibrate_accel_action)
        
        # FUTURE IMPROVEMENT: ADD MENU ACTIONS FOR GYRO AND MAGNETOMETER CALIBRATION.

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
        # --- NEW: Create a client for the calibration service ---
        self.start_calibration_client = self.create_client(StartCalibration, '/aether/start_calibration')

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
        rclpy.spin_once(self, timeout_sec=0)

    def fleet_state_callback(self, msg):
        """Receives the state of the entire fleet and updates the UI."""
        new_state = {}
        for drone_msg in msg.drones:
            new_state[drone_msg.system_id] = {
                "id": drone_msg.system_id,
                "firmware": drone_msg.firmware_type,
                "mode": drone_msg.flight_mode,
                "armed": drone_msg.is_armed
            }
        
        if set(new_state.keys()) != set(self.fleet_state.keys()):
            self.update_drone_selector(new_state)

        self.fleet_state = new_state
        self.update_fleet_table()

    def update_fleet_table(self):
        """Redraws the fleet status table with the latest data."""
        self.fleet_table.setRowCount(len(self.fleet_state))
        sorted_drones = sorted(self.fleet_state.values(), key=lambda d: d['id'])

        for row, drone in enumerate(sorted_drones):
            self.fleet_table.setItem(row, 0, QTableWidgetItem(str(drone['id'])))
            self.fleet_table.setItem(row, 1, QTableWidgetItem(drone['firmware']))
            self.fleet_table.setItem(row, 2, QTableWidgetItem(drone['mode']))
            self.fleet_table.setItem(row, 3, QTableWidgetItem("Yes" if drone['armed'] else "No"))

    def update_drone_selector(self, new_state):
        """Updates the dropdown menu for selecting a drone."""
        self.drone_selector.clear()
        sorted_ids = sorted(new_state.keys())
        for drone_id in sorted_ids:
            self.drone_selector.addItem(f"Drone {drone_id}", userData=drone_id)

    def on_upload_mission(self):
        """Opens a file dialog and calls the mission upload service."""
        selected_drone_id = self.drone_selector.currentData()
        if selected_drone_id is None:
            QMessageBox.warning(self, "Selection Error", "No drone selected for mission upload.")
            return

        file_path, _ = QFileDialog.getOpenFileName(self, "Open Mission Plan", "", "Mission Plan Files (*.plan)")

        if file_path:
            if not self.upload_mission_client.wait_for_service(timeout_sec=1.0):
                self.get_logger().error("Mission upload service not available.")
                QMessageBox.critical(self, "Service Error", "The mission upload service is not available. Is the backend running?")
                return

            request = UploadMission.Request()
            request.target_system_id = selected_drone_id
            request.file_path = file_path
            
            self.get_logger().info(f"UI sending request to upload {file_path} to Drone {selected_drone_id}")
            future = self.upload_mission_client.call_async(request)
            future.add_done_callback(self.on_upload_response)

    def on_upload_response(self, future):
        """Handles the response from the mission upload service."""
        try:
            response = future.result()
            self.get_logger().info(f"Mission upload response: Success={response.success}, Message='{response.message}'")
            if response.success:
                QMessageBox.information(self, "Mission Upload", f"Mission upload initiated successfully!\n\n{response.message}")
            else:
                QMessageBox.critical(self, "Mission Upload Failed", f"The mission upload failed.\n\nReason: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")
            QMessageBox.critical(self, "Service Error", f"An exception occurred during the service call:\n{e}")

    def on_calibrate_accel(self):
        """Handles the 'Calibrate Accelerometer' menu action."""
        selected_drone_id = self.drone_selector.currentData()
        if selected_drone_id is None:
            QMessageBox.warning(self, "Selection Error", "No drone selected for calibration.")
            return

        if not self.start_calibration_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error("Start calibration service not available.")
            QMessageBox.critical(self, "Service Error", "The calibration service is not available. Is the backend running?")
            return

        # Create and show the wizard dialog
        self.wizard = CalibrationWizard(self, selected_drone_id)
        
        # Send the request to the backend to start the process
        request = StartCalibration.Request()
        request.target_system_id = selected_drone_id
        request.sensor_type = "accel"
        
        self.get_logger().info(f"UI sending request to start accelerometer calibration for Drone {selected_drone_id}")
        future = self.start_calibration_client.call_async(request)
        future.add_done_callback(self.on_start_calibration_response)

        # Show the wizard to the user
        self.wizard.exec()

    def on_start_calibration_response(self, future):
        """Handles the response after requesting to start a calibration."""
        try:
            response = future.result()
            if not response.success:
                self.get_logger().error(f"Backend failed to start calibration: {response.message}")
                QMessageBox.critical(self, "Calibration Error", f"Could not start calibration.\n\nReason: {response.message}")
                # If the backend failed to start, we should close the wizard we just opened.
                if hasattr(self, 'wizard') and self.wizard.isVisible():
                    self.wizard.reject()
        except Exception as e:
            self.get_logger().error(f"Service call to start calibration failed: {e}")
            if hasattr(self, 'wizard') and self.wizard.isVisible():
                self.wizard.reject()

def main(args=None):
    rclpy.init(args=args)
    app = QApplication(sys.argv)
    gcs_window = GCSMainWindow()
    gcs_window.show()
    
    try:
        app.exec()
    finally:
        gcs_window.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
