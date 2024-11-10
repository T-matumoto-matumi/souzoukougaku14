import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import socket
import struct

# ESP32サーバーのIPアドレスとポート
ESP32_IP = "192.168.4.1"  # ESP32のIPアドレス
ESP32_PORT = 8080         # ESP32のポート番号

# 送信するfloat配列とスタートバイト
data_array = [1.1, 2.2, 3.3, 4.4, 5.5]
start_byte = 0xAA

class UdpNode(Node):
    def __init__(self):
        super().__init__("udp_node")
        timer_period =0.05
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.sub = self.create_subscription(
            Twist,"/cmd_vel",self.vel_callback,10
        )
        self.vel_x =0.0
        self.vel_w =0.0
        # ソケットを作成してarduinoに接続
        # arduinoへのソケット接続の初期化
        try:
            self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client_socket.connect((ESP32_IP, ESP32_PORT))
            self.get_logger().info("Connected to ESP32 server")
        except Exception as e:
            self.get_logger().error(f"Failed to connect to ESP32: {e}")
            self.client_socket = None
            rclpy.shutdown()
        self.right = 0.0
        self.left = 0.0
        self.right_send = 0.0
        self.left_send = 0.0
        self.R = 15 #半径[mm]
        self.L = 105 #機体の幅[mm]
        self.max = 100
        
        
        
    def vel_callback(self,msg):
        self.vel_x = msg.linear.x
        self.vel_w = msg.angular.z
    
    def timer_callback(self):
        self.right = self.vel_x/self.R-self.vel_w*self.L/(2*self.R)
        self.left = self.vel_x/self.R+self.vel_w*self.L/(2*self.R)
        print(f"rihgt{self.right},left{self.left}")
        if self.left>self.right:
            self.left_send = 1*self.max
            self.right_send = self.right/self.left*self.max
        elif self.left<self.right:
            self.right_send=1*self.max
            self.left_send = self.left/self.right*self.max
        elif self.right==self.left:
            self.right_send = self.max
            self.left_send = self.max
        else:
            self.right_send =0.0
            self.left_send =0.0
        
        data_array[0]=self.right_send
        data_array[1]=self.left_send
        
        
        # スタートバイトを送信
        self.client_socket.sendall(struct.pack('B', start_byte))

        # float配列をバイナリ形式で送信
        data = struct.pack(f'{len(data_array)}f', *data_array)
        self.client_socket.sendall(data)

        
def main(args=None):
    rclpy.init(args=args)
    node = UdpNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()