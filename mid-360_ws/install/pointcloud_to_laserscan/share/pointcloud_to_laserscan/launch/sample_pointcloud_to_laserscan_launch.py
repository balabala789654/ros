from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory





def generate_launch_description():
    package_path = get_package_share_directory('pointcloud_to_laserscan')

    rviz_config_path = os.path.join(package_path, 'config', 'show.rviz')

    livox_rviz = Node(
            package='rviz2',
            executable='rviz2',
            output='screen',
            arguments=['-d', rviz_config_path]
        )
    
    return LaunchDescription([
        # DeclareLaunchArgument(
        #     name='scanner', default_value='scanner',
        #     description='Namespace for sample topics'
        # ),
        # Node(
        #     package='pointcloud_to_laserscan', executable='dummy_pointcloud_publisher',
        #     remappings=[('cloud', [LaunchConfiguration(variable_name='scanner'), '/cloud'])],
        #     parameters=[{'cloud_frame_id': 'cloud', 'cloud_extent': 2.0, 'cloud_size': 500}],
        #     name='cloud_publisher'
        # ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_transform_publisher',
            arguments=[
                '--x', '0', '--y', '0', '--z', '0',
                '--qx', '0', '--qy', '0', '--qz', '0', '--qw', '1',
                '--frame-id', 'map', '--child-frame-id', 'livox_frame'
            ]
        ),
        Node(
            package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
            remappings=[('cloud_in', '/livox/lidar'),
                        ('scan','/scan')],
            parameters=[{
                'target_frame': 'livox_frame',
                'transform_tolerance': 0.01,
                'min_height': 0.0,
                'max_height': 10.0,
                'angle_min': -3.1416,  # -M_PI/2
                'angle_max': 3.1416,  # M_PI/2
                'angle_increment': 0.0087,  # M_PI/360.0
                'scan_time': 0.3333,
                'range_min': 0.45,
                'range_max': 4.0,
                'use_inf': True,
                'inf_epsilon': 1.0
            }],
            name='pointcloud_to_laserscan'
        ),
        livox_rviz
    ])
