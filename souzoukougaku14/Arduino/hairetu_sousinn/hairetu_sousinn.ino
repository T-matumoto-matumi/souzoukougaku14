#include <WiFi.h> // Wi-Fiライブラリをインクルード

const char* ssid = "YOUR_SSID";        // Wi-Fi SSID
const char* password = "YOUR_PASSWORD"; // Wi-Fiパスワード

WiFiServer server(80); // ポート80でサーバーを作成

int intArray[5] = {10, 20, 30, 40, 50}; // 例の整数配列

void setup() {
  Serial.begin(115200); // シリアル通信を開始
  WiFi.begin(ssid, password); // Wi-Fiに接続

  // 接続を待つ
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Wi-Fiに接続中...");
  }

  Serial.println("Wi-Fiに接続しました");
  server.begin(); // サーバーを開始
  Serial.println("サーバーが開始されました");
}

void loop() {
  WiFiClient client = server.available(); // クライアントが接続しているか確認

  if (client) {
    Serial.println("新しいクライアントが接続しました");
    // 整数配列を送信
    client.write((uint8_t*)&intArray, sizeof(intArray));
    client.flush();
    Serial.println("整数配列を送信しました");

    client.stop(); // 接続を閉じる
  }
}
