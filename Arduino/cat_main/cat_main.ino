#include "WiFiS3.h"
#include "math.h"
#include "FspTimer.h"

const char* SSID = "cafe_14";      // Wi-FiのSSID
const char* PASS = "123456789";    // Wi-Fiのパスワード
const int PORT = 8080;             // ポート番号
byte IP[] = {192,48,56,1};
int status = WL_IDLE_STATUS;
WiFiServer server(PORT);
volatile int count_right;
volatile int count_left;
const int PHASE_A_right=2;
const int PHASE_B_right=4;
const int PHASE_A_left=7;
const int PHASE_B_left=8;
// int配列の要素数
const int arraySize = 5;
int dataArray[arraySize];

FspTimer _timer;

void timer_callback(timer_callback_args_t *arg){
  Serial.println("timer_callback");
}

bool timer_setup(){
  //setup ok:1 ,setup errer:0
  uint8_t type;
  int8_t ch = FspTimer::get_available_timer(type);
  if(ch<0){
    return 0;
  }else{
    _timer.begin(TIMER_MODE_PERIODIC,type,ch,1.0f,50.0f,timer_callback,nullptr);
    _timer.setup_overflow_irq();
    _timer.open();
    _timer.start();
    return 1;
  }
}
class MOTOR {
  private:
    int AIN1;
    int AIN2;
    int PWMA;
  public:
    MOTOR(int ain1,int ain2,int pwm){
      AIN1 = ain1;
      AIN2 = ain2;
      PWMA = pwm;
      pinMode(AIN1,OUTPUT);
      pinMode(AIN2,OUTPUT);
      pinMode(PWMA,OUTPUT);
    }
    //setpowerは−２５５から２５５の範囲で入力してください。
    void setpower(int power){
      if(power >= 0 && power <=255){
        digitalWrite(AIN1,HIGH);
        digitalWrite(AIN2,LOW);
        analogWrite(PWMA,power);
      }else if(power<0 && power>=-255){
        digitalWrite(AIN1,LOW);
        digitalWrite(AIN2,HIGH);
        analogWrite(PWMA,abs(power));
      }else{
        ;//errer
      }
    }
};

MOTOR motor_right(0,1,3);
MOTOR motor_left(12,13,5);

void setup() {
  attachInterrupt(digitalPinToInterrupt(PHASE_A_right),A_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_right),B_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_A_left),A_CHANGE_LEFT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_left),B_CHANGE_LEFT,CHANGE);
  count_right = 0;
  count_left = 0;
  Serial.begin(9600);
    // Wi-Fiネットワークを起動
  WiFi.beginAP(SSID, PASS);
  Serial.println("Access Point Started");
  // サーバーの開始
  server.begin();
  if(timer_setup()==0){
    Serial.println(":::errer:::no timer to use");
  }else{
    Serial.println(":info:timer_callback start");
  }
}

void loop() {
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
  //ここに受信処理を書く
    while (client.available() < 1);//データが来るまでまつ
    uint8_t startByte = client.read();

    if (startByte != 0xAA) {
      //スタートバイトがずれていたとき
      Serial.println("Invalid start byte");
      //ここでスタートバイトがずれたときに動かなくなっている可能性あり。
      //client.stop();
      return;
    }

    // float配列を受信
    while (client.available() < arraySize * sizeof(int));
    client.readBytes((char*)dataArray, arraySize * sizeof(int));

    // 受信データの表示
    Serial.println("Received int data:");
    for (int i = 0; i < arraySize; i++) {
      Serial.println(dataArray[i]);
    }
    motor_right.setpower(dataArray[0]);
    motor_left.setpower(dataArray[1]);

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

