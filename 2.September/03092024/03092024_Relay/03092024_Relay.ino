int pot = A0;
int relay = 3;
void setup() {
pinMode(pot, INPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

int pot1 = analogRead(pot);
int potVal = map(pot1, 0, 1023, 0,100);

if (potVal <= 50) {
digitalWrite(relay, LOW);
delay(1000);
}
else {
digitalWrite(relay, HIGH);
delay(1000);
}
Serial.println(potVal);
//digitalWrite(3, LOW);
//delay(1000);
//digitalWrite(3, HIGH);
//delay(1000);
}
