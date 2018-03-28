/*
  Blink Center Dice LED
*/

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);    // turn the LED on
  delay(500);               // wait 
  digitalWrite(3, LOW);     // turn the LED off
  delay(500);               // wait
}

