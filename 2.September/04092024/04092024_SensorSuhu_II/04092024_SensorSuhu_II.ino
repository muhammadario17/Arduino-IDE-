#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define led1 3
#define led2 4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600); 
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop(){
  //float h = dht.readHumidity();
  float t = dht.readTemperature();

  //Serial.print("Humidity: ");
  //Serial.print(h);
  //Serial.print("%  Temperature: ");
  Serial.println(t);
  Serial.print("°C ");
  delay(500);

if(t < 26){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
}
else if(t >= 25){
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}
}

  