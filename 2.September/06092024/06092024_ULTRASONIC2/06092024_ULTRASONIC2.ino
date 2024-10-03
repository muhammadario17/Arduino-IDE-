#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6EFFqBzal"
#define BLYNK_TEMPLATE_NAME "Ultrasonic 2"
#define BLYNK_AUTH_TOKEN               "JOaOmu-8XBzU65mZc7RuES4CSx_zGPeo"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <LCD_I2C.h>


LCD_I2C lcd(0x27, 16, 2);

char ssid[] =                         "lab electronic";
char pass[] =                         "Labelec24!";

const int trigpin = D6;
const int echopin = D5;

const int led1= D0;
const int led2= D3;
const int led3= D4;

long duration;
int distance;

BlynkTimer waktu;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  lcd.begin(); 
  lcd.backlight();
  
  waktu.setInterval (100L, sensor);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
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
  
  Blynk.virtualWrite (V0, distance);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print("cm");
  delay(100);

  if(distance<=100){
    digitalWrite(led1, HIGH);
    Blynk.virtualWrite(V1, HIGH);
    digitalWrite(led2, HIGH);
    Blynk.virtualWrite(V2, HIGH);
    digitalWrite(led3, HIGH);
    Blynk.virtualWrite(V3, HIGH);
  }
  else if(distance<=200){
    digitalWrite(led1, HIGH);
    Blynk.virtualWrite(V1, HIGH);
    digitalWrite(led2, HIGH);
    Blynk.virtualWrite(V2, HIGH);
    digitalWrite(led3, LOW);
    Blynk.virtualWrite(V3, LOW);
  }
    else{
      
    digitalWrite(led1, LOW);
    Blynk.virtualWrite(V1, LOW);
    digitalWrite(led2, LOW);
    Blynk.virtualWrite(V2, LOW);
    digitalWrite(led3, LOW);
    Blynk.virtualWrite(V3, LOW);
    }
  }
void loop() {
  Blynk.run();
  waktu.run();
}
