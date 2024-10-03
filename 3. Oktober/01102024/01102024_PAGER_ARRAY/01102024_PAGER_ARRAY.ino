#define BLYNK_TEMPLATE_ID "TMPL6lApIbU0d"
#define BLYNK_TEMPLATE_NAME "pager"
#define BLYNK_AUTH_TOKEN "8CfRG2B_Xk1CjvXqX_am0PLCty7o4EEO"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "lab electronic";
char pass[] = "Labelec24!";


int segmentPins[] = { D2, D3, D4, D5, D6, D7, D8 };  // a, b, c, d, e, f, g


int gatePosition = 0;           //POSISI AWAL

byte Patterns[][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1 
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 0, 0, 0, 1 },  // 3
  { 1, 1, 0, 0, 0, 0, 0 },  // 4
  { 1, 0, 0, 0, 0, 0, 0 },  // 5
  { 0, 0, 0, 0, 0, 0, 0 }   // 6
};

const char* gateStatus[] = { "PINTU TERTUTUP", "PINTU TERTUTUP", "PINTU TERBUKA", "PINTU TERBUKA", "PINTU TERBUKA", "PINTU TERBUKA", "TERBUKA PENUH" };

//SLIDER PINTU (V0)
BLYNK_WRITE(V0) {
  gatePosition = param.asInt();
  SevenSegment();
  GateStatus();   
}

//SEVEN SEGMENT
void SevenSegment() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], Patterns[gatePosition][i]);
  }
}

//STATUS PINTU (V1)
void GateStatus() {
  Blynk.virtualWrite(V1, gateStatus[gatePosition]);
}

void setup() {
  Serial.begin(115200);


  for (int i = 0; i < 7; i++) {                    //PINMODE SEGMENT
    pinMode(segmentPins[i], OUTPUT);
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  GateStatus();
}

void loop() {
  Blynk.run();
}