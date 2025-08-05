import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

def generate_launch_description():
    # This argument defines the unique MAVLink System ID for THIS specific drone.
    # You MUST set this to a different number for each drone (e.g., 1, 2, 3).
    system_id_arg = DeclareLaunchArgument(
        'system_id',
        default_value='1',
        description='The MAVLink System ID of this vehicle.'
    )

    # This defines the serial port and baud rate for the connection.
    # '/dev/ttyAMA0' is a common default for the Raspberry Pi's GPIO UART.
    # YOU MUST VERIFY THIS on your physical hardware.
    fcu_url_arg = DeclareLaunchArgument(
        'fcu_url',
        default_value='/dev/ttyAMA0:921600',
        description='The connection URL for the flight controller.'
    )

    # Get the path to the default MAVROS config file
    mavros_config_path = os.path.join(
        get_package_share_directory('mavros'), 'launch', 'px4_config.yaml'
    )

    # This action group allows us to push all nodes within it into a namespace
    namespaced_group = GroupAction(
        actions=[
            # --- THIS IS THE CRITICAL FIX ---
            # This pushes all enclosed nodes into a namespace like "drone1"
            PushRosNamespace(['drone', LaunchConfiguration('system_id')]),

            # MAVROS Node
            Node(
                package='mavros',
                executable='mavros_node',
                name='mavros', # The node name will be automatically namespaced
                output='screen',
                parameters=[
                    mavros_config_path,
                    {
                        'fcu_url': LaunchConfiguration('fcu_url'),
                        'gcs_url': '', 
                        'tgt_system': 1,
                        'tgt_component': 1,
                        'system_id': LaunchConfiguration('system_id'),
                        'component_id': 190,
                    }
                ]
            ),
            
            # FUTURE IMPROVEMENT: THE ONBOARD COLLISION AVOIDER NODE WOULD BE LAUNCHED HERE
        ]
    )

    return LaunchDescription([
        system_id_arg,
        fcu_url_arg,
        namespaced_group,
    ])
