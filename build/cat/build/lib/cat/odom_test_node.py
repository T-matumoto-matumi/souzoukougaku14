import rclpy
from rclpy.node import Node
import math
import numpy as np
from geometry_msgs.msg import Twist,Pose

class OdomTestNode(Node):
    def __init__(self):
        super().__init__("odom_test_node")
        self.vel_sub = self.create_subscription(
            Twist,"cmd_vel",self.vel_cb,10
        )
        self.pose_pub = self.create_publisher(
            Pose,"pose",10
        )
        self.vel_x=0
        self.arg = 0
        self.timer_period =0.1
        self.R = 10
        self.L = 80
        self.pose = [0.0,0.0,0.0]
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        
        
    def vel_cb(self,msg):
        self.vel_x = msg.linear.x
        self.arg = msg.angular.z
        
    def timer_callback(self):
        self.pose[0]+=self.vel_x*math.cos(self.pose[2])*self.timer_period*10
        self.pose[1]+=self.vel_x*math.sin(self.pose[2])*self.timer_period*10
        self.pose[2]+=self.arg*self.timer_period*10
        msg = Pose()
        msg.position.x = self.pose[0]
        msg.position.y = self.pose[1]
        msg.orientation.z = self.pose[2]
        self.pose_pub.publish(msg)      
        
def main(args=None):
    rclpy.init(args=args)
    node = OdomTestNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
        
    
        