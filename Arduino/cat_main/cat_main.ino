#include "WiFiS3.h"

const char SSID[] = "cafe_999";
const char PASS[] = "123";
byte IP[] = {192,48,56,1};
int PORT = 80;
int status = WL_IDLE_STATUS;
WiFiServer server(PORT);
volatile int count_right;
volatile int count_left;
const int PHASE_A_right=2;
const int PHASE_B_right=4;
const int PHASE_A_left=7;
const int PHASE_B_left=8;





void setup() {
  attachInterrupt(digitalPinToInterrupt(PHASE_A_right),A_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_right),B_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_A_left),A_CHANGE_LEFT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_left),B_CHANGE_LEFT,CHANGE);
  count_right = 0;
  count_left = 0;
  Serial.begin(115200);
  wifi_setup();
}

void loop() {
  Serial.println(count_right);
  delay(100);
  //wifiの受信の処理
  if (WiFi.status() != WL_AP_CONNECTED) {
    Serial.println("NO DEVICE");
    return;
  }
  WiFiClient client = server.available();
  if (!client) {
    Serial.println("NO CLIENT");
    return;
  }else{
  ;//ここに受信処理を書く

  }

  if (!client.connected()) {
    Serial.println("Client disconnected");
    client.stop();  //接続が切れてたらクライアントを終了
    return;
  }

  if (client.available() <= 0) {
    Serial.println("data not coming");  // データが来なかったらなにもしない
  }
}

void A_CHANGE_RIGHT(){
  if(digitalRead(PHASE_A_right)==HIGH){
    if (digitalRead(PHASE_B_right) == HIGH){
      count_right--;
    }
    else{
      count_right++;
    }
  }
  else{
    if(digitalRead(PHASE_B_right)==HIGH){
      count_right++;
    }
    else{
      count_right--;
    }
  }
}

void B_CHANGE_RIGHT(){
  if(digitalRead(PHASE_B_right)==HIGH){
    if (digitalRead(PHASE_A_right) == HIGH){
      count_right++;
    }
    else{
      count_right--;
    }
  }
  else{
    if(digitalRead(PHASE_A_right)==HIGH){
      count_right--;
    }
    else{
      count_right++;
    }
  }
}

void A_CHANGE_LEFT(){
  if(digitalRead(PHASE_A_left)==HIGH){
    if (digitalRead(PHASE_B_left) == HIGH){
      count_left--;
    }
    else{
      count_left++;
    }
  }
  else{
    if(digitalRead(PHASE_B_left)==HIGH){
      count_left++;
    }
    else{
      count_left--;
    }
  }
}

void B_CHANGE_LEFT(){
  if(digitalRead(PHASE_B_left)==HIGH){
    if (digitalRead(PHASE_A_left) == HIGH){
      count_left++;
    }
    else{
      count_left--;
    }
  }
  else{
    if(digitalRead(PHASE_A_left)==HIGH){
      count_left--;
    }
    else{
      count_left++;
    }
  }
}

void wifi_setup() {
  WiFi.config(IPAddress(IP));
  status = WiFi.beginAP(SSID, PASS);
  if (status != WL_AP_LISTENING) {
    Serial.println(" AP failed")
  }
  server.begin();  //サーバを起動
}
