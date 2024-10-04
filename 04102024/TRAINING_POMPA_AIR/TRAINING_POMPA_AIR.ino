#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME "projek666"
#define BLYNK_AUTH_TOKEN "BkZwYQeZOZLKAIGYfIKO36WQCJMTCOok"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "lab electronic";
char pass[] = "Labelec24!";

// PIN SENSOR
#define relay D0
#define sw_relay D1  //Common GND
#define sw_mode D8   //Puldown resistor
#define echo D5
#define trig D6

//LED PIN
#define red D7
#define yellow D4
#define green D3


int setPoint;
int mode;
long duration;
int distance;
int water;
bool on, off = false;

/*
NOTES: BLYNK VIRTUAL PIN 
V0 = TANGKI
V1 = MODE
V2 = NOTIF LED
V3 = SETPOINT
V4 = STATUS POMPA 
*/

#define BLYNK_HIJAU "#23C48E"
#define BLYNK_KUNING "#ED9D00"
#define BLYNK_MERAH "#D3435C"


WidgetLED led(V2);
BlynkTimer timer;


BLYNK_WRITE(V1) {
  mode = param.asInt();
}
BLYNK_WRITE(V3) {
  setPoint = param.asInt();
}

void setup() {

  // PINMODE
  pinMode(relay, OUTPUT);
  pinMode(sw_relay, INPUT);
  pinMode(sw_mode, INPUT_PULLUP);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, sensor);
  Serial.begin(9600);
}

void sensor() {

  //MODE AUTO / MANUAL BLYNK WIDGET VIEW
  if (sw_mode == 0 && on == false) {  //AUTO MODE
    Blynk.virtualWrite(V1, HIGH);
    on = true;
    off = false;
  } else if (sw_mode == 0 && off == false) {  //MANUAL MODE
    Blynk.virtualWrite(V1, LOW);
    on = false;
    off = true;
  }

  //ULTRASONIC
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0, 034 / 2;
  water = map(distance, 0, 204, 0, 100);
  Blynk.virtualWrite(V0, water);  //BLYNK WIDGET VIEW FOR ULRASONIC
}

void notif() {       //NOTIF LED
  if (water < 10) {  //HIGH WATER LVL
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(green, 1);
    Blynk.setProperty(V2, "color", "#D3435C");
  } else if (water > 10 && water <  25) {  //MIDDLE WATER LVL
    digitalWrite(red, 0);
    digitalWrite(yellow, 1);
    digitalWrite(green, 0);
    Blynk.setProperty(V2, "color", "#ED9D00");
  } else {  //LOW WATER LVL
    digitalWrite(red, 1);
    digitalWrite(yellow, 0);
    digitalWrite(green, 0);
    Blynk.setProperty(V2, "color", "#23C48E");
  }

  if (mode == 1) {     
    if (water < setPoint) {   //MODE BLYNK
      digitalWrite(relay, HIGH);
      Blynk.virtualWrite(V2, "NYALA");
    } else {
      digitalWrite(relay, LOW);
      Blynk.virtualWrite(V2, "MATI");
    }
  }
  else {
      if (sw_relay == 1) {     //MODE SWITCH
        digitalWrite(relay, HIGH);
        Blynk.virtualWrite(V2, "NYALA");
      } else {
        digitalWrite(relay, LOW);
        Blynk.virtualWrite(V2, "MATI");
      }
    }
}


void loop() {
  Blynk.run();
  timer.run();
}
