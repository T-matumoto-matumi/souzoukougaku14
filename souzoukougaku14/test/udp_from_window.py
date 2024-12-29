import socket
import struct
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy

# サーバー設定
udp_ip = "127.0.0.1"   # すべてのインターフェースで待機
udp_port = 2222      # Arduinoで設定したpcポート番号

# ソケットの作成
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((udp_ip, udp_port))

print("Waiting for data...")

# ノードの初期化
rclpy.init(args=None)
node = Node("joy_node")
pub=node.create_publisher(
    Joy,"joy",10
)
joy_msg = Joy()
# 配列サイズを事前に確保
joy_msg.buttons = [0] * 15  # ボタン用の15個の整数配列
joy_msg.axes = [0.0] * 6    # 軸用の6個の浮動小数点数配列

while True:
    # Arduinoからデータを受信
    data, addr = sock.recvfrom(84)  # 1024バイトまでのデータを受信
    int_array = struct.unpack('15i', data[:60])  # int型配列をアンパック（4つの整数を仮定）
    float_array = struct.unpack('6f',data[60:])
    
    print(f"button array: {int_array}")
    print(f"button array: {float_array}")
    for i in range(0,15):
        joy_msg.buttons[i]=int_array[i]
        
    for i in range(0,6):
        joy_msg.axes[i]=float_array[i]
    pub.publish(joy_msg)

