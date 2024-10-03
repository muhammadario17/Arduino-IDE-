   #define led1 2
   #define led2 3
   #define led3 4
   #define led4 LED_BUILTIN
   #define buzzerPin 9

   void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
   }

   void loop() {


    digitalWrite (buzzerPin, LOW);
    digitalWrite (led1, LOW);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW);
    delay(500);

    digitalWrite (buzzerPin, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led4, LOW);
    delay(500);

    digitalWrite (buzzerPin, LOW);
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led3, HIGH);
    digitalWrite (led4, HIGH);
    delay(500);

    
    digitalWrite (buzzerPin, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led4, LOW);
    delay(500);

    digitalWrite (buzzerPin, LOW);
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, HIGH);
    delay(500);

    digitalWrite (buzzerPin, HIGH);
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led4, LOW);
    delay(2000);

   }