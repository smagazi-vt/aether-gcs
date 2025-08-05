import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    This launch file starts all the necessary backend nodes for the Aether GCS.
    """
    
    config_file_path = os.path.join(
        get_package_share_directory('aether_gcs_backend'),
        'config',
        'drone_profiles.yaml'
    )

    # --- Node Definitions ---

    fleet_manager_node = Node(
        package='aether_gcs_backend',
        executable='fleet_manager',
        name='fleet_manager_node',
        output='screen',
        parameters=[{'drone_profiles_path': config_file_path}]
    )

    mission_planner_node = Node(
        package='aether_gcs_backend',
        executable='mission_planner',
        name='mission_planner_backend_node',
        output='screen'
    )
    
    calibration_manager_node = Node(
        package='aether_gcs_backend',
        executable='calibration_manager',
        name='calibration_manager_node',
        output='screen'
    )

    # --- NEWLY ADDED STRATEGIC DECONFLICTION NODE ---
    # This C++ node runs on the GCS to provide high-level warnings.
    strategic_deconfliction_node = Node(
        package='aether_gcs_logic_cpp', # The new C++ package
        executable='strategic_deconfliction_node',
        name='strategic_deconfliction_node',
        output='screen'
    )


    return LaunchDescription([
        fleet_manager_node,
        mission_planner_node,
        calibration_manager_node,
        strategic_deconfliction_node # <-- ADDED THIS NODE
    ])
