import socket
import struct

# サーバー設定
udp_ip = "0.0.0.0"   # すべてのインターフェースで待機
udp_port = 4004      # Arduinoで設定したpcポート番号

# ソケットの作成
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((udp_ip, udp_port))

print("Waiting for data...")

while True:
    # Arduinoからデータを受信
    data, addr = sock.recvfrom(20)  # 1024バイトまでのデータを受信
    int_array = struct.unpack('5i', data)  # int型配列をアンパック（5つの整数を仮定）

    print(f"Received array from Arduino: {int_array}")

    # 応答として同じデータを送り返す
    response = struct.pack('5i', *int_array)  # int配列をバイト列に変換
    address = ("192.168.4.1",5005)
    sock.sendto(response, address)
    print("Sent response back to Arduino")
