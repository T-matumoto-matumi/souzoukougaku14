import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat
from sensor_msgs.msg import Joy

class Ps4ControllerNode(Node):
    def __init__(self):
        super().__init__("ps4_controller_node")
        self.pub = self.create_publisher(
            JoyCat,"joy_cat",10
        )
        self.sub = self.create_subscription(
            Joy,"/joy",self.joy_callback,10
        )
        self.vel_x =0.0
        self.vel_yaw =0.0
        
        self.left_axes_0 =0.0
        self.left_axes_1 =0.0
        
    def joy_callback(self,msg):
        self.left_axes_0 = msg.axes[2]
        self.left_axes_1 = -1*msg.axes[1]    
        
        send_msg= JoyCat()
        self.vel_x = self.left_axes_1
        self.vel_yaw = self.left_axes_0
        if abs(self.left_axes_1) <= 0.05:
            self.vel_x = 0.0
            
        if abs(self.left_axes_0)<=0.05:
            self.vel_yaw = 0.0
        print(f"vel_x{self.vel_x},vel_yaw{self.vel_yaw}")
        
        send_msg.x = self.vel_x
        send_msg.yaw=self.vel_yaw
        send_msg.button_1 = bool(msg.buttons[1])
        send_msg.button_2 = bool(msg.buttons[2])
        self.pub.publish(send_msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = Ps4ControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()