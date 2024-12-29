import socket
import struct

# ESP32サーバーのIPアドレスとポート
ESP32_IP = "192.168.4.1"  # ESP32のIPアドレス
ESP32_PORT = 8080         # ESP32のポート番号

# 送信するfloat配列とスタートバイト
data_array = [1, 2, 3, 4, 5]
start_byte = 0xAA

# ソケットを作成してESP32に接続
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((ESP32_IP, ESP32_PORT))
print("Connected to ESP32 server")

# スタートバイトを送信
client_socket.sendall(struct.pack('B', start_byte))

# float配列をバイナリ形式で送信
data = struct.pack(f'{len(data_array)}i', *data_array)
client_socket.sendall(data)

# ソケットを閉じる
client_socket.close()
print("Data sent and connection closed")
