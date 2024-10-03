// Define segment pins
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int dp = 9;

// Array of segment patterns for digits 0-9
const byte numPatterns[10] = {
  0b00000000, // 0
  0b01111001, // 1
  0b00100100, // 2
  0b00110000, // 3
  0b00011001, // 4
  0b00010010, // 5
  0b00000010, // 6
  0b01111000, // 7
  0b00000000, // 8
  0b01100000, // 9
};

void setup() {
  // Set all segment pins as output
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1000); // Wait 1 second before changing number
  }
  for (int i = 9; i >= 0; i--) {
    displayNumber(i);
    delay(1000); // Wait 1 second before changing number
  }
}

void displayNumber(int num) {
  byte pattern = numPatterns[num];

  digitalWrite(a, pattern & 0b00000001);
  digitalWrite(b, pattern & 0b00000010);
  digitalWrite(c, pattern & 0b00000100);
  digitalWrite(d, pattern & 0b00001000);
  digitalWrite(e, pattern & 0b00010000);
  digitalWrite(f, pattern & 0b00100000);
  digitalWrite(g, pattern & 0b01000000);
}
