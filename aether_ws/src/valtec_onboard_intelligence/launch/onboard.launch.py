import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # --- HARDWARE DEPENDENCY 1: MAVLINK SYSTEM ID ---
    # This launch argument defines the unique MAVLink System ID for THIS specific drone.
    # You MUST set this to a different number for each drone in your fleet (e.g., 1, 2, 3).
    # You can set it when you launch the file, e.g., `ros2 launch ... system_id:=2`
    system_id_arg = DeclareLaunchArgument(
        'system_id',
        default_value='1',
        description='The MAVLink System ID of this vehicle.'
    )

    # --- HARDWARE DEPENDENCY 2: FLIGHT CONTROLLER CONNECTION ---
    # This defines the serial port and baud rate for the connection between the
    # Raspberry Pi and the Pixhawk flight controller.
    #
    # RELEVANT QUESTION: How will you physically connect the Raspberry Pi to the Pixhawk?
    # - If using a USB cable, the port will likely be '/dev/ttyACM0'.
    # - If using the Raspberry Pi's GPIO pins (UART), the port will be '/dev/ttyS0' or '/dev/ttyAMA0'.
    # You MUST verify this on your physical hardware.
    fcu_url_arg = DeclareLaunchArgument(
        'fcu_url',
        default_value='/dev/ttyACM0:57600',
        description='The connection URL for the flight controller.'
    )

    # Get the path to the default MAVROS config file
    mavros_config_path = os.path.join(
        get_package_share_directory('mavros'), 'launch', 'px4_config.yaml'
    )

    # MAVROS Node
    mavros_node = Node(
        package='mavros',
        executable='mavros_node',
        name='mavros',
        output='screen',
        parameters=[
            # Load the default PX4 config file
            mavros_config_path,
            # Override specific parameters
            {
                'fcu_url': LaunchConfiguration('fcu_url'),
                'gcs_url': '', # We don't need a GCS connection from here
                'tgt_system': LaunchConfiguration('system_id'),
                'tgt_component': 1,
                'system_id': 245, # This is the ID of the companion computer, 245 is a common default
                'component_id': 190,
            }
        ]
    )

    return LaunchDescription([
        system_id_arg,
        fcu_url_arg,
        mavros_node,
    ])
