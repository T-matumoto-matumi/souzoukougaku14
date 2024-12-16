#include "WiFiS3.h"
#include "math.h"
#include "CBTimer.h"
// 前回のタイマー処理実行時刻を記録
// unsigned long previousMillis = 0;
// const unsigned long interval = 10; // 1ms の間隔
// // float timer_period =0.0;
WiFiUDP udp;
// 送信するfloat型配列
//l,
float send_array[1] = {0.0};

int senser_array[4] = {1, 2, 3, 4}; //sener
//受信するは配列
//right,left,reset,up_down,grap
int receive_array[5] = {0,0,0,0,0};               //receive

//encoder
const int PHASE_A_right=0;
const int PHASE_B_right=1;
const int PHASE_A_left=2;
const int PHASE_B_left=3;

// 自己位置
//l
volatile float l =0.0;
//速度
//vel_x,vel_y,vel_yaw
volatile float vel_l = 0.0;
volatile float vel_before_l =0.0;
//角速度
//vel_right,vel_left
volatile float vel_wheel[2]={0.0f,0.0f};//right,left
volatile int count_before[2]={0,0};//right.left
volatile int count_after[2]={0,0};//right,left
//timer
int timer_period=1;//ms


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
        analogWrite(PWMA,0);
      };
    };
};

MOTOR motor_right(8,9,10);
MOTOR motor_left(4,7,5);

volatile int count=0; 

void callback(void){
  step();
}


void setup(){
  Serial.begin(115200);
  wifi_setup();
  pinMode(0,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PHASE_A_right),A_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_right),B_CHANGE_RIGHT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_A_left),A_CHANGE_LEFT,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PHASE_B_left),B_CHANGE_LEFT,CHANGE);
  static CBTimer timer;
  if(timer.begin(timer_period,callback,false)!=true){
    Serial.println("no timer");
  }else{
    timer.start();
  }
}

void loop(){

  receive();
  //初期化処理
  if (receive_array[2]==1){
    l = 0.0;
  }
  //現在地送信
  send_array[0]=l;
  send();
  motor_right.setpower( receive_array[0]);
  motor_left.setpower( receive_array[1]);
  //unsigned long currentMillis = millis();
  // 一定時間が経過した場合に step を実行
  // if (currentMillis - previousMillis >= interval) {
  //   timer_period = float(currentMillis - previousMillis);
  //   previousMillis = currentMillis; // 実行時刻を更新
  //   step(timer_period); // タイマーの処理

  // }
}

void wifi_setup(){
  const char* SSID = "cafe_14";
  const char* PASS = "123456789";
  const unsigned int arduino_Port = 5005; 
  // 固定IPアドレス、サブネットマスク、ゲートウェイの設定
  IPAddress localIP(192, 168, 4, 1);        // アクセスポイントのIP
  IPAddress gateway(192, 168, 4, 1);        // ゲートウェイのIP（通常はアクセスポイントと同じ）
  IPAddress subnet(255, 255, 255, 0);       // サブネットマスク
  // アクセスポイントの固定IPアドレスを設定
  WiFi.config(localIP, gateway, subnet);
  uint8_t status = WiFi.beginAP(SSID,PASS);
  if(status){
    Serial.println("アクセスポイントモードでWiFiを開始しました");
  }else{
    Serial.println("WiFiの開始に失敗しました");
  }
  Serial.println("Connected to WiFi");
  Serial.println("arduino ip;");
  Serial.println(WiFi.softAPIP());
  udp.begin(arduino_Port);
}

void send(){
  const char* PC_IP = "192.168.4.2";//pc ip
  const unsigned int PC_PORT = 4004;//pcのport
  udp.beginPacket(PC_IP, PC_PORT);
  // 配列をバイト列として送信
  udp.write((uint8_t*)send_array, sizeof(send_array));
  udp.write((uint8_t*)senser_array, sizeof(senser_array));
  udp.endPacket();
  //Serial.println("Data sent to Python");
}

void receive(){
  int packetSize = udp.parsePacket();//パケットのサイズを受け取る
  if(packetSize==16){
    udp.read((unsigned char*)receive_array, sizeof(receive_array)); // 応答を受信
    for (int i = 0; i < (sizeof(receive_array) / sizeof(receive_array[0])); i++) {
      Serial.print(receive_array[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

void step(){
  //r:車輪の半径[mm]　L:車輪の幅[mm] timer_period[ms]
  float r = 15;
  float L = 110;
  float ref = 32;
  //角速度
  vel_wheel[0] = (float(count_after[0]-count_before[0]))*M_PI*2/ref;
  vel_wheel[1] = (float(count_after[1]-count_before[1]))*M_PI*2/ref;
  //速度
  vel_l =r/2*(vel_wheel[0]+vel_wheel[1]);
  //積算(台形積分)
  l+=0.5*(vel_l+vel_before_l);//[mm/ms]*[ms]=>[mm]
  //更新
  count_before[0] = count_after[0];
  count_before[1] = count_after[1];
  vel_before_l = vel_l;

  
}

void A_CHANGE_RIGHT(){
  if(digitalRead(PHASE_A_right)==HIGH){
    if (digitalRead(PHASE_B_right) == HIGH){
      count_after[0]--;
    }
    else{
      count_after[0]++;
    }
  }
  else{
    if(digitalRead(PHASE_B_right)==HIGH){
      count_after[0]++;
    }
    else{
      count_after[0]--;
    }
  }
  
}

void B_CHANGE_RIGHT(){
  if(digitalRead(PHASE_B_right)==HIGH){
    if (digitalRead(PHASE_A_right) == HIGH){
      count_after[0]++;
    }
    else{
      count_after[0]--;
    }
  }
  else{
    if(digitalRead(PHASE_A_right)==HIGH){
      count_after[0]--;
    }
    else{
      count_after[0]++;
    }
  }
}

void A_CHANGE_LEFT(){
  if(digitalRead(PHASE_A_left)==HIGH){
    if (digitalRead(PHASE_B_left) == HIGH){
      count_after[1]--;
    }
    else{
      count_after[1]++;
    }
  }
  else{
    if(digitalRead(PHASE_B_left)==HIGH){
      count_after[1]++;
    }
    else{
      count_after[1]--;
    }
  }
}

void B_CHANGE_LEFT(){
  if(digitalRead(PHASE_B_left)==HIGH){
    if (digitalRead(PHASE_A_left) == HIGH){
      count_after[1]++;
    }
    else{
      count_after[1]--;
    }
  }
  else{
    if(digitalRead(PHASE_A_left)==HIGH){
      count_after[1]--;
    }
    else{
      count_after[1]++;
    }
  }
}
