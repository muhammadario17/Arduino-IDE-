//Seven segment push button counter
      
 const int a = D2; // For displaying segment  "a"
 const int b = D3; // For displaying segment  "b"
 const int c = D4; // For displaying segment  "c"
 const int d = D5; // For displaying segment  "d"
 const int e = D6; // For displaying segment  "e"
 const int f = D7; // For displaying segment  "f"
 const int g = D8; // For displaying segment  "g"
 const int buttonPin = 9;
 #define buzz 10

 bool bPress = false;
 
 
 //Variables will change
 int buttonPushCounter = 0;
 int buttonState = 0;
 int lastButtonState = 0;
 
 void setup()
 {
   pinMode(a,OUTPUT); // A
   pinMode(b,OUTPUT); // B
   pinMode(c,OUTPUT); // C
   pinMode(d,OUTPUT); // D
   pinMode(e,OUTPUT); // E
   pinMode(f,OUTPUT); // F
   pinMode(g,OUTPUT); // G
   pinMode(buzz, OUTPUT);


   pinMode(buttonPin,INPUT_PULLUP);
   Serial.begin(9600);
   displayDigit(buttonPushCounter);
 }
 
 void loop()
 {
   buttonState = digitalRead(buttonPin);
   
   //compare the buttonState to its revious state
   if(buttonState != lastButtonState)
   {
     //if the state has changed,increment the counter
     if(buttonState == LOW){
       //if the current state is HIGH then the button went from off to on
       bPress = true;
       buttonPushCounter++;
       if(buttonPushCounter>9) buttonPushCounter = 0;
       Serial.println("1");

      tone(buzz, 1000); // Play a 1kHz tone
      delay(50); // Duration of the tone
      noTone(buzz); // Stop the tone
     }
     else{
       //if the current state is LOW then the button went from on to off
       Serial.println("0");
     }
     //Delay a little bit to avoid bouncing
     delay(1);
   }
   //save the current state as the last state,for ext time through the loop
   lastButtonState = buttonState;
   
   if(bPress ){
     turnoff();
     displayDigit(buttonPushCounter);
   }
 }
 
 void displayDigit(int digit)
 {
   //condition for displaying segment a
   if(digit != 1 && digit !=4)
   digitalWrite(a,LOW);
   
   //condition for displaying segment b
   if(digit != 5  && digit != 6)
   digitalWrite(b,LOW);
   
   //condition for displaying segment c
   if(digit != 2)
   digitalWrite(c,LOW);
   
   //condition for displaying segment d
   if(digit != 1 && digit !=4 && digit != 7)
   digitalWrite(d,LOW);
   
   //condition for displaying segment e
   if(digit == 2 || digit ==6 || digit ==8 || digit == 0)
   digitalWrite(e,LOW);
   
   //condition for displaying segment f
   if(digit != 1 && digit !=2 && digit != 3 && digit != 7)
   digitalWrite(f,LOW);
   
   //condition for displaying segment g
   if(digit != 0 && digit !=1 && digit!= 7)
   digitalWrite(g,LOW);
 }
 
 void turnoff()
 {
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
 }