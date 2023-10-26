import os
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.actions import ExecuteProcess

def generate_launch_description():
    robot_name_in_model = 'car'
    package_name = 'my_car'
    urdf_name = "my_car.urdf"
    rviz_name = "show.rviz"

    ld = LaunchDescription()
    pkg_share = FindPackageShare(package=package_name).find(package_name) 
    urdf_model_path = os.path.join(pkg_share, f'urdf/{urdf_name}')
    rviz_config_path=os.path.join(pkg_share, f'rviz/{rviz_name}')

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        arguments=[urdf_model_path]
        )

    joint_state_publisher_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        arguments=[urdf_model_path]
        )

    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_path]
        )

    joint_control_node = Node(
        package='my_car',
        executable='joint_control',
        name='joint_control',
        output='screen',
        # arguments=['-d', rviz_config_path]        
    )

    start_gazebo_cmd =  ExecuteProcess(
        cmd=['gazebo', '--verbose','-s', 'libgazebo_ros_init.so', '-s', 'libgazebo_ros_factory.so'],
        output='screen')

    # Launch the robot
    spawn_entity_cmd = Node(
        package='gazebo_ros', 
        executable='spawn_entity.py',
        arguments=['-entity', robot_name_in_model,  '-file', urdf_model_path ], output='screen')


    ld.add_action(robot_state_publisher_node)
    # ld.add_action(joint_control_node)
    ld.add_action(rviz2_node)
    ld.add_action(joint_state_publisher_node)
    # ld.add_action(start_gazebo_cmd)
    # ld.add_action(spawn_entity_cmd)

    return ld