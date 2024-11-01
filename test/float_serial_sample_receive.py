import serial
import struct
import time

arduino_port = "/dev/ttyACM0"  # 使用しているポートに変更
baud_rate = 9600       # Arduino側のボーレートと一致
num_floats = 5         # 受信するfloatの個数
start_byte = b'\xFF'   # スタートバイトの値

# シリアル接続を開きます
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # 接続が確立するまで少し待機

try:
    while True:
        if ser.in_waiting > 0:
            # スタートバイトを検出するまで待機
            if ser.read(1) == start_byte:
                # スタートバイトの後のデータを読み込み
                data = ser.read(num_floats * 4)
                
                # バイナリデータをfloat型に変換
                if len(data) == num_floats * 4:
                    float_values = struct.unpack('f' * num_floats, data)
                    print("Received floats:", float_values)
        
        time.sleep(1)
        
except KeyboardInterrupt:
    print("通信を終了します")

finally:
    ser.close()
