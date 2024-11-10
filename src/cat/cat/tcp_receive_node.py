import rclpy
from rclpy.node import Node
import socket
import struct

HOST_IP = '192,48,56,1'
PORT = 8080

class UdpReceiveNode(Node):
    def __init__(self):
        super().__init__("tcp_receive_node")
        timer_period =0.05
        self.timer = self.create_timer(timer_period,self.timer_callback)
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((HOST_IP, PORT))
        
    def timer_callback(self):
         # 最初の1バイトを受信（0xAA）
        start_byte = self.client_socket.recv(1)
        if start_byte == b'\xAA':
            data_size = 5
            received_data = []
             # 各整数（4バイト）を一つずつ受信
            for _ in range(data_size):
                data = self.client_socket.recv(4)  # 4バイトずつ受信
                if not data:
                    print("No data received. Connection may be closed.")
                    break
                # 受信した4バイトのデータをint型に変換
                value = struct.unpack('i', data)[0]  # 'i' は 4バイト整数を意味します
                received_data.append(value)

            # 受信したデータを表示
            print("Received array:", received_data)
        else:
            print("Start byte mismatch. Expected 0xAA.")
                    
def main():
    rclpy.init()
    node = UdpReceiveNode()
    print('udp_receive_node is started...')
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.client_socket.close()
    rclpy.shutdown()
    print("Client socket closed.")
        
if __name__ == "__main__":
    main()