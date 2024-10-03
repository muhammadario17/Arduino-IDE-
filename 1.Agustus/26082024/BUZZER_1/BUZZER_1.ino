const int buzzerPin = 9; // Pin connected to the buzzer

// Frequencies for the melody of "Twinkle Twinkle Little Star"
int melody[] = {
  750, 500, 750, 500, 750, 500, 1200 // "Twinkle, twinkle"
};

// Durations of each note (in milliseconds)
int noteDurations[] = {
  400, 400, 400, 400, 400, 400, 800 // First line

};

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  int melodyLength = sizeof(melody) / sizeof(melody[0]); // Get the number of notes in the melody
  
  for (int i = 0; i < melodyLength; i++) {
    int duration = noteDurations[i]; // Get the duration of the current note
    tone(buzzerPin, melody[i], duration); // Play the note
    delay(duration * 1.30); // Wait for the note to finish playing
  }
  
  delay(2000); // Wait for 2 seconds before playing the melody again
}