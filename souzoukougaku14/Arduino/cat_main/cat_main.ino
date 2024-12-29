#include "WiFiS3.h"
#include "math.h"


const char* SSID = "cafe_14";      // Wi-FiのSSID
const char* PASS = "123456789";    // Wi-Fiのパスワード
const int PORT = 8080;             // ポート番号
byte IP[] = {192,48,56,1};
int status = WL_IDLE_STATUS;
WiFiServer server(PORT);

//encoder
const int ref = 32;
volatile int count_right=0;
volatile int count_left=0;
const int PHASE_A_right=1;
const int PHASE_B_right=0;
const int PHASE_A_left=8;
const int PHASE_B_left=7;

// 通信用のint配列
const int arraySize = 5;
int dataArray[arraySize];
int dataArray_send[5]={1,2,3,4,5};

// 自己位置
//x,y,yaw
float pose[3]={0.0f,0.0f,0.0f};
//速度
//vel_x,vel_y,vel_yaw
float vel[3]={0.0f,0.0f,0.0f};
//角速度
//vel_right,vel_left
float vel_now[2]={0.0f,0.0f};
int count_before[2]={0,0};

//timer 0.1周期
float timer_period = 1.f;

void read_msg(){
  WiFiClient client = server.available();
  if (!client) {
    Serial.println(":::errer:::   No client");
    return;
  }else{
  //ここに受信処理を書く
    while (client.available() < 1){
      Serial.println("wait");
    };//データが来るまでまつ
    uint8_t startByte = client.read();

    if (startByte != 0xAA) {
      //スタートバイトがずれていたとき
      Serial.println(":::errer:::   Invalid start byte");
      //ここでスタートバイトがずれたときに動かなくなっている可能性あり。
      client.stop();
      return;
    }
    // int配列を受信
    while (client.available() < arraySize * sizeof(int));
    client.readBytes((char*)dataArray, arraySize * sizeof(int));

    // 受信データの表示
    Serial.println(":info:   Received int data");
    for (int i = 0; i < arraySize; i++) {
      Serial.println(dataArray[i]);
    }
  }

  if (!client.connected()) {
    Serial.println(":info:   Client disconnected");
    client.stop();  //接続が切れてたらクライアントを終了
    return;
  }

  if (client.available() <= 0) {
    Serial.println(":info:   data not coming");  // データが来なかったらなにもしない
  }
}


//モーターのクラス
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
      };
    };
};
//足回りの宣言
MOTOR motor_right(4,5,6);
MOTOR motor_left(7,8,9);




void setup() {
  count_right = 0;
  count_left = 0;
  Serial.begin(9600);
}



void loop() {
  //read_msg();
  // motor_right.setpower(dataArray[0]);
  // motor_left.setpower(dataArray[1]);
  motor_right.setpower(200);
  motor_left.setpower(200);

}



void wifi_setup(){
  // Wi-Fiネットワークを起動
  WiFi.beginAP(SSID, PASS);
  Serial.println(":info:   Access Point Started");
  // サーバーの開始
  server.begin();
  while(WiFi.status()!=WL_AP_CONNECTED){
    Serial.println(":::errer:::   No device connected");
    delay(1000);
  }
  Serial.println(":info:   Device connected!");
}

void send_msg(){
  WiFiClient client = server.available();
  if(client){
    size_t dataSize = sizeof(dataArray_send) / sizeof(dataArray_send[0]);
    // int配列をバイナリで送信
    client.write(0xAA);
    client.write((uint8_t*)&dataArray_send, dataSize * sizeof(int));
    Serial.println(":info:   Send int data");
  }
  if (!client.connected()) {
    Serial.println(":info:   Client disconnected");
    client.stop();  //接続が切れてたらクライアントを終了
    return;
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


void step(){
  //r:車輪の半径[mm]　L:車輪の幅[mm]
  float r = 15;
  float L = 105;

  //はじめに角速度の計算
  vel_now[0] = (float(count_right-count_before[0]))*M_PI*2/float(ref);
  vel_now[1] = (float(count_left-count_before[1]))*M_PI*2/float(ref);

  //速度の計算
  vel[0]=(float(cos(pose[2])))*r/2*(vel_now[0]+vel_now[1]);
  vel[1]=(float(sin(pose[2])))*r/2*(vel_now[0]+vel_now[1]);
  vel[2]=(r/L)*(vel_now[0]-vel_now[1]);

  //積算
  pose[0]+=vel[0]*timer_period;
  pose[1]+=vel[1]*timer_period;
  pose[2]+=vel[2]*timer_period;
  
  //更新
  count_before[0] = count_right;
  count_before[1] = count_left;

  dataArray_send[0]=int(pose[0]);
  dataArray_send[1]=int(pose[1]);
  dataArray_send[2]=int(pose[2]);
}
