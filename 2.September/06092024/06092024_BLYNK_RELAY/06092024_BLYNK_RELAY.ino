#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID           "TMPL6Is4H7E_o"
#define BLYNK_TEMPLATE_NAME         "Ario"
#define BLYNK_AUTH_TOKEN            "5kYIGbkJ8KwiGbsHW-x-rIh6oDAG-ZSm"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] =                       "lab electronic";
char pass[] =                       "Labelec24!";

const int led =                      D0;
const int led2 =                     D1;
#define relay                        D2

int                                  statled;
int                                  statled2;
int                                  statrelay;


void setup() {
  // put your setup code here, to run once:
  Serial.begin                       (9600);

  digitalWrite                       (led, statled);
  digitalWrite                       (led2, statled2);
  digitalWrite                       (relay, statrelay);
  
  Blynk.begin                         (BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0){

  int                                 statled = param.asInt();
  digitalWrite                        (led, statled);
}


BLYNK_WRITE(V1){

  int                                 statled2 = param.asInt();
  digitalWrite                        (led2, statled2);
}

BLYNK_WRITE(V2){

  int                                 statrelay = param.asInt();
  digitalWrite                        (relay, statrelay);
}


void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}
