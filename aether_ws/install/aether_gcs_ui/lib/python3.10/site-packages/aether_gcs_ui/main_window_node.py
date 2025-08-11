#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, 
                             QLabel, QTableWidget, QTableWidgetItem, QPushButton, 
                             QFileDialog, QHeaderView, QComboBox, QMessageBox)
from PyQt6.QtCore import QTimer
from PyQt6.QtGui import QAction

from aether_interfaces.srv import UploadMission
from aether_interfaces.msg import FleetState, DeconflictionWarning
from std_srvs.srv import Trigger 

class GCSMainWindow(QMainWindow, Node):
    """
    The main graphical user interface for the Aether GCS.
    Focuses on fleet monitoring and swarm command for the MVP.
    """
    def __init__(self):
        # Explicitly initialize each parent class
        super().__init__(node_name='aether_gcs_ui_node')

        self.setWindowTitle("Aether GCS")
        self.setGeometry(100, 100, 800, 600)

        self.fleet_state = {}

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

        # --- Individual Mission Control ---
        self.mission_label = QLabel("Individual Mission Control")
        self.layout.addWidget(self.mission_label)
        
        self.drone_selector = QComboBox()
        self.layout.addWidget(self.drone_selector)

        self.upload_button = QPushButton("Upload Mission Plan to Selected Drone...")
        self.upload_button.clicked.connect(self.on_upload_mission)
        self.layout.addWidget(self.upload_button)
        
        # --- Swarm Command Section ---
        self.swarm_label = QLabel("Swarm Command")
        font = self.swarm_label.font()
        font.setPointSize(16)
        self.swarm_label.setFont(font)
        self.layout.addWidget(self.swarm_label)

        self.swarm_button_layout = QHBoxLayout()
        self.arm_swarm_button = QPushButton("Arm All")
        self.takeoff_swarm_button = QPushButton("Takeoff All")
        self.land_swarm_button = QPushButton("Land All")
        self.rtl_swarm_button = QPushButton("RTL All")
        
        self.swarm_button_layout.addWidget(self.arm_swarm_button)
        self.swarm_button_layout.addWidget(self.takeoff_swarm_button)
        self.swarm_button_layout.addWidget(self.land_swarm_button)
        self.swarm_button_layout.addWidget(self.rtl_swarm_button)
        
        self.layout.addLayout(self.swarm_button_layout)

        self.arm_swarm_button.clicked.connect(self.on_swarm_arm)
        self.takeoff_swarm_button.clicked.connect(self.on_swarm_takeoff)
        self.land_swarm_button.clicked.connect(self.on_swarm_land)
        self.rtl_swarm_button.clicked.connect(self.on_swarm_rtl)


        # --- ROS 2 Integration ---
        self.upload_mission_client = self.create_client(UploadMission, '/aether/upload_mission')
        
        self.swarm_arm_client = self.create_client(Trigger, '/aether/swarm_arm')
        self.swarm_takeoff_client = self.create_client(Trigger, '/aether/swarm_takeoff')
        self.swarm_land_client = self.create_client(Trigger, '/aether/swarm_land')
        self.swarm_rtl_client = self.create_client(Trigger, '/aether/swarm_rtl')

        self.fleet_state_subscriber = self.create_subscription(
            FleetState, '/aether/fleet_state', self.fleet_state_callback, 10)

        self.deconfliction_subscriber = self.create_subscription(
            DeconflictionWarning, '/aether/deconfliction_warnings', self.deconfliction_warning_callback, 10)

        self.ros_timer = QTimer(self)
        self.ros_timer.timeout.connect(self.spin_ros)
        self.ros_timer.start(100)

        self.get_logger().info("GCS UI Node has started.")

    def spin_ros(self):
        rclpy.spin_once(self, timeout_sec=0)

    def fleet_state_callback(self, msg):
        new_state = {}
        for drone_msg in msg.drones:
            new_state[drone_msg.system_id] = {
                "id": drone_msg.system_id, "firmware": drone_msg.firmware_type,
                "mode": drone_msg.flight_mode, "armed": drone_msg.is_armed
            }
        
        if set(new_state.keys()) != set(self.fleet_state.keys()):
            self.update_drone_selector(new_state)

        self.fleet_state = new_state
        self.update_fleet_table()
    
    def deconfliction_warning_callback(self, msg):
        self.get_logger().warn(f"Received deconfliction warning: {msg.warning_text}")
        QMessageBox.critical(self, "Strategic Conflict Warning", 
            f"Conflict detected between Drone {msg.drone_id_1} and Drone {msg.drone_id_2}!\n\n"
            f"Details: {msg.warning_text}")

    def update_fleet_table(self):
        self.fleet_table.setRowCount(len(self.fleet_state))
        sorted_drones = sorted(self.fleet_state.values(), key=lambda d: d['id'])
        for row, drone in enumerate(sorted_drones):
            self.fleet_table.setItem(row, 0, QTableWidgetItem(str(drone['id'])))
            self.fleet_table.setItem(row, 1, QTableWidgetItem(drone['firmware']))
            self.fleet_table.setItem(row, 2, QTableWidgetItem(drone['mode']))
            self.fleet_table.setItem(row, 3, QTableWidgetItem("Yes" if drone['armed'] else "No"))

    def update_drone_selector(self, new_state):
        self.drone_selector.clear()
        sorted_ids = sorted(new_state.keys())
        for drone_id in sorted_ids:
            self.drone_selector.addItem(f"Drone {drone_id}", userData=drone_id)

    def on_upload_mission(self):
        selected_drone_id = self.drone_selector.currentData()
        if selected_drone_id is None:
            QMessageBox.warning(self, "Selection Error", "No drone selected for mission upload.")
            return

        file_path, _ = QFileDialog.getOpenFileName(self, "Open Mission Plan", "", "Mission Plan Files (*.plan)")
        if file_path:
            self.call_service(self.upload_mission_client, UploadMission.Request(
                target_system_id=selected_drone_id, file_path=file_path), "Mission Upload")

    def on_swarm_arm(self):
        self.get_logger().info("UI sending ARM SWARM command.")
        self.call_service(self.swarm_arm_client, Trigger.Request(), "Arm Swarm")

    def on_swarm_takeoff(self):
        self.get_logger().info("UI sending TAKEOFF SWARM command.")
        self.call_service(self.swarm_takeoff_client, Trigger.Request(), "Takeoff Swarm")

    def on_swarm_land(self):
        self.get_logger().info("UI sending LAND SWARM command.")
        self.call_service(self.swarm_land_client, Trigger.Request(), "Land Swarm")

    def on_swarm_rtl(self):
        self.get_logger().info("UI sending RTL SWARM command.")
        self.call_service(self.swarm_rtl_client, Trigger.Request(), "RTL Swarm")

    def call_service(self, client, request, service_name):
        if not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().error(f"{service_name} service not available.")
            QMessageBox.critical(self, "Service Error", f"The {service_name} service is not available.")
            return

        future = client.call_async(request)
        future.add_done_callback(lambda fut: self.service_response_callback(fut, service_name))

    def service_response_callback(self, future, service_name):
        try:
            response = future.result()
            self.get_logger().info(f"{service_name} response: Success={response.success}, Message='{response.message}'")
            if response.success:
                QMessageBox.information(self, f"{service_name} Succeeded", f"Command sent successfully!\n\n{response.message}")
            else:
                QMessageBox.critical(self, f"{service_name} Failed", f"The command failed.\n\nReason: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call for {service_name} failed: {e}")
            QMessageBox.critical(self, "Service Error", f"An exception occurred during the {service_name} call:\n{e}")

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
