#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID              "TMPL6ckryOE7w"
#define BLYNK_TEMPLATE_NAME            "ultrasonic"
#define BLYNK_AUTH_TOKEN               "jxoBjZmI1liVNLyfZ2a5ckVPtDns7x28"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] =                         "lab electronic";
char pass[] =                         "Labelec24!";

const int trigpin = D6;
const int echopin = D5;

long duration;
int distance;

BlynkTimer waktu;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  waktu.setInterval (100L, sensor);
  Blynk.begin                         (BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin (9600);
}

void sensor(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);

  duration = pulseIn (echopin, HIGH);
  distance = duration*0.034/2;
  
  Serial.println (V0, distance);
  delay(100);
}
void loop() {
  Blynk.run();
  waktu.run();
}
