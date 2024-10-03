#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME "projek666"
#define BLYNK_AUTH_TOKEN "BkZwYQeZOZLKAIGYfIKO36WQCJMTCOok"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//PIN 
#define RELAY_PIN D0
#define SW_RELAY_PIN 1
#define SW_MODE_PIN D8
#define LED_GREEN_PIN D3
#define LED_YELLOW_PIN D4
#define LED_RED_PIN D7
#define ECHO_PIN D5
#define TRIGGER_PIN D6

//WiFi ssid and pass
char ssid[] = "lab electronic";
char pass[] = "Labelec24!"; 

BlynkTimer timer;

//Widget LED for Blynk
WidgetLED led (V2);

  //BLINK WARNA LAMPU
#define BLYNK_HIJAU "#23C48E"
#define BLYNK_KUNING "#ED9D00"
#define BLYNK_MERAH "#D3435C"

bool mode, relaystate, btnState;
int setPoint;
float waterLevel, capacity;
int sensorHeight = 45;
int tankHeight = 40;

  //BLYNK LED
BLYNK_CONNECTED(){
  led.on();
}

  //BLYNK SETPOINT V1
BLYNK_WRITE(V1){
  setPoint = param.asInt();
}

  //Ultrasonic sensor
float jarak (){
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  float duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void sensor(){

//Kapasitas Tangki (V0)
  waterLevel = sensorHeight - jarak();
  capacity = (waterLevel *100) / tankHeight;

  Blynk.virtualWrite(V0, capacity);

  //LED Notification
  if (waterLevel < 10) {
    digitalWrite(LED_GREEN_PIN, 0);
    digitalWrite(LED_YELLOW_PIN, 0);
    digitalWrite(LED_RED_PIN, 1);
    led.setColor(BLYNK_MERAH);
  } else if (waterLevel < 25) {
    digitalWrite(LED_GREEN_PIN, 0);
    digitalWrite(LED_YELLOW_PIN, 1);
    digitalWrite(LED_RED_PIN, 0);
    led.setColor(BLYNK_KUNING);
  } else{
    digitalWrite(LED_GREEN_PIN, 1);
    digitalWrite(LED_YELLOW_PIN, 0);
    digitalWrite(LED_RED_PIN, 0);
    led.setColor(BLYNK_HIJAU);
  }

  //Sync button
  if (digitalRead(SW_MODE_PIN) == HIGH) {
    if (btnState != HIGH) {
      mode = !mode;
      Blynk.virtualWrite(V3, mode);
    }
    btnState = HIGH;
  } else {
    btnState = LOW;
  }

  //Auto/Manual Mode
  if(mode){
    if(capacity < setPoint){
      relaystate =true;
    }else if(capacity >= 100){
      relaystate =false;
    }
    digitalWrite(RELAY_PIN, relaystate);
  }else {
    if (digitalRead(SW_RELAY_PIN)==0);{
    relaystate = !relaystate;  
    }
  digitalWrite(RELAY_PIN, relaystate);  
  }
}

void setup() {
  // PINMODE
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SW_MODE_PIN, INPUT);
  pinMode(SW_RELAY_PIN, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, sensor);
}

void loop() {
  //BLYNK / TIMER RUN
  Blynk.run();
  timer.run();
}
