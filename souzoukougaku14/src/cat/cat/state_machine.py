import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat
from geometry_msgs.msg import Twist,Pose,PoseArray
from enum import Enum
import math
from math import pi
from scipy.interpolate import interp1d
from tf_transformations import euler_from_quaternion
from scipy.spatial.transform import Rotation as R





class MachineState(Enum):
    manual_mode = 1
    auto_mode = 2
    stop = 4
    test = 5
    go_straight = 6
    go_arg = 7



class StateMachine(Node):
    def __init__(self):
        super().__init__("state_machine")
        self.joy_sub = self.create_subscription(
            JoyCat,"joy_cat",self.joy_callback,10
        )
        timer_period =0.1
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.robot_state = MachineState.manual_mode#defult mamual mode

        
        self.joy_msg = JoyCat()
        self.vel_msg = Twist()
        self.pose = 0.0#x
        self.yaw = 0.0
        self.R = 15 #半径[mm]
        self.L = 105 #機体の幅[mm]
        self.vel_pub = self.create_publisher(
            Twist,"cmd_vel",10
        )
        self.pose_sub = self.create_subscription(
            Pose,"pose",self.pose_callback,10
        )
        self.aruco_pose_sub = self.create_subscription(
            PoseArray,"aruco_poses",self.aruco_callback,10
        )
        
    def aruco_callback(self,msg):
        #検出したマーカの数
        count = len(msg.poses)
        yaw_array =[]
        ave_yaw=0.0
        for i,pose in enumerate(msg.poses):
            #self.get_logger().info(f"Pose {i}: x={pose.orientation.x}, y={pose.orientation.y}, z={pose.orientation.z},w={pose.orientation.w}")
            q_x = pose.orientation.x
            q_y = pose.orientation.y
            q_z = pose.orientation.z
            q_w = pose.orientation.w
            #z axix flippingの補正
            q = (q_x,q_y,q_z,q_w)
            r = R.from_quat(q)
            z_axis = r.apply([0,0,1])
            if z_axis[2]<0:
                #z-flipping
                (roll,pitch,yaw) = euler_from_quaternion((-q_x,-q_y,-q_z,-q_w))
            else:
                (roll,pitch,yaw) = euler_from_quaternion((q_x,q_y,q_z,q_w))
            yaw_array.append(yaw)
            ave_yaw+=yaw
        ave_yaw=ave_yaw/count
        self.yaw = ave_yaw
        self.get_logger().info(f"yaw = {ave_yaw}")
        
        
        
    def pose_callback(self,msg):
        self.pose = msg.position.x
    
        
    def joy_callback(self,msg):
        self.joy_msg = msg
        
    def timer_callback(self):
        if self.robot_state == MachineState.manual_mode:
            self.vel_msg.linear.x=self.joy_msg.x
            self.vel_msg.angular.z=self.joy_msg.yaw
            self.vel_pub.publish(self.vel_msg)
        elif self.robot_state == MachineState.go_straight:
            self.go_straight()
        elif self.robot_state == MachineState.go_arg:
            self.go_arg()
            
    def go_arg(self):
        aim = pi/2
        print(self.yaw)
        if pi/2-self.yaw>=0:
            self.pub_vel(0.0,0.3)
        else:
            print("gool")
            self.pub_vel(0.0,0.0)
            
    def go_straight(self):
        aim_x = 1000
        print(self.pose)
        if self.pose<=aim_x:
            self.pub_vel(0.6,0.0)
        else:
            print("gool")
            self.pub_vel(0.0,0.0)
                
                
                
    def pub_vel(self,vel_x,ang_z):
        self.vel_msg.linear.x=vel_x
        self.vel_msg.angular.z=ang_z
        self.vel_pub.publish(self.vel_msg)
        

    def PItoPI(self,angle):
        while angle>=pi:
            angle=angle-2*pi
        while angle<=-pi:
            angle=angle+2*pi
        return angle

    
    
    def sgn(self,x):
        if x<0:
            return -1
        else:
            return 1
        
    def dis_comp(self,idx_x,idx_y,x,y):#二点間距離
        l_1 = math.hypot(idx_x-x,idx_y-y)
        return l_1
    
    def calc_argment(self,gool):
        p_x=gool[0]-self.pose[0]
        p_y=gool[1]-self.pose[1]
        target_angle = math.atan2(p_y, p_x)
        current_yaw = self.PItoPI(self.pose[2])
        alpha = target_angle-current_yaw
        delta_alpha = math.atan2(math.sin(alpha),math.cos(alpha))
        return delta_alpha          
            

            
def main(args=None):
    rclpy.init(args=args)
    node = StateMachine()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()