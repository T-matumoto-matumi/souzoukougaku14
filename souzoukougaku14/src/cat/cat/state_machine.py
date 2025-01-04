import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat,Button
from geometry_msgs.msg import Twist,Pose,PoseArray
from enum import Enum
import math
from math import pi
from scipy.interpolate import interp1d
from tf_transformations import euler_from_quaternion
from scipy.spatial.transform import Rotation as R
import time





class MachineState(Enum):
    manual_mode = 0
    stop = 1
    #test_mode
    go_straight = 2
    go_arg = 3

    bring_two_cup = 4
    catch_black_cup = 5
    put_black_cup = 6
    catch_white_cup = 7
    put_white_cup = 8



class StateMachine(Node):
    def __init__(self):
        super().__init__("state_machine")
        self.joy_sub = self.create_subscription(
            JoyCat,"joy_cat",self.joy_callback,10
        )
        timer_period =0.1
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.robot_state = MachineState.manual_mode#defult mamual mode
        self.state_index=[0,0,0,0,0]#各行動の中身における行動分岐のインデックス,bring_two_cup/catch_black_cup/put_black_cup/catch_white_cup/put_white_cup
        
        self.joy_msg = JoyCat()
        self.vel_msg = Twist()
        self.button_msg = Button()
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
        self.button_pub =self.create_publisher(
            Button,"button",10
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
            self.button_msg.button_1 = bool(self.joy_msg.button_1)
            self.button_msg.button_2 = bool(self.joy_msg.button_2)
            self.button_pub.publish(self.button_msg)
        elif self.robot_state == MachineState.go_straight:
            self.go_straight()
        elif self.robot_state == MachineState.go_arg:
            self.go_arg()

        elif self.robot_state == MachineState.bring_two_cup:
            self.bring_two_cup()
        elif self.robot_state == MachineState.catch_black_cup:
            self.catch_black_cup()
        elif self.robot_state == MachineState.put_black_cup:
            self.put_black_cup()
        elif self.robot_state == MachineState.catch_white_cup:
            self.catch_white_cup()
        elif self.robot_state == MachineState.put_white_cup:
            self.put_white_cup()
        
        
            
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

    def straight(self,aim_l):
        if aim_l>=0:
            #前進
            if self.pose<=aim_l:
                self.pub_vel(0.6,0.0)
                return False
            else:
                self.pub_vel(0.0,0.0)
                return True
        else:
            #後進
            if self.pose>=aim_l:
                self.pub_vel(-0.6,0.0)
                return False
            else:
                self.pub_vel(0.0,0.0)
                return True
    def curve(self,aim_arg):
        delta = aim_arg-self.yaw
        if abs(delta)>0.1:
            if delta>=0:
                self.pub_vel(0.0,0.3)
            else:
                self.pub_vel(0.0,-0.3)
            return False
        else:
            self.pub_vel(0.0,0.0)
            return True
    def grab(self,bool):
        #bool=true:掴む　bool=false:離す
        if bool:
            self.button_msg.button_2 = bool
            self.button_pub.publish(self.button_msg)
        else:
            self.button_msg.button_2 = bool
            self.button_pub.publish(self.button_msg)  

    def upper(self,bool):
        #bool=true:up bool=false:down
        if bool:
            self.button_msg.button_1 = bool
            self.button_pub.publish(self.button_msg)
        else:
            self.button_msg.button_1 = bool
            self.button_pub.publish(self.button_msg)         



                
    def bring_two_cup(self):
        aim_l = 600.0
        if self.pose<=aim_l:
            self.pub_vel(0.6,0.0)
        else:
            self.get_logger().info("complete bring two cup")
            self.pub_vel(0.0,0.0)
            self.robot_state = MachineState.catch_black_cup
    
    def catch_black_cup(self):
        l_1 = -300.0
        arg_1 = -pi/4
        l_2 = 150.0
        if self.state_index[1]==0:
            if self.straight(l_1) is False:
                self.get_logger().info(f":::state:::   catch_black_cup\n:::index:::   {self.state_index[1]}")
            else:
                self.state_index[1]+=1

        elif self.state_index[1]==1:
            if self.curve(arg_1) is False:
                self.get_logger().info(f":::state:::   catch_black_cup\n:::index:::   {self.state_index[1]}")
            else:
                self.state_index[1]+=1

        elif self.state_index[1]==2:
            if self.straight(l_2) is False:
                self.get_logger().info(f":::state:::   catch_black_cup\n:::index:::   {self.state_index[1]}")
            else:
                self.state_index[1]+=1

        elif self.state_index[1]==3:
            self.get_logger().info(f":::state:::   catch_black_cup\n:::index:::   {self.state_index[1]}")
            self.grab(bool=False)
            time.sleep(0.5)
            #upper dowm
            self.upper(bool=False)
            #grab
            self.grab(bool=True)
            time.sleep(1)
            #upper up
            self.upper(bool=True)
            self.robot_state = MachineState.put_black_cup

    def put_black_cup(self):
        arg_1 = -pi/6
        l_1 = 100.0
        if self.state_index[2]==0:
            if self.curve(arg_1) is False:
                self.get_logger().info(f":::state:::   put_black_cup\n:::index:::   {self.state_index[2]}")
            else:
                self.state_index[2]+=1
        elif self.state_index[2]==1:
            if self.straight(l_1) is False:
                self.get_logger().info(f":::state:::   put_black_cup\n:::index:::   {self.state_index[2]}")
            else:
                self.state_index[2]+=1
        elif self.state_index[2]==2:
            self.grab(bool=False)
            time.sleep(1)
            self.robot_state = MachineState.catch_white_cup

    def catch_white_cup(self):
        arg_1 = pi/2
        l_1 = 400.0
        if self.state_index[3]==0:
            if self.curve(arg_1) is False:
                self.get_logger().info(f":::state:::   catch_white_cup\n:::index:::   {self.state_index[3]}")
            else:
                self.state_index[3]+=1
        elif self.state_index[3]==1:
            self.grab(False)
            self.upper(False)
            if self.straight(l_1) is False:
                self.get_logger().info(f":::state:::   catch_white_cup\n:::index:::   {self.state_index[3]}")
            else:
                self.state_index[3]+=1
        elif self.state_index[3]==2:
            self.grab(bool=True)
            time.sleep(1)
            self.upper(bool=True)
            time.sleep(1)
            self.robot_state = MachineState.put_white_cup

    


        
        





                
                
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