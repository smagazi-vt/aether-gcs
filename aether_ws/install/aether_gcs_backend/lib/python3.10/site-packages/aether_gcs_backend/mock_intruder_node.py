#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Quaternion, Twist, Vector3
import sys

class MockIntruderNode(Node):
    """
    This node simulates a second drone by publishing a fake Odometry message.
    Its position can be set via command-line arguments for easy testing.
    """
    def __init__(self):
        super().__init__('mock_intruder_node')
        
        # --- Configuration ---
        self.drone_id = 2 # We will pretend to be Drone 2
        
        # Get the position from command-line arguments, with a default
        try:
            self.x_pos = float(sys.argv[1])
            self.y_pos = float(sys.argv[2])
            self.z_pos = float(sys.argv[3])
        except (IndexError, ValueError):
            self.get_logger().info("Usage: ros2 run aether_gcs_backend mock_intruder <x> <y> <z>")
            self.get_logger().info("Defaulting to position (15, 0, 0)")
            self.x_pos = 15.0
            self.y_pos = 0.0
            self.z_pos = 0.0

        # Create the publisher for the fake odometry topic
        topic_name = f'/drone{self.drone_id}/mavros/global_position/local'
        self.publisher_ = self.create_publisher(Odometry, topic_name, 10)
        
        # Publish the message repeatedly
        self.timer = self.create_timer(0.1, self.timer_callback) # 10 Hz
        
        self.get_logger().info(f"Mock Intruder (Drone {self.drone_id}) started. Publishing fake position at ({self.x_pos}, {self.y_pos}, {self.z_pos})")

    def timer_callback(self):
        msg = Odometry()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'
        msg.child_frame_id = 'base_link'
        
        # Set the fake position
        msg.pose.pose.position = Point(x=self.x_pos, y=self.y_pos, z=self.z_pos)
        # Set a zero velocity for simplicity
        msg.twist.twist.linear = Vector3(x=0.0, y=0.0, z=0.0)
        
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = MockIntruderNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
