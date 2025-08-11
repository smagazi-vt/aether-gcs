from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'aether_gcs_backend'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all launch files from the 'launch' directory
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        # Include all config files from the 'config' directory
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='valtec',
    maintainer_email='valtec@todo.todo',
    description='The backend logic and fleet management for the Aether GCS.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fleet_manager = aether_gcs_backend.fleet_manager_node:main',
            'mission_planner = aether_gcs_backend.mission_planner_node:main',
            'calibration_manager = aether_gcs_backend.calibration_manager_node:main',
            'swarm_coordinator = aether_gcs_backend.swarm_coordinator_node:main',
            'mock_intruder = aether_gcs_backend.nodes.mock_intruder_node:main',
        ],
    },
)
