import socket
import time

# ESP32のアクセスポイント設定
SSID = "cafe_00"
PASSWORD = "123456789"
ESP32_IP = "192.168.4.1"  # ESP32のIPアドレス
PORT = 80

# 送信したい配列データ
data_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
data_string = ','.join(map(str, data_array)) + '\n'  # カンマで区切って文字列化し、最後に改行を追加

# ソケット接続の準備
try:
    # ソケットを作成
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((ESP32_IP, PORT))  # ESP32サーバに接続
        print("Connected to ESP32")

        # 配列データを送信
        sock.sendall(data_string.encode())
        print(f"Sent data: {data_string.strip()}")

        # 応答を待機
        response = sock.recv(1024).decode()
        print("Received from ESP32:", response)

except Exception as e:
    print("An error occurred:", e)
