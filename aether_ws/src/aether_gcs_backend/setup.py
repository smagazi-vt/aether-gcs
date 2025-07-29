from setuptools import find_packages, setup

package_name = 'aether_gcs_backend'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='valtec',
    maintainer_email='valtec@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fleet_manager = aether_gcs_backend.fleet_manager_node:main',
            'mission_planner = aether_gcs_backend.mission_planner_node:main'
        ],
    },
)
