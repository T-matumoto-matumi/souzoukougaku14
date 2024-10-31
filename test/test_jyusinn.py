import socket

# ArduinoのIPアドレスとポート番号
SSID = "cafe_00"
PASSWORD = "123456789"
ESP32_IP = "192.168.4.1"  # ESP32のIPアドレス
PORT = 80

# ソケットを作成して接続
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((ESP32_IP, PORT))
    print("Connected to ESP32")
    # データを受信
    data = s.recv(1024).decode()
    print("Received data:", data)
    
    # 受信したデータをリストに変換
    data_array = [int(x) for x in data.split(',')]
    print("Array:", data_array)
