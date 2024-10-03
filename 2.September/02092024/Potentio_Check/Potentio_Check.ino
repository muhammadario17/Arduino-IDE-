int pot = A0;
//int led1 = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(pot, INPUT);
//pinMode(led1, OUTPUT);
Serial.begin(9600);
}

void loop() { 
int pot = analogRead(pot);
int potVal = map(pot, 0, 1023, 0, 255);
//if(potVal >= 125) {
//digitalWrite(led1, HIGH);
//}
//else {
//digitalWrite(led1, LOW);
//}
Serial.println(potVal);
}
