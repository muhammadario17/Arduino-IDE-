void setup(){
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  bool nilaibutton1 = digitalRead(2);
  bool nilaibutton2= digitalRead(3);
  digitalWrite(4, nilaibutton1);
  digitalWrite(5, nilaibutton2);
  Serial.println(nilaibutton1);
  Serial.println(nilaibutton2);
  delay(0);
}