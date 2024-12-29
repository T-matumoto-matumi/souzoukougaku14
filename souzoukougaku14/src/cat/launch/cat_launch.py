from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cat',
            namespace='cat',
            executable='cam_node',
            name='cam_node',
            

            ),
        Node(
            package='ros2_aruco',
            namespace='cat',
            executable='aruco_node_tf',
            name='aruco_node_tf',
           
            ),
        Node(
            package='cat',
            namespace='cat',
            executable='state_machine',
            name='state_machine',
            
        ),
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
            executable='udp_send_node',
            name='udp_send_node',
        ),
        Node(
            package='cat',
            namespace='cat',
            executable='udp_receive_node',
            name='udp_send_node',
        ),
        
        
    ])