from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cat',
            namespace='cat',
            executable='pc_controller',
            name='pc_controller',
            output="screen"
            ),
        Node(
            package='cat',
            namespace='cat',
            executable='state_machine',
            name='state_machine',
            output="screen",
            #remappings=[("/cmd_vel","turtle1/cmd_vel")]
            ),
        Node(
            package='cat',
            namespace='cat',
            executable='tcp_send_node',
            name='tcp_send_node',
            output="screen"
            ),
        Node(
            package='cat',
            namespace='cat',
            executable='tcp_receive_node',
            name='tcp_receive_node',
            output="screen"
            ),
        
    ])