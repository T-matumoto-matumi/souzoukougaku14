#include "CBTimer.h"

bool flag=0;

void callback(void){
  if(flag ==0 ){
  digitalWrite(LED_BUILTIN,HIGH);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }

}

void setup() {
  // put your setup code here, to run once:
  static CBTimer timer;
  timer.begin(500,callback);

}

void loop() {
  // put your main code here, to run repeatedly:
}
