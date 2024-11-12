import rclpy
from rclpy.node import Node
import socket
import struct

IP = '0.0.0.0'
PORT = 4004

# UDPソケットを作成
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((IP, PORT))

class UdpReceiveNode(Node):
    def __init__(self):
        super().__init__("udp_receive_node")
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)

        
    def timer_callback(self):
        data,addr = sock.recvfrom(20)
        # 受信したデータを解析
        self.int_array = struct.unpack('5i', data)  # float型の配列としてデータを解釈
        self.get_logger().info(f'Received Float Array:{self.int_array}')

                    
def main():
    rclpy.init()
    node = UdpReceiveNode()
    print('udp_receive_node is started...')
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()
    print("Client socket closed.")
        
if __name__ == "__main__":
    main()