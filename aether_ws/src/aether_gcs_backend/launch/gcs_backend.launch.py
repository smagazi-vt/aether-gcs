import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    This launch file starts the necessary backend nodes for the Aether GCS MVP.
    """
    
    config_file_path = os.path.join(
        get_package_share_directory('aether_gcs_backend'),
        'config',
        'drone_profiles.yaml'
    )

    # --- Node Definitions ---

    # 1. The Fleet Manager Node (discovers all drones)
    fleet_manager_node = Node(
        package='aether_gcs_backend',
        executable='fleet_manager',
        name='fleet_manager_node',
        output='screen',
        parameters=[{'drone_profiles_path': config_file_path}]
    )
    
    # 2. The Swarm Coordinator Node (handles mission logic and collision avoidance)
    swarm_coordinator_node = Node(
        package='aether_gcs_backend',
        executable='swarm_coordinator',
        name='swarm_coordinator_node',
        output='screen'
    )


    return LaunchDescription([
        fleet_manager_node,
        swarm_coordinator_node,
    ])
