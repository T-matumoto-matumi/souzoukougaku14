#include "WiFiS3.h"

const char* SSID = "cafe_14";
const char* PASS = "123456789";
const char* UDPADRESS = "192.168.1.100";//pc ip
const unsigned int arduino_Port = 5005;    //arduino のport
const unsigned int pc_Port = 4004;    //pcのport


// 固定IPアドレス、サブネットマスク、ゲートウェイの設定
IPAddress localIP(192, 168, 4, 1);        // アクセスポイントのIP
IPAddress gateway(192, 168, 4, 1);        // ゲートウェイのIP（通常はアクセスポイントと同じ）
IPAddress subnet(255, 255, 255, 0);       // サブネットマスク

WiFiUDP udp;

int intArray[5] = {1, 2, 3, 4, 5}; // 送信するint型配列
int responseArray[5];               // 応答を格納する配列
size_t arraySize = sizeof(intArray) / sizeof(intArray[0]);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // アクセスポイントの固定IPアドレスを設定
  WiFi.config(localIP, gateway, subnet);

  uint8_t status = WiFi.beginAP(SSID,PASS);
  while (status != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  udp.begin(arduino_Port);
  Serial.println("arduino ip;");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // sousinn
  udp.beginPacket(UDPADRESS, pc_Port);
  udp.write((uint8_t*)intArray, sizeof(intArray)); // 配列をバイト列として送信
  udp.endPacket();
  Serial.println("Data sent to Python");

  // 受信（もしデータがある場合）
  int packetSize = udp.parsePacket();//パケットのサイズを受け取る
  if(packetSize>0){
    udp.read((unsigned char*)responseArray, sizeof(responseArray)); // 応答を受信
    for (int i = 0; i < arraySize; i++) {
      Serial.print(responseArray[i]);
      Serial.print(" ");
    }
    Serial.println();
  } 

}
