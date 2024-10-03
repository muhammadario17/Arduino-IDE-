const int ldr = A0;
int nilaiADC;
#define led 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
 // Jika terkena cahaya akan redup dengan perlahan (2 kondisi)
 //int ldr1 = analogRead(ldr);
 //int fade =map(ldr1, 0, 1025, 0, 100);
 //Serial.println(ldr1);
 //analogWrite(led, ldr1);
 //delay(500);
 
  // jika dalam kondisi redup akan menyalakan lampu (2 kondisi)
  nilaiADC = analogRead(ldr);
  int fade = map(nilaiADC, 0, 1025, 0, 100);
  Serial.print("Nilai ADC: ");
  Serial.println(fade);
  delay(500);


  if(fade < 20){
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}