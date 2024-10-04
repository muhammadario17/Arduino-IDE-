#define BLYNK_PRINT Serial


/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME         "projek666"
#define BLYNK_AUTH_TOKEN            "eHrqiJak9XZlxlJJN85wT90mLSP93Kpu"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "lab electronic";
char pass[] = "Labelec24!";


#define relay1Pin  D0
#define relay2Pin  D1
#define pintu1_Pin D5
#define pintu2_Pin D6
#define pintu3_Pin D7

BlynkTimer timer;


int relay1, relay2;


BLYNK_WRITE(V0)
{
  relay1 = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(relay1Pin, relay1);
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
}


BLYNK_WRITE(V1)
{
  relay2 = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(relay2Pin, relay2);
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
}


void sendDatasensor(){
  if (digitalRead(pintu1_Pin)==1) {
    Blynk.virtualWrite(V2, "Pintu Tertutup");
    Blynk.setProperty(V2, "color", "#001F3F");
  }
    else{
    Blynk.virtualWrite(V2, "Pintu Terbuka");
    Blynk.setProperty(V2, "color", "#6A9AB0");
  }
  

  if (digitalRead(pintu2_Pin)==1) {
    Blynk.virtualWrite(V3, "Pintu Tertutup");
    Blynk.setProperty(V3, "color", "#FF6500");
  }
  
    else{
    Blynk.virtualWrite(V3, "Pintu Terbuka");
    Blynk.setProperty(V3, "color", "#FFAD60");
  }

  if (digitalRead(pintu3_Pin)==1) {
    Blynk.virtualWrite(V4, "Pintu Tertutup");
    Blynk.setProperty(V4, "color", "#73EC8B");
  }
    else{
    Blynk.virtualWrite(V4, "Pintu Terbuka");
    Blynk.setProperty(V4, "color", "#E78F81");
  }
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  pinMode(pintu1_Pin, INPUT);
  pinMode(pintu2_Pin, INPUT);
  pinMode(pintu3_Pin, INPUT);

  timer.setInterval(10L, sendDatasensor);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


void loop()
{
  Blynk.run();
  timer.run();
}