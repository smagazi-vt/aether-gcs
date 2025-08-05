#!/usr/bin/env python3

from PyQt6.QtWidgets import (QDialog, QVBoxLayout, QLabel, QProgressBar, QMessageBox)
from PyQt6.QtCore import pyqtSlot
from rclpy.node import Node
from aether_interfaces.msg import CalibrationStatus

class CalibrationWizard(QDialog):
    """
    A dialog window that provides a step-by-step guide for a sensor calibration.
    It subscribes to the /aether/calibration_status topic for live updates.
    """
    def __init__(self, parent_node: Node, drone_id: int):
        super().__init__()
        
        # We need a reference to the parent ROS 2 node to create subscribers
        self.node = parent_node
        self.drone_id = drone_id

        self.setWindowTitle(f"Sensor Calibration - Drone {self.drone_id}")
        self.setMinimumSize(400, 200)

        # --- UI Elements ---
        self.layout = QVBoxLayout(self)

        self.instruction_label = QLabel("Starting calibration...")
        font = self.instruction_label.font()
        font.setPointSize(14)
        self.instruction_label.setFont(font)
        self.instruction_label.setWordWrap(True)
        self.layout.addWidget(self.instruction_label)

        self.progress_bar = QProgressBar()
        self.progress_bar.setRange(0, 100)
        self.layout.addWidget(self.progress_bar)
        
        # --- ROS 2 Integration ---
        # Subscribe to the status topic from the backend manager
        self.status_subscriber = self.node.create_subscription(
            CalibrationStatus,
            '/aether/calibration_status',
            self.status_callback,
            10
        )

    @pyqtSlot(CalibrationStatus)
    def status_callback(self, msg: CalibrationStatus):
        """
        This is a PyQt Slot that is called when a new CalibrationStatus message arrives.
        It updates the UI elements.
        """
        # Ignore messages for other drones
        if msg.system_id != self.drone_id:
            return

        # Update the instruction text
        self.instruction_label.setText(msg.instruction_text)

        # Update the progress bar
        if msg.progress_percentage >= 0:
            self.progress_bar.setValue(int(msg.progress_percentage))
        
        # Handle completion of the calibration
        if msg.is_complete:
            self.status_subscriber.destroy() # Stop listening to the topic
            if msg.success:
                QMessageBox.information(self, "Calibration Complete", "The sensor calibration was successful!")
            else:
                QMessageBox.critical(self, "Calibration Failed", "The sensor calibration failed. Please check the drone and try again.")
            
            self.accept() # Close the dialog window

