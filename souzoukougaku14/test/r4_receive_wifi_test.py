import socket
import time

# ArduinoサーバーのIPアドレスとポート番号
IP = "192.168.1.1"
PORT = 80

# ソケットを作成してサーバーに接続
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((IP, PORT))
print("Connected to Arduino")

try:
    while True:
        # データを受信
        data = client_socket.recv(1024).decode("utf-8").strip()
        
        # データが空でない場合に処理
        if data:
            # カンマ区切りの文字列を分割して配列として表示
            values = data.split(",")
            print("Received array:")
            for i, value in enumerate(values):
                print(f"Element {i}: {value}")
                
        # 1秒待機してから次の受信を開始
        time.sleep(1)

except KeyboardInterrupt:
    print("Connection closed")
finally:
    client_socket.close()
