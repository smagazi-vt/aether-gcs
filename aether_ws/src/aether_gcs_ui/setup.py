from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'aether_gcs_ui'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='valtec',
    maintainer_email='valtec@todo.todo',
    description='The graphical user interface for the Aether GCS MVP.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'aether_ui = aether_gcs_ui.main_window_node:main',
        ],
    },
)
