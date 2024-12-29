import rclpy
from rclpy.node import Node
from cat_messages.msg import JoyCat

class PcController(Node):
    def __init__(self):
        super().__init__("pc_controller")
        self.pub = self.create_publisher(
            JoyCat,"joy_cat",10
        )
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.vel_x =0.0
        self.vel_yaw =0.0
        self.upper_state=0
        self.grab_state=0
        

    
    def timer_callback(self):
        key = input("w:forward\na:left\nd:right\ns:back <<")
        print(f"key={key}")
        if key=="w":
            self.vel_x+=0.1
        elif key=="s":
            self.vel_x-=0.1
        elif key=="d":
            self.vel_yaw-=0.1
        elif key=="a":
            self.vel_yaw+=0.1
        elif key=="u":
            self.upper_state=1
        elif key=="h":
            self.upper_state=0
        elif key=="i":
            self.grab_state=1
        elif key=="j":
            self.grab_state=0
            
            
            
        print(f"vel_x{self.vel_x},vel_yaw{self.vel_yaw}")
        msg= JoyCat()
        msg.x = self.vel_x
        msg.yaw=self.vel_yaw
        msg.button_1=bool(self.upper_state)
        msg.button_2=bool(self.grab_state)
        self.pub.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = PcController()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()