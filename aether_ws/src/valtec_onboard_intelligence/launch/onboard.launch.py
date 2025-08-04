import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, PushRosNamespace

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
    # You have specified a telemetry port. This means you will use the Pi's GPIO pins (UART).
    # The port name for this can vary. '/dev/ttyAMA0' is a common default.
    # YOU MUST VERIFY THIS on your physical hardware. You can do this by running `ls /dev/tty*`
    # on the Raspberry Pi.
    # The baud rate MUST match the baud rate configured for the corresponding TELEM port
    # in QGroundControl (e.g., SERIAL_BAUD parameter). 921600 is a good choice for a wired link.
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
            # Push a namespace based on the drone's system ID
            PushRosNamespace(['drone', LaunchConfiguration('system_id')]),

            # MAVROS Node
            Node(
                package='mavros',
                executable='mavros_node',
                name='mavros', # The node name will be automatically namespaced
                output='screen',
                parameters=[
                    # Load the default PX4 config file
                    mavros_config_path,
                    # Override specific parameters
                    {
                        'fcu_url': LaunchConfiguration('fcu_url'),
                        'gcs_url': '', # We don't need a GCS connection from here
                        'tgt_system': 1, # We are the GCS for the FCU, so target is 1
                        'tgt_component': 1,
                        'system_id': LaunchConfiguration('system_id'), # Set mavros's system ID
                        'component_id': 190, # 190 is a common ID for companion computers
                    }
                ]
            ),
            
            # FUTURE IMPROVEMENT: THE ONBOARD COLLISION AVOIDER NODE WOULD BE LAUNCHED HERE
            # Node(
            #     package='valtec_onboard_intelligence',
            #     executable='collision_avoider_node',
            #     name='collision_avoider',
            #     output='screen'
            # ),
        ]
    )

    return LaunchDescription([
        system_id_arg,
        fcu_url_arg,
        namespaced_group,
    ])
