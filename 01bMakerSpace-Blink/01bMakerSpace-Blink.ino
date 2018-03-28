/*
  Blink Center Dice LED
*/

#include "MakerSpacePins.h"

void setup() {
  pinMode(LED1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED1, HIGH);    // turn the LED on
  delay(500);                  // wait 
  digitalWrite(LED1, LOW);     // turn the LED off
  delay(500);                  // wait
}

