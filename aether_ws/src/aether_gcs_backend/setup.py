from setuptools import find_packages, setup
import os
import glob

package_name = 'aether_gcs_backend'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob.glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name, 'config'), glob.glob(os.path.join('config', 'drone_profiles.yaml'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Valtec - Sara Magaziotis-Ginori',
    maintainer_email='sara.magaziotisginori@valtec.ai',
    description='Contains node for receiving mission plans and node for dynamically discovering new drones.',
    license='NONE',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fleet_manager = aether_gcs_backend.fleet_manager_node:main',
            'mission_planner = aether_gcs_backend.mission_planner_node:main'
        ],
    },
)
