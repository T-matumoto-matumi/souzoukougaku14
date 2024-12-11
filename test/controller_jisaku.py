import socket
import struct
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy

# サーバー設定
udp_ip = "127.0.0.1"   # すべてのインターフェースで待機
udp_port = 3333      # Arduinoで設定したpcポート番号

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
joy_msg.buttons = [0] * 4  # ボタン用の4個の整数配列
joy_msg.axes = [0.0] * 4    # 軸用の6個の浮動小数点数配列

while True:
    # Arduinoからデータを受信
    data, addr = sock.recvfrom(32)  # 32バイトまでのデータを受信
    float_array = struct.unpack('8f', data)  # float型配列をアンパック
    
    print(f"float array: {float_array}")
    for i in range(4,7):
        joy_msg.buttons[i]=int(float_array[i])
        
    for i in range(0,3):
        joy_msg.axes[i]=float(float_array[i])
    pub.publish(joy_msg)