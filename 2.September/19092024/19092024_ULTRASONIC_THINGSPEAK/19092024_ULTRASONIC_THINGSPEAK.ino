#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h"
#include <LCD_I2C.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;
unsigned long channel = 2661367;

WiFiClient client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char* myWriteAPIKey = SECRET_WRITE_APIKEY;

const int trigpin = D6;
const int echopin = D5;
const int led1 = D3;
const int led2 = D4;
const int led3 = D7;

long duration;
int distance;
int number = 0;

LCD_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for Leonardo native USB port only
  }

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  WiFi.mode(WIFI_STA);

  ThingSpeak.begin(client);

  lcd.begin();
  lcd.backlight();
}


void loop() {
  // put your main code here, to run repeatedly:
  

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;

  lcd.clear();

  Serial.print("jarak= ");
  Serial.println(distance);
  Serial.print(" cm ");


  lcd.setCursor(0, 0);
  lcd.print("Jarak = ");
  lcd.print(distance);
  lcd.print("cm ");

  
  ThingSpeak.setField(1, distance);

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  if (distance > 1 && distance < 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    ThingSpeak.setField(2, HIGH);
    ThingSpeak.setField(3, LOW);
    ThingSpeak.setField(4, LOW);
    lcd.setCursor(0, 1);
    lcd.print("LED1 = ");
    lcd.print("ON");
  } else if(distance > 11 && distance < 20){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    ThingSpeak.setField(2, LOW);
    ThingSpeak.setField(3, HIGH);
    ThingSpeak.setField(4, LOW);
    lcd.setCursor(0, 1);
    lcd.print("LED2 = ");
    lcd.print("ON");
  } else if(distance > 21 && distance < 30){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    ThingSpeak.setField(2, LOW);
    ThingSpeak.setField(3, LOW);
    ThingSpeak.setField(4, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("LED3 = ");
    lcd.print("ON");
  } else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    ThingSpeak.setField(2, HIGH);
    ThingSpeak.setField(3, HIGH);
    ThingSpeak.setField(4, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("LED = ");
    lcd.print("ON");
  }
  
  delay(15000);
}
