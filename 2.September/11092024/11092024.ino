 #define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME "projek666"
#define BLYNK_AUTH_TOKEN "BVWDuMdW2PtY2hj8wSSXNZvANtiXdxWf"

#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>

char ssid[] = "lab electronic";
char pass[] = "Labelec24!";

BlynkTimer timer;

const int Rly1=D1;
const int Rly2=D2;
const int Pb0=D5;
const int Pb1=D6;
const int Pb2=D7;

int tombol0, tombol1, tombol2,relay1,relay2;

void setup(){
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(Rly1, OUTPUT);
  pinMode(Rly2, OUTPUT);
  pinMode(Pb0, INPUT);
  pinMode(Pb1, INPUT);
  pinMode(Pb2, INPUT);
  timer.setInterval(100L,utama);
}

void utama(){
  tombol0=digitalRead(Pb0);
  tombol1=digitalRead(Pb1);
  tombol2=digitalRead(Pb2);

  if(tombol0==1){
    Blynk.virtualWrite (V0,1);
    Blynk.virtualWrite (V2,"TERBUKA");
  }else{
    Blynk.virtualWrite (V0,0);
    Blynk.virtualWrite (V2,"TERTUTUP");
  }

  if(tombol1==1){
    Blynk.virtualWrite (V1,1);
    Blynk.virtualWrite (V3,"TERBUKA");
  }else{
    Blynk.virtualWrite (V1,0);
    Blynk.virtualWrite (V3,"TERTUTUP");
  }

  if(tombol2==1){
    Blynk.virtualWrite (V4,"TERBUKA");
  }else{
    Blynk.virtualWrite (V4,"TERTUTUP");
  }
}

BLYNK_WRITE(V0){
  relay1=param.asInt();
  digitalWrite(Rly1,relay1);
}

BLYNK_WRITE(V1){
  relay2=param.asInt();
  digitalWrite(Rly2,relay2);
}

void loop() {
  Blynk.run();
  timer.run();
}