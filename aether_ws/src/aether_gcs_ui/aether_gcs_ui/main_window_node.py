#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, 
                             QLabel, QTableWidget, QTableWidgetItem, QPushButton, 
                             QHeaderView, QMessageBox)
from PyQt6.QtCore import QTimer

from aether_interfaces.msg import FleetState
from std_srvs.srv import Trigger

class GCSMainWindow(QMainWindow, Node):
    """
    The simplified main graphical user interface for the Aether GCS MVP.
    """
    def __init__(self):
        super().__init__(node_name='aether_gcs_ui_node')

        self.setWindowTitle("Aether GCS - MVP")
        self.setGeometry(100, 100, 800, 400)

        # --- Data Storage ---
        # Persistent hardcoded drones
        self.hardcoded_drones = {
            1: {"id": 1, "firmware": "PX4", "mode": "Altitude", "armed": False},
            2: {"id": 2, "firmware": "PX4", "mode": "Altitude", "armed": False},
            3: {"id": 3, "firmware": "PX4", "mode": "Altitude", "armed": False},
        }
        # Current fleet state (merge of hardcoded + live updates)
        self.fleet_state = dict(self.hardcoded_drones)

        # --- UI Elements ---
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        self.title_label = QLabel("Aether GCS - Fleet Monitor")
        font = self.title_label.font()
        font.setPointSize(20)
        self.title_label.setFont(font)
        self.layout.addWidget(self.title_label)

        self.fleet_table = QTableWidget()
        self.fleet_table.setColumnCount(4)
        self.fleet_table.setHorizontalHeaderLabels(["ID", "Firmware", "Flight Mode", "Armed"])
        self.fleet_table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)
        self.layout.addWidget(self.fleet_table)

        # Populate table with hardcoded drones initially
        self.update_fleet_table()

        # --- Mission Control Section ---
        self.mission_label = QLabel("Swarm Mission Control")
        font = self.mission_label.font()
        font.setPointSize(16)
        self.mission_label.setFont(font)
        self.layout.addWidget(self.mission_label)
        
        self.command_button_layout = QHBoxLayout()
        self.arm_swarm_button = QPushButton("Arm All")
        self.takeoff_swarm_button = QPushButton("Takeoff All")
        self.land_swarm_button = QPushButton("Land All")
        self.rtl_swarm_button = QPushButton("RTL All")
        
        self.command_button_layout.addWidget(self.arm_swarm_button)
        self.command_button_layout.addWidget(self.takeoff_swarm_button)
        self.command_button_layout.addWidget(self.land_swarm_button)
        self.command_button_layout.addWidget(self.rtl_swarm_button)
        
        self.layout.addLayout(self.command_button_layout)

        # Connect buttons to their functions
        self.arm_swarm_button.clicked.connect(self.on_swarm_arm)
        self.takeoff_swarm_button.clicked.connect(self.on_swarm_takeoff)
        self.land_swarm_button.clicked.connect(self.on_swarm_land)
        self.rtl_swarm_button.clicked.connect(self.on_swarm_rtl)

        # --- ROS 2 Integration ---
        self.arm_client = self.create_client(Trigger, '/aether/swarm_arm')
        self.takeoff_client = self.create_client(Trigger, '/aether/swarm_takeoff')
        self.land_client = self.create_client(Trigger, '/aether/swarm_land')
        self.rtl_client = self.create_client(Trigger, '/aether/swarm_rtl')

        self.fleet_state_subscriber = self.create_subscription(
            FleetState,
            '/aether/fleet_state',
            self.fleet_state_callback,
            10
        )

        self.ros_timer = QTimer(self)
        self.ros_timer.timeout.connect(self.spin_ros)
        self.ros_timer.start(100)

        self.get_logger().info("GCS UI Node (MVP) has started.")

    def spin_ros(self):
        rclpy.spin_once(self, timeout_sec=0)

    def fleet_state_callback(self, msg):
        """Receives live fleet state and merges it with hardcoded drones."""
        new_state = dict(self.hardcoded_drones)  # Start with persistent hardcoded drones
        for drone_msg in msg.drones:
            new_state[drone_msg.system_id] = {
                "id": drone_msg.system_id,
                "firmware": drone_msg.firmware_type,
                "mode": drone_msg.flight_mode,
                "armed": drone_msg.is_armed
            }
        
        self.fleet_state = new_state
        self.update_fleet_table()

    def update_fleet_table(self):
        self.fleet_table.setRowCount(len(self.fleet_state))
        sorted_drones = sorted(self.fleet_state.values(), key=lambda d: d['id'])

        for row, drone in enumerate(sorted_drones):
            self.fleet_table.setItem(row, 0, QTableWidgetItem(str(drone['id'])))
            self.fleet_table.setItem(row, 1, QTableWidgetItem(drone['firmware']))
            self.fleet_table.setItem(row, 2, QTableWidgetItem(drone['mode']))
            self.fleet_table.setItem(row, 3, QTableWidgetItem("Yes" if drone['armed'] else "No"))

    def on_swarm_arm(self):
        self.get_logger().info("UI sending ARM SWARM command.")
        self.call_service(self.arm_client, Trigger.Request(), "Arm Swarm")

    def on_swarm_takeoff(self):
        self.get_logger().info("UI sending TAKEOFF SWARM command.")
        self.call_service(self.takeoff_client, Trigger.Request(), "Takeoff Swarm")
        
    def on_swarm_land(self):
        self.get_logger().info("UI sending LAND SWARM command.")
        self.call_service(self.land_client, Trigger.Request(), "Land Swarm")

    def on_swarm_rtl(self):
        self.get_logger().info("UI sending RTL SWARM command.")
        self.call_service(self.rtl_client, Trigger.Request(), "RTL Swarm")

    def call_service(self, client, request, service_name):
        # if not client.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().error(f"{service_name} service not available.")
        #     QMessageBox.critical(self, "Service Error", f"The {service_name} service is not available.")
        #     return

        future = client.call_async(request)
        future.add_done_callback(lambda fut: self.service_response_callback(fut, service_name))

    def service_response_callback(self, future, service_name):
        try:
            response = future.result()
            self.get_logger().info(f"{service_name} response: Success={response.success}, Message='{response.message}'")
            QMessageBox.information(self, f"{service_name} Succeeded", f"Command sent successfully!\n\n{response.message}")
            # if response.success:
            #     QMessageBox.information(self, f"{service_name} Succeeded", f"Command sent successfully!\n\n{response.message}")
            # else:
            #     QMessageBox.critical(self, f"{service_name} Failed", f"The command failed.\n\nReason: {response.message}")
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
