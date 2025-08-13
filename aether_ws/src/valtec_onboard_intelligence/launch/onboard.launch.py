import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

def generate_launch_description():
    # MAVLink System ID for this specific drone.
    system_id_arg = DeclareLaunchArgument(
        'system_id',
        default_value='1',
        description='The MAVLink System ID of this vehicle.'
    )

    # The serial port and baud rate for the connection to the Pixhawk.
    # YOU MUST VERIFY THIS on your physical hardware.
    fcu_url_arg = DeclareLaunchArgument(
        'fcu_url',
        default_value='udp://:14540@127.0.0.1:14580',
        description='The connection URL for the flight controller.'
    )

    # Get the path to the default MAVROS config file
    mavros_config_path = os.path.join(
        get_package_share_directory('mavros'), 'launch', 'px4_config.yaml'
    )

    # This action group pushes all nodes within it into a namespace (e.g., "drone1")
    namespaced_group = GroupAction(
        actions=[
            PushRosNamespace(['drone', LaunchConfiguration('system_id')]),

            # MAVROS Node
            Node(
                package='mavros',
                executable='mavros_node',
                name='mavros',
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
            
            # --- NEW: LAUNCH THE ONBOARD COLLISION AVOIDANCE NODE ---
            # This starts the C++ node that handles real-time tactical avoidance.
            Node(
                package='valtec_onboard_intelligence',
                executable='collision_avoider_node',
                name='onboard_collision_avoider',
                output='screen',
                parameters=[
                    # Pass the drone's own ID to the node so it knows who it is.
                    {'system_id': LaunchConfiguration('system_id')}
                ]
            ),
        ]
    )

    return LaunchDescription([
        system_id_arg,
        fcu_url_arg,
        namespaced_group,
    ])
