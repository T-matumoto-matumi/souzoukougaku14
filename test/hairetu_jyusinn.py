import socket
import struct

# サーバー設定
HOST = '0.0.0.0'  # 自分のIPアドレスか'0.0.0.0'で全てのインターフェースで待機
PORT = 80          # ポート番号

def main():
    # ソケットを作成
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((HOST, PORT))
        server_socket.listen()
        print(f"サーバーがポート {PORT} で待機中...")

        # クライアントからの接続を待機
        conn, addr = server_socket.accept()
        with conn:
            print(f"{addr} から接続されました")
            
            # データを受信 (20バイト: 5つの整数 * 4バイト)
            data = conn.recv(20)
            
            if len(data) == 20:
                # バイナリデータを整数配列に変換
                int_array = struct.unpack('5i', data)
                print("受信した整数配列:")
                for i in int_array:
                    print(i)
            else:
                print("受信したデータのサイズが無効です")

if __name__ == "__main__":
    main()
