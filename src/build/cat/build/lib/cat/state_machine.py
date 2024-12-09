import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat
from geometry_msgs.msg import Twist,Pose
from enum import Enum
import math
from math import pi
import numpy as np
from scipy.interpolate import interp1d




class MachineState(Enum):
    manual_mode = 1
    auto_mode = 2
    path_2to3 = 3
    stop = 4
    test = 5



class StateMachine(Node):
    def __init__(self):
        super().__init__("state_machine")
        self.joy_sub = self.create_subscription(
            JoyCat,"joy_cat",self.joy_callback,10
        )
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.robot_state = MachineState.auto_mode #defult mamual mode
        self.minigool = [0.0,0.0]
        
        self.joy_msg = JoyCat()
        self.vel_msg = Twist()
        self.pose = [0.0,0.0,0.0]#x,y,yaw
        self.R = 15 #半径[mm]
        self.L = 105 #機体の幅[mm]
        self.vel_pub = self.create_publisher(
            Twist,"cmd_vel",10
        )
        self.pose_sub = self.create_subscription(
            Pose,"pose",self.pose_callback,10
        )
        
        #path 1to2
        self.path_1to2_t = np.array([0,1,2,3])
        self.path_1to2_x = np.array([0,250,500,1000])
        self.path_1to2_y = np.array([0,0,0,0])
        self.f_CS_y_path_1to2 = interp1d(self.path_1to2_t, self.path_1to2_y, kind='linear')
        self.f_CS_x_path_1to2 = interp1d(self.path_1to2_t, self.path_1to2_x, kind='linear')
        self.xnew_path_1to2 =np.linspace(0, 3, num=10)
        self.last_index_path_1to2 = len(self.xnew_path_1to2)-1
        self.index_path_1to2 =0
        
        #path 2to3
        self.path_2to3_t = np.array([0,1,2,3])
        self.path_2to3_x = np.array([0,100,100,0])
        self.path_2to3_y = np.array([100,1000,0,0])
        self.f_CS_y_path_2to3 = interp1d(self.path_2to3_t, self.path_2to3_y, kind='linear')
        self.f_CS_x_path_2to3 = interp1d(self.path_2to3_t, self.path_2to3_x, kind='linear')
        self.xnew_path_2to3 =np.linspace(0, 3, num=10)
        self.last_index_path_2to3 = len(self.xnew_path_2to3)-1
        self.index_path_2to3 =0
        
    def pose_callback(self,msg):
        self.pose[0] = msg.position.x
        self.pose[1] = msg.position.y
        self.pose[2] = msg.orientation.z
    
        
    def joy_callback(self,msg):
        self.joy_msg = msg
        
    def timer_callback(self):
        if self.robot_state == MachineState.manual_mode:
            self.vel_msg.linear.x=self.joy_msg.x
            self.vel_msg.angular.z=self.joy_msg.yaw
            self.vel_pub.publish(self.vel_msg)
            
        elif self.robot_state == MachineState.auto_mode:
            self.move_from1to2()
        elif self.robot_state == MachineState.path_2to3:
            self.move_from2to3()
        elif self.robot_state == MachineState.stop:
            self.pub_vel(0.0,0.0)
        elif self.robot_state == MachineState.test:
            k_p = 0.5
            if self.joy_msg.button_1 == 1:
                delta =math.pi/2-self.pose[2]
                delta_bf = math.atan2(math.sin(delta),math.cos(delta))/pi
                self.pub_vel(0.0,k_p*(delta_bf))
                print(delta_bf)
            elif self.joy_msg.button_2 == 1:
                delta =-math.pi/2-self.pose[2]
                delta_bf = math.atan2(math.sin(delta),math.cos(delta))/pi
                self.pub_vel(0.0,k_p*(delta_bf))
                print(delta_bf)
            else:
                self.pub_vel(0.0,0.0)
                
                    
        
    def move_from1to2(self):
        #回転のゲイン後できれいに書き直す
        k_p = 0.400
        
        if self.index_path_1to2<self.last_index_path_1to2:
            self.minigool = self.aim_point(
                cx=self.f_CS_x_path_1to2(self.xnew_path_1to2),
                cy=self.f_CS_y_path_1to2(self.xnew_path_1to2),
                index=self.index_path_1to2,
                x=self.pose[0],
                y=self.pose[1]
                )
            
            fai = math.atan2(self.minigool[1]-self.pose[1],self.minigool[0]-self.pose[0])
            delta = fai - self.pose[2]
            delta_bf = math.atan2(math.sin(delta),math.cos(delta))
            # if delta_bf >= pi/4:
            #     self.pub_vel(0.0,k_p*delta_bf/pi)
            # elif delta_bf <= -pi/4:
            #     self.pub_vel(0.0,k_p*delta_bf/pi)
            # else:
            #     self.pub_vel(0.5,0.0)
            self.pub_vel(0.5,2*0.5*math.sin(delta_bf))
            #print(self.index_path_1to2)
            print(delta_bf)
            
            if math.fabs(self.pose[0]-self.f_CS_x_path_1to2(self.xnew_path_1to2)[self.index_path_1to2+1])<20 and math.fabs(self.pose[1]-self.f_CS_y_path_1to2(self.xnew_path_1to2)[self.index_path_1to2+1])<20:
                self.index_path_1to2+=1
        
        elif self.index_path_1to2 == self.last_index_path_1to2:
            self.get_logger().info("purepath is gool!!")
            self.robot_state = MachineState.stop
            
    def move_from2to3(self):
        #回転のゲイン後できれいに書き直す
        k_p = 0.1500
        
        if self.index_path_2to3<self.last_index_path_2to3:
            self.minigool = self.aim_point(
                cx=self.f_CS_x_path_2to3(self.xnew_path_2to3),
                cy=self.f_CS_y_path_2to3(self.xnew_path_2to3),
                index=self.index_path_2to3,
                x=self.pose[0],
                y=self.pose[1]
                )
            
            fai = math.atan2(self.minigool[1]-self.pose[1],self.minigool[0]-self.pose[0])
            delta = fai - self.pose[2] + pi
            delta_bf = math.atan2(math.sin(delta),math.cos(delta))
            if delta_bf >= pi/8:
                self.pub_vel(-2.0,k_p*delta_bf)
            elif delta_bf <= -pi/8:
                self.pub_vel(-2.0,k_p*delta_bf)
            else:
                self.pub_vel(-5.0,0.0)
            print(self.index_path_1to2)
            
            if math.fabs(self.pose[0]-self.f_CS_x_path_2to3(self.xnew_path_2to3)[self.index_path_2to3+1])<10 and math.fabs(self.pose[1]-self.f_CS_y_path_2to3(self.xnew_path_2to3)[self.index_path_2to3+1])<10:
                self.index_path_2to3+=1
        
        elif self.index_path_2to3 == self.last_index_path_2to3:
            self.get_logger().info("purepath is gool!!")
                
                
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
            
    def aim_point(self,cx,cy,index,x,y):
        #ｘ，ｙは今の位置
        #indexはインデックス
        r = 15.0#探索半径
        p_now=[x,y]
        gool =[0.0,0.0]
        idx_i=[cx[index]-p_now[0],cy[index]-p_now[1]]
        idx_i_1=[cx[index+1]-p_now[0],cy[index+1]-p_now[1]]
        dx = idx_i_1[0]-idx_i[0]
        dy = idx_i_1[1]-idx_i[1]
        d_r = math.hypot(dx,dy)
        D = (idx_i[0]*idx_i_1[1])-(idx_i[1]*idx_i_1[0])
        maxX=max(idx_i[0],idx_i_1[0])
        minX=min(idx_i[0],idx_i_1[0])
        maxY=max(idx_i[1],idx_i_1[1])
        minY=min(idx_i[1],idx_i_1[1])
        lam = (r*d_r)**2-D**2#lam>0交点二つ,lam=0接する,lam<0交点なし
        #ここからは交点を求めてそこから目標点を算出している
        if lam>0:
            interpoint_1=[(D*dy+self.sgn(dy)*dx*(((r*d_r))**2-(D**2))**0.5)/(d_r**2),(-D*dx+math.fabs(dy)*math.sqrt((r*d_r)**2)-D**2)/(d_r**2)]
            interpoint_2=[(D*dy-self.sgn(dy)*dx*(((r*d_r)**2-D**2)**0.5))/(d_r**2),(-D*dx-math.fabs(dy)*math.sqrt((r*d_r)**2)-D**2)/(d_r**2)]
            l_now = self.dis_comp(idx_i_1[0],idx_i_1[1],0,0)
            l_inter1=self.dis_comp(idx_i_1[0],idx_i_1[1],interpoint_1[0],interpoint_1[1])
            l_inter2=self.dis_comp(idx_i_1[0],idx_i_1[1],interpoint_2[0],interpoint_2[1])
            if(minX<=interpoint_1[0]<=maxX and minY<=interpoint_1[1]<=maxY and minX<=interpoint_2[0]<=maxX and minY<=interpoint_2[1]<=maxY):
                #交点二つとも有効
                if l_inter1<l_now and l_inter1<l_inter2:
                    gool=interpoint_1
                elif l_inter2<l_now and l_inter2<l_inter1:
                    gool=interpoint_2
                else:
                    gool=idx_i_1
            elif (minX<=interpoint_1[0]<=maxX and minY<=interpoint_1[1]<=maxY):
                #交点１のみ有効
                if l_inter1<l_now:
                    gool=interpoint_1
                else:
                    gool=idx_i_1
            elif (minX<=interpoint_2[0]<=maxX and minY<=interpoint_2[1]<=maxY):
                #交点２のみ
                if l_inter2<l_now:
                    gool=interpoint_2
                else:
                    gool=idx_i_1
            else:
                gool=idx_i_1
        
        elif lam == 0:
            interpoint=[(D*dy)/(d_r**2),(-D*dx)/(d_r**2)]
            l_now=self.dis_comp(idx_i_1[0],idx_i_1[1],0,0)
            l_inter=self.dis_comp(idx_i_1[0],idx_i_1[0],interpoint[0],interpoint[1])
            #交点一つが有効な時
            if minX<=interpoint[0]<=maxX and minY<=interpoint[1]<=maxY:
                if(l_now>l_inter):
                    gool=interpoint
                else:
                    gool=idx_i_1
            else:
                gool=idx_i_1
        
        else:#交点０
            gool = idx_i_1
        
        gool[0]+=p_now[0]
        gool[1]+=p_now[1]
        return gool

            
def main(args=None):
    rclpy.init(args=args)
    node = StateMachine()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()