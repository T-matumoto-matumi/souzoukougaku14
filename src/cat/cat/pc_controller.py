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
        self.vel_y =0.0
        self.vel_yaw =0.0

    
    def timer_callback(self):
        key = input("f:forward\na:left\nd:right\ns:back <<")
        print(f"key={key}")
        if key=="w":
            self.vel_y+=0.1
        elif key=="s":
            self.vel_y-=0.1
        elif key=="d":
            self.vel_x+=0.1
        elif key=="a":
            self.vel_x-=0.1
        print(f"vel_x{self.vel_x},vel_y{self.vel_y}")
        msg= JoyCat()
        msg.x = self.vel_x
        msg.y = self.vel_y
        self.pub.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = PcController()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()