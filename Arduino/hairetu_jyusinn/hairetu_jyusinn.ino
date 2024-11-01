#include <WiFi.h> // Wi-Fiライブラリをインクルード

const char* ssid = "YOUR_SSID";        // Wi-Fi SSID
const char* password = "YOUR_PASSWORD"; // Wi-Fiパスワード

WiFiClient client; // Wi-Fiクライアントを作成
int intArray[5];   // 受信した整数を格納する配列

void setup() {
  Serial.begin(115200); // シリアル通信を開始
  WiFi.begin(ssid, password); // Wi-Fiに接続

  // 接続を待つ
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Wi-Fiに接続中...");
  }

  Serial.println("Wi-Fiに接続しました");
  if (client.connect("SERVER_IP_ADDRESS", 80)) { // サーバーに接続
    Serial.println("サーバーに接続しました");
    client.read((uint8_t*)intArray, sizeof(intArray)); // 整数配列を読み込む
    client.stop(); // 接続を閉じる
  }
}

void loop() {
  // 受信した整数配列を表示
  for (int i = 0; i < 5; i++) {
    Serial.print("受信した整数: ");
    Serial.println(intArray[i]);
  }
  
  while (true); // ループを停止
}
