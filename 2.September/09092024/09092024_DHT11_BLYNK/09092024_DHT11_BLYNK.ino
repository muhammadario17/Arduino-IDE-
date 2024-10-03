#define BLYNK_TEMPLATE_ID "TMPL63VmDuECW"
#define BLYNK_TEMPLATE_NAME "Projek1"
#define BLYNK_AUTH_TOKEN "uHRq5BhxnhvRRNyRBGiisIEy55W6r3nH"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Blynk Auth Token


// Wi-Fi Credentials
char ssid[] = "Ario";
char pass[] = "747087180A";

// Pin Definitions
#define DHTPIN D4      // Pin data dari DHT11 terhubung ke D4
#define DHTTYPE DHT11  // Tipe sensor DHT yang digunakan

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void setup(){
  Blynk.begin (BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(9600);
  timer.setInterval(2000L, sensordht11);
  dht.begin();
}


void sensordht11(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity");
  Serial.println(h);
  Serial.print("Temprature");
  Serial.println(t);

  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
}

void loop(){
  Blynk.run();
  timer.run();
}
