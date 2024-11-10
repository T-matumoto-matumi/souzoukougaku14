import serial
import time

arduino_port = "/dev/ttyACM0"  # 使用しているポートに変更
baud_rate = 9600       # Arduino側のボーレートと一致
num_bytes = 5          # 受信するデータのバイト数

ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # 接続が確立するまで少し待機

try:
    while True:
        if ser.in_waiting > 0:
            start_byte = ser.read(1)  # スタートバイトを読み込む
            
            # スタートバイトが0xFFの場合、次のデータを読み込む
            if start_byte == b'\xFF':
                data = ser.read(num_bytes)
                
                if len(data) == num_bytes:
                    # データのデコードと表示
                    decoded_values = list(data)
                    print("Received data:", decoded_values)

                    # バイナリ表示
                    binary_values = [format(byte, '08b') for byte in decoded_values]
                    print("Binary data:", binary_values)
                    
        time.sleep(1)
        
except KeyboardInterrupt:
    print("通信を終了します")

finally:
    ser.close()
