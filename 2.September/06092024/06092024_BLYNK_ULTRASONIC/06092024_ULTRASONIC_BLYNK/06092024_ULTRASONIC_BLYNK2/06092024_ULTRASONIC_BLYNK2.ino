#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6EFFqBzal"
#define BLYNK_TEMPLATE_NAME "Ultrasonic 2"
#define BLYNK_AUTH_TOKEN               "JOaOmu-8XBzU65mZc7RuES4CSx_zGPeo"

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
