#define BLYNK_TEMPLATE_ID "TMPL6lApIbU0d"
#define BLYNK_TEMPLATE_NAME "pager"
#define BLYNK_AUTH_TOKEN "8CfRG2B_Xk1CjvXqX_am0PLCty7o4EEO"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "lab electronic";
char pass[] = "Labelec24!";

int gatePosition = 0;

 const int a = D2; // For displaying segment  "a"
 const int b = D3; // For displaying segment  "b"
 const int c = D4; // For displaying segment  "c"
 const int d = D5; // For displaying segment  "d"
 const int e = D6; // For displaying segment  "e"
 const int f = D7; // For displaying segment  "f"
 const int g = D8; // For displaying segment  "g"


BLYNK_WRITE(V0){
  gatePosition = param.asInt();
  sevenSegment();
}

void sevenSegment(){

  if(gatePosition == 0){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERTUTUP");
  }
  else if(gatePosition == 1){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }
  else if(gatePosition == 2){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }
  else if(gatePosition == 3){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }
  else if(gatePosition == 4){
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }
  else if(gatePosition == 5){
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }
  else if(gatePosition == 6){
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  Blynk.virtualWrite (V1, "PINTU TERBUKA");
  }

}


void setup(){
  Serial.begin(115200);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop(){
  Blynk.run();
}
