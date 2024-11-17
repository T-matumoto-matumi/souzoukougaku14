import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from cat_messages.msg import Senser
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
        self.pose_pub = self.create_publisher(
            Pose,"pose",10
        )
        self.senser_pub = self.create_publisher(
            Senser,"senser",10
        )
        self.pose_msg = Pose()
        self.senser_msg = Senser()

        
    def timer_callback(self):
        data,addr = sock.recvfrom(28)
        # 受信したデータを解析
        float_array = struct.unpack('fff',data[:12])
        int_array = struct.unpack("iiii",data[12:])
        print(f"Received Float Array: {float_array}")
        print(f"Received Int Array: {int_array}")
        self.pose_msg.position.x = float_array[0]
        self.pose_msg.position.y = float_array[1]
        self.pose_msg.orientation.z = float_array[2]
        
        self.senser_msg.senser1 = int_array[0]
        self.senser_msg.senser2 = int_array[1]
        self.senser_msg.senser3 = int_array[2]
        self.senser_msg.senser4 = int_array[3]
        
        self.pose_pub.publish(self.pose_msg)
        self.senser_pub.publish(self.senser_msg)


                    
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