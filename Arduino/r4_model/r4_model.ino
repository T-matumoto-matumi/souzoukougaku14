#include "WiFiS3.h"

const char SSID[] = "cafe_999";
const char PASS[] = "123";
byte IP[] = {192,48,56,1};
int PORT = 80;
int status = WL_IDLE_STATUS;
WiFiServer server(PORT);
int data_arrary[10] ={1,2,3,4,5,6,7,8,9,10};

void setup() {
  wifi_setup();        // start wifi
}



void wifi_setup() {
  WiFi.config(IPAddress(IP));
  status = WiFi.beginAP(SSID, PASS);
  if (status != WL_AP_LISTENING) {
    while (true) {
      LED_print(0, 1, "AP failed", SCROLL_LEFT);
    }
  }
  server.begin();  //サーバを起動
}