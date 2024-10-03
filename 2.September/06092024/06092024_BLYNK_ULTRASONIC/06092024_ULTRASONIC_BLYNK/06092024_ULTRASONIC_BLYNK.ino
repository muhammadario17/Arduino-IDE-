#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID              "TMPL6ckryOE7w"
#define BLYNK_TEMPLATE_NAME            "ultrasonic"
#define BLYNK_AUTH_TOKEN               "jxoBjZmI1liVNLyfZ2a5ckVPtDns7x28"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] =                         "lab electronic";
char pass[] =                         "Labelec24!";

int potentio =                         A0;
BlynkTimer                             waktu;

void setup() {
  // put your setup code here, to run once:
  
  waktu.setInterval                   (100L, nilaipot);
  Serial.begin                        (9600);
  Blynk.begin                         (BLYNK_AUTH_TOKEN, ssid, pass);
}

void nilaipot(){
  potentio = analogRead               (A0);
  int pot  = map                      (potentio, 0, 1023, 0, 100);
  Blynk.virtualWrite                  (V0, potentio);
  Blynk.virtualWrite                  (V1, pot);
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
waktu.run();
}
