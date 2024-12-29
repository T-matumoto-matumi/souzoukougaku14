import serial
import struct
import time

# Arduinoのシリアルポートに合わせて設定
arduino_port = "/dev/ttyACM0"  # Windowsの場合
baud_rate = 9600       # Arduino側のボーレートと一致させます
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # 接続が確立するまで待機

# 送信するfloat配列
float_array = [1.23, 4.56, 7.89, 12.34, 56.78]

try:
    # スタートバイトを送信
    ser.write(b'\xFF')
    
    # 配列のサイズを送信
    ser.write(struct.pack('B', len(float_array)))
    
    # 各float値をバイナリで送信
    for value in float_array:
        ser.write(struct.pack('<f', value))  # リトルエンディアンでfloatを送信

    print("Float array sent to Arduino.")

except Exception as e:
    print(f"Error: {e}")

finally:
    ser.close()
