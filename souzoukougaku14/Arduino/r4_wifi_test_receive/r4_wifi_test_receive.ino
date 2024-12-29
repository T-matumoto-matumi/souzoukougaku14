#include "WiFiS3.h"

const char SSID[] = "cafe_999";
const char PASS[] = "123";
byte IP[] = {192,48,56,1};
int PORT = 80;
int status = WL_IDLE_STATUS;
WiFiServer server(PORT);
int data_array[10] ={1,2,3,4,5,6,7,8,9,10};

void setup(){
    Serial.println(9600);
    wifi_setup();
}

void loop(){
  // アクセスポイントに他のデバイスがつながるのを待つ
  if (WiFi.status() != WL_AP_CONNECTED) {
    Serial.println("NO DEVICE");
    return;
  }

  //接続されているクライアントを確認
  WiFiClient client = server.available();
  if (!client) {
    Serial.println("NO CLIENT");
    return;
  }else{
    for(int i=0;i<10;i++){
      client.print(data_array[i]);
      if(i<9){
        client.print(",");
      }
    }
    client.println();
    delay(1000);
  }

  if (!client.connected()) {
    Serial.println("Client disconnected");
    client.stop();  //接続が切れてたらクライアントを終了
    return;
  }

  if (client.available() <= 0) {
    return;  // データが来なかったらなにもしない
  }
}

void wifi_setup(){
  WiFi.config(IPAddress(IP));
  status = WiFi.beginAP(SSID,PASS);
  if (status != WL_AP_LISTENING){
    Serial.println("Faild to start AP");
    while(true);
  }
  Serial.println("AP is started");
  server.begin();
}
