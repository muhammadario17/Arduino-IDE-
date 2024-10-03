#define BLYNK_TEMPLATE_ID "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME "projek666"
#define BLYNK_AUTH_TOKEN "BVWDuMdW2PtY2hj8wSSXNZvANtiXdxWf"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "lab electronic";
char pass[] = "Labelec24!";

const int re1 = D0;
const int re2 = D1;

const int b1 = D2;
const int b2 = D3;

int ree2;
int ree1;
int bb1;
int bb2;

bool ada1 = false;
bool ada2 = false;
bool awd1 = false;
bool awd2 = false;

void setup() {
  pinMode(re1, OUTPUT);
  pinMode(re2, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(9600);
}

// BLYNK_WRITE(V0) {//b1

// }

// BLYNK_WRITE(V1) {//b2

// }

// BLYNK_WRITE(V2) {//b3

// }

BLYNK_WRITE(V3) {  //re1
  ree1 = param.asInt();
}
//   if (bb1 == 1) {
//   Blynk.virtualWrite(V1, "OPEN");
//   digitalWrite(re1, HIGH);
// } else if (bb1 == 0) {
//   Blynk.virtualWrite(V1, "Closed");
//   digitalWrite(re1, LOW);
// }


BLYNK_WRITE(V4) {  //re2
  ree2 = param.asInt();
}

void loop() {
  bb2 = digitalRead(b2);
  if (bb2 == 1) {
    // Blynk.virtualWrite(V1, "OPEN");
    // digitalWrite(re1, HIGH);
    if (awd1 == false) {
      Blynk.virtualWrite(V4, HIGH);
      awd1 = true;
      awd2 = false;
      Blynk.syncVirtual(V4);
    }

    if (ree2 == 1) {
      Blynk.virtualWrite(V0, "OPEN");
      digitalWrite(re2, HIGH);
    } else {
      Blynk.virtualWrite(V0, "Closed");
      digitalWrite(re2, LOW);
    }
  } else if (bb2 == 0) {
    // Blynk.virtualWrite(V1, "Closed");
    // digitalWrite(re1, LOW);
    if (awd2 == false) {
      Blynk.virtualWrite(V4, LOW);
      awd2 = true;
      awd1 = false;
      Blynk.syncVirtual(V4);
    }

    if (ree2 == 1) {
      Blynk.virtualWrite(V0, "OPEN");
      digitalWrite(re2, HIGH);
    } else {
      Blynk.virtualWrite(V0, "Closed");
      digitalWrite(re2, LOW);
    }
  }
  //____________________
  bb1 = digitalRead(b1);
  if (bb1 == 1) {
    // Blynk.virtualWrite(V1, "OPEN");
    // digitalWrite(re1, HIGH);
    if (ada1 == false) {
      Serial.println("keadaan IF");
      Blynk.virtualWrite(V3, HIGH);
      ada1 = true;
      Serial.print("ada1");
      Serial.println(ada1);
      ada2 = false;
      Serial.print("ada2");
      Serial.println(ada2);
      Blynk.syncVirtual(V3);
    }

    if (ree1 == 1) {
      Blynk.virtualWrite(V1, "OPEN");
      digitalWrite(re1, HIGH);
    } else {
      Blynk.virtualWrite(V1, "Closed");
      digitalWrite(re1, LOW);
    }
  } else if (bb1 == 0) {
    // Blynk.virtualWrite(V1, "Closed");
    // digitalWrite(re1, LOW);
    if (ada2 == false) {
      Serial.println("keadaan ELSE");
      Blynk.virtualWrite(V3, LOW);
      ada2 = true;
      Serial.print("ada2");
      Serial.println(ada2);
      ada1 = false;
      Serial.print("ada1");
      Serial.println(ada1);
      Blynk.syncVirtual(V3);
    }

    if (ree1 == 1) {
      Blynk.virtualWrite(V1, "OPEN");
      digitalWrite(re1, HIGH);
    } else {
      Blynk.virtualWrite(V1, "Closed");
      digitalWrite(re1, LOW);
    }
  }

  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.run();
}