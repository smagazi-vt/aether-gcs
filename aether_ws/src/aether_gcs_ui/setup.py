from setuptools import find_packages, setup

package_name = 'aether_gcs_ui'

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
    maintainer='Valtec - Sara Magaziotis-Ginori',
    maintainer_email='sara.magaziotisginori@valtec.ai',
    description='TODO: Package description',
    license='NONE',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'aether_ui = aether_gcs_ui.main_window_node:main',
        ],
    },
)


