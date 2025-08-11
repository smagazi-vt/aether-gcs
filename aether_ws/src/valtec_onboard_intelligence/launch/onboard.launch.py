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

    # --- THIS IS THE CRITICAL FIX ---
    # We are changing the connection URL to use a more reliable TCP connection
    # for the SITL simulation. The PX4 simulator listens on TCP port 4560.
    fcu_url_arg = DeclareLaunchArgument(
        'fcu_url',
        default_value='udp://:14540@localhost:14557',
        description='The connection URL for the flight controller (SITL).'
    )

    # Get the path to the default MAVROS config file
    mavros_config_path = os.path.join(
        get_package_share_directory('mavros'), 'launch', 'px4_config.yaml'
    )

    namespaced_group = GroupAction(
        actions=[
            PushRosNamespace(['drone', LaunchConfiguration('system_id')]),

            Node(
                package='mavros',
                executable='mavros_node',
                name='mavros',
                output='screen',
                parameters=[
                    mavros_config_path,
                    {
                        'fcu_url': LaunchConfiguration('fcu_url'),
                        # --- THIS IS THE SECOND PART OF THE FIX ---
                        # We explicitly tell MAVROS to use the MAVLink v2.0 protocol.
                        # This helps avoid version detection timeouts.
                        'fcu_protocol': 'v2.0',
                        'gcs_url': 'udp://@127.0.0.1:14550', 
                        'tgt_system': 1,
                        'tgt_component': 1,
                        'system_id': LaunchConfiguration('system_id'),
                        'component_id': 190,
                    }
                ]
            ),
        ]
    )

    return LaunchDescription([
        system_id_arg,
        fcu_url_arg,
        namespaced_group,
    ])
