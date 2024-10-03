#define BLYNK_TEMPLATE_ID "TMPL6ckryOE7w"
#define BLYNK_TEMPLATE_NAME "ultrasonic"
#define BLYNK_AUTH_TOKEN "jxoBjZmI1liVNLyfZ2a5ckVPtDns7x28"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>
#include <LCD_I2C.h>

#define DHTPIN D5
#define DHTTYPE DHT11

BlynkTimer timer;

LCD_I2C lcd(0x27, 16, 2);

BLYNK_WRITE(V4) {
  setPoint = param.asFloat();
  Serial.print("Set Point baru: ");
  Serial.println(setPoint);
  Blynk.virtualWrite(V4, setPoint); 
}

BLYNK_WRITE(V2) {
  systemEnabled = param.asInt(); 
  Serial.print("System Enabled: ");
  Serial.println(systemEnabled);
  Blynk.virtualWrite(V2, systemEnabled ? 1 : 0);
}

void readSensors() {
  t = dht.readTemperature();
  h = dht.readHumidity();
  Blynk.virtualWrite(V0, t); 
  Blynk.virtualWrite(V1, h); 

  if (systemEnabled) {
    if (t > setPoint) {
      digitalWrite(led, HIGH);
      ledState = true;
    } else {
      digitalWrite(led, LOW);  
      ledState = false;
    }
  } else {
    digitalWrite(led, LOW);
    ledState = false;
  }

  Blynk.virtualWrite(V3, ledState ? 1 : 0); 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("°C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:"); 
  lcd.print(t);
  lcd.print("  H:"); 
  lcd.print(h);

  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print((int)setPoint); 
  lcd.setCursor(5, 1);
  lcd.print("E:"); 
  lcd.print(systemEnabled ? "ON" : "OFF");
  lcd.setCursor(11, 1);
  lcd.print("L:"); 
  lcd.print(ledState ? "ON" : "OFF");
}

void loop() {
  Blynk.run();
  timer.run();
}