import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    # Get the path to the drone_profiles.yaml file
    config_file_path = os.path.join(
        get_package_share_directory('aether_gcs_backend'),
        'config',
        'drone_profiles.yaml'
    )

    return LaunchDescription([
        Node(
            package='aether_gcs_backend',
            #TODO: VERIFY THE ENTRYPOINT NAME
            executable='fleet_manager', # Assumes you named the entry point 'fleet_manager'
            name='fleet_manager',
            output='screen',
            parameters=[{'drone_profiles_path': config_file_path}]
        )
    ])
