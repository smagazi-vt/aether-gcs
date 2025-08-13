import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    This launch file starts all the necessary backend nodes for the Aether GCS.
    """
    
    # Get the path to the drone_profiles.yaml configuration file
    config_file_path = os.path.join(
        get_package_share_directory('aether_gcs_backend'),
        'config',
        'drone_profiles.yaml'
    )

    # --- Node Definitions ---

    # 1. The Fleet Manager Node
    fleet_manager_node = Node(
        package='aether_gcs_backend',
        executable='fleet_manager',
        name='fleet_manager_node',
        output='screen',
        parameters=[{'drone_profiles_path': config_file_path}]
    )

    # 2. The Mission Planner Backend Node
    mission_planner_node = Node(
        package='aether_gcs_backend',
        executable='mission_planner',
        name='mission_planner_backend_node',
        output='screen'
    )
    
    # 3. The Swarm Coordinator Node
    swarm_coordinator_node = Node(
        package='aether_gcs_backend',
        executable='swarm_coordinator',
        name='swarm_coordinator_node',
        output='screen'
    )

    # The LaunchDescription object gathers all nodes and actions to be executed.
    return LaunchDescription([
        fleet_manager_node,
        mission_planner_node,
        swarm_coordinator_node,
    ])
