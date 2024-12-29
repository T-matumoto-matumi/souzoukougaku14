import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import socket
import struct
# サーバー設定
udp_ip = "127.0.0.1"   # すべてのインターフェースで待機
udp_port = 4004      # windowsで設定したpcポート番号
# 送信するint button
int_array = [0]*15
# 送信するfloat axis
float_array = [0.0]*6
# ソケットの作成
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((udp_ip, udp_port))

print("Waiting for data...")

class JoyNode(Node):
    def __init__(self):
        super().__init__("ps4_joy_node")
        self.joy_pub = self.create_publisher(
            Joy,"joy",10
        )
        self.joy_msg = Joy()
        timer_period =0.01
        self.timer = self.create_timer(timer_period,self.timer_callback)
        # 配列サイズを事前に確保
        self.joy_msg.buttons = [0] * 15  # ボタン用の15個の整数配列
        self.joy_msg.axes = [0.0] * 6    # 軸用の6個の浮動小数点数配列

        
    def timer_callback(self):
        # winからデータを受信
        data, addr = sock.recvfrom(84)  # 84バイトまでのデータを受信
        int_array = struct.unpack('15i', data[:60])  # int型配列をアンパック（15つの整数を仮定）
        float_array = struct.unpack('6f',data[60:])
    
        #print(f"button array: {int_array}")
        #print(f"button array: {float_array}")
        
        for i in range(0,15):
            self.joy_msg.buttons[i]=int_array[i]
        for i in range(0,6):
            self.joy_msg.axes[i]=float_array[i]
        
        self.joy_pub.publish(self.joy_msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = JoyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
        