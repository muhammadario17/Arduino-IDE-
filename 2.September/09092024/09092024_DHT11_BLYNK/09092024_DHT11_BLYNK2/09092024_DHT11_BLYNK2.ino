#define BLYNK_TEMPLATE_ID "TMPL61LHt7ueW"
#define BLYNK_TEMPLATE_NAME "projek666"
#define BLYNK_AUTH_TOKEN "uHRq5BhxnhvRRNyRBGiisIEy55W6r3nH"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Ario";
char pass[] = "747087180A";

#include <Wire.h>
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2);

#include <DHT.h>
#define DHTPIN D4     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

const int led = D3;
bool ledState = false;

void setup(){
  Blynk.begin (BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(9600);
  timer.setInterval(2000L, sensordht);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(led, OUTPUT);
}

void loop(){
  Blynk.run();
  timer.run();
}

void sensordht();{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity");
  Serial.println(h);
  Serial.print("Temprature");
  Serial.println(t);

  lcd.setCursor(0,0);
  lcd.print("H:");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(8,0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C:");

  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  
}

BLYNK_WRITE(V2){
  ledState = param.asInt();
  digitalWrite(led, ledState ? HIGH : LOW);

  lcd.setCursor(0,1);
  if(ledState){
    lcd.print("LED HIDUP");
  }

  else{
    lcd.print("LED MATI");
  }
}
