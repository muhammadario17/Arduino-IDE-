//int a=2;
//int b=3;
//int c=4;
//int d=5;
//int e=6;
//int f=7;
int pinPot = A0;
int led[] = {2, 3, 4, 5, 6, 7};
int buzzer = 8;

void setup() {
  //pinMode(a, OUTPUT);
  //pinMode(b, OUTPUT);
  //pinMode(c, OUTPUT);
  //pinMode(d, OUTPUT);
  //pinMode(e, OUTPUT);
  //pinMode(f, OUTPUT);
  pinMode(pinPot, INPUT);
  
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }

  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); 

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(pinPot);
  int potVal = map(pot, 0, 1023, 0, 255);
  if(potVal<101){
    //digitalWrite(a, HIGH);
    //digitalWrite(b, HIGH);
    //digitalWrite(c, LOW);
    //digitalWrite(d, LOW);
    //digitalWrite(e, LOW);
    //digitalWrite(f, LOW);
    //digitalWrite(buzzer, LOW);
    digitalWrite(led[0], HIGH);
    digitalWrite(led[1], HIGH);
  }
  else if(potVal<201) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  Serial.println(potVal);
  delay(100);
}