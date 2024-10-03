#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

unsigned long channel = 2659863;

unsigned int led1 = 1;
unsigned int led2 = 2;
unsigned int led3 = 3;
unsigned int led4 = 4;

WiFiClient client;
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2);

#define buz D5

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(buz, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(D8, 0);
  digitalWrite(D7, 0);
  digitalWrite(D6, 0);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SECRET_SSID);
  lcd.begin();
  lcd.backlight();
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  while (WiFi.status() != WL_CONNECTED) {  //Cek koneksi Wifi.
    delay(500);
    Serial.print(".");
  }
  ThingSpeak.begin(client);
}

void loop() {
  lcd.clear();
  //update data terakhir dari field Thingspeak
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  int led_2 = ThingSpeak.readFloatField(channel, led2);
  int led_3 = ThingSpeak.readFloatField(channel, led3);
  int led_4 = ThingSpeak.readFloatField(channel, led4);

  //relay2
  if (led_1 == 1) {
    lcd.setCursor(0, 0);
    lcd.print("L1 ON");
    digitalWrite(D8, 1);
    Serial.println("D8 is On..!");
    delay(100);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("L1 OFF");
    digitalWrite(D8, 0);
    Serial.println("D8 is Off..!");
    delay(100);
  }
  //led3
  if (led_2 == 1) {
    lcd.setCursor(0, 1);
    lcd.print("L2 ON");
    digitalWrite(D7, 1);
    Serial.println("D7 is On..!");
    delay(100);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("L2 OFF");
    digitalWrite(D7, 0);
    Serial.println("D7 is Off..!");
    delay(100);
  }

  //relay1
  if (led_3 == 1) {
    lcd.setCursor(10, 0);
    lcd.print("L3 ON");
    digitalWrite(D6, 1);
    Serial.println("D6 is On..!");
    delay(100);
  } else {
    lcd.setCursor(10, 0);
    lcd.print("L3 OFF");
    digitalWrite(D6, 0);
    Serial.println("D6 is Off..!");
    delay(100);
  }

  //buzzer
  if (led_4 == 1) {
    lcd.setCursor(10, 1);
    lcd.print("B  ON");
    digitalWrite(buz, 1);
    Serial.println("buz is On..!");
    delay(100);
  } else {
    lcd.setCursor(10, 1);
    lcd.print("B  OFF");
    digitalWrite(buz, 0);
    Serial.println("buz is Off..!");
    delay(100);
  }
  delay(500);
}