/*
  Blink with PushButton Enable
*/

#include "MakerSpacePins.h"

int sw_pb=HIGH;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(SW_PB,INPUT);

  Serial.begin(9600);
}

void loop() {
  if (sw_pb == LOW) {
    digitalWrite(LED1, HIGH); // turn the LED on
    delay(500);               // wait 
  }
  digitalWrite(LED1, LOW);    // turn the LED off
  delay(500);                   // wait
  sw_pb=digitalRead(SW_PB);
}

