#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6m3pGt1lm"
#define BLYNK_TEMPLATE_NAME         "DHT11"
#define BLYNK_AUTH_TOKEN            "mcNDR5mXFN6V9E1enYHQp_IpgXzoin0P"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "lab electronic";
char pass[] = "Labelec24!";

int setPoint;
int enableSwitch;

#include <LCD_I2C.h>          //LCD
LCD_I2C lcd(0x27, 16, 2);

#define DHTTYPE DHT11         //DHT11


#define DHTPIN D2
#define buzz D3               //BUZZER

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

BLYNK_WRITE(V0){ 
  //SetPoint V0
  setPoint = param.asInt();
  lcd.setCursor(0,1); lcd.print("S:"); lcd.print(setPoint);
}

BLYNK_WRITE(V1){
  //Enable Switch V1
  enableSwitch = param.asInt();
  if(enableSwitch = 1){
    lcd.setCursor(5,5); lcd.print ("ON"); lcd.print(enableSwitch);
  }
  else{
    lcd.setCursor(5,5); lcd.print ("OFF"); lcd.print(enableSwitch);
  }
}

void dht11(){

 

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)

  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);

  lcd.setCursor(0,0); lcd.print ("T:"); lcd.print(t);
  lcd.setCursor(9,0); lcd.print ("H:"); lcd.print(h);

  if(t >= setPoint && enableSwitch == 1){
    digitalWrite(buzz, HIGH);
    lcd.setCursor(11,1); lcd.print ("ON");
  }
    else{
    digitalWrite(buzz, LOW);
    lcd.setCursor(11,1); lcd.print ("OFF");
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  timer.setInterval(100L, dht11);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.backlight();
  lcd.clear();
  Blynk.run();
  timer.run();
}
