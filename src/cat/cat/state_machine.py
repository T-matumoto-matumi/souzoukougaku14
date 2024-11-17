import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat
from geometry_msgs.msg import Twist
from enum import Enum


L_WIDTH = 10 #robot width [mm]
R_WHEEL = 5/2 #robot radius [mm]

class MachineState(Enum):
    manual_mode = 1
    auto_mode = 2



class StateMachine(Node):
    def __init__(self):
        super().__init__("state_machine")
        self.joy_sub = self.create_subscription(
            JoyCat,"joy_cat",self.joy_callback,10
        )
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.robot_state = MachineState.manual_mode
        #defult mamual mode
        self.joy_msg = JoyCat()
        self.vel_msg = Twist()
        self.vel_pub = self.create_publisher(
            Twist,"cmd_vel",10
        )
        
    def joy_callback(self,msg):
        self.joy_msg = msg
        
    def timer_callback(self):
        if self.robot_state == MachineState.manual_mode:
            self.vel_msg.linear.x=self.joy_msg.x
            self.vel_msg.angular.z=self.joy_msg.yaw
            self.vel_pub.publish(self.vel_msg)
            
        elif self.robot_state == MachineState.auto_mode:
            #`kokoni auto mode kaku
            pass
        

            
def main(args=None):
    rclpy.init(args=args)
    node = StateMachine()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()