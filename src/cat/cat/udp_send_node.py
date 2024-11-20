import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import socket
import struct
import math

# ESP32サーバーのIPアドレスとポート
IP = "192.168.4.1"  # ESP32のIPアドレス
PORT = 5005     # ESP32のポート番号

# 送信するint
data_array = [0, 0, 0, 0]


class UdpSendNode(Node):
    def __init__(self):
        super().__init__("udp_send_node")
        timer_period =0.05
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.sub = self.create_subscription(
            Twist,"cmd_vel",self.vel_callback,10
        )
        self.vel_x =0.0
        self.vel_w =0.0
            
        self.right = 0.0
        self.left = 0.0
        self.right_send = 0.0
        self.left_send = 0.0
        self.R = 15 #半径[mm]
        self.L = 105 #機体の幅[mm]
        self.max = 100
        
    def send_data(self,destination_ip, destination_port, data):
        # 配列をバイナリ形式で送信
        data = struct.pack(f'{len(data)}i', *data)
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as udp_socket:
            destination_address = (destination_ip, destination_port)
            # データをUDPで送信
            udp_socket.sendto(data, destination_address)
        
    def vel_callback(self,msg):
        self.vel_x = msg.linear.x
        self.vel_w = msg.angular.z
    
    def timer_callback(self):
        self.right = self.vel_x/self.R-self.vel_w*self.L/(2*self.R)
        self.left = self.vel_x/self.R+self.vel_w*self.L/(2*self.R)
        print(f"rihgt{self.right},left{self.left}")
        self.max = 100
        if self.left>self.right:
            self.left_send = 1*self.max
            self.right_send = self.right/self.left*self.max
        elif self.left<self.right:
            self.right_send=1*self.max
            self.left_send = self.left/self.right*self.max
        elif self.right==self.left and self.right!=0 and self.left!=0:
            if self.left<0:
                self.left_send = -1*self.max
                self.right_send = -1*self.max
            else:
                self.left_send = self.max
                self.right_send = self.max
        else:
            self.right_send =0
            self.left_send =0
        
        data_array[0]=int(self.right_send)
        data_array[1]=int(self.left_send)
        
        self.send_data(IP,PORT,data_array)

        
def main(args=None):
    rclpy.init(args=args)
    node = UdpSendNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()