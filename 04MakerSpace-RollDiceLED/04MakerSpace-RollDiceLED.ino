/*
  Rolling Dice
*/

#include "MakerSpacePins.h"

void setup() {
  pinMode(LED1,     OUTPUT);
  pinMode(LED2,     OUTPUT);
  pinMode(LED3,     OUTPUT);
  pinMode(LED4,     OUTPUT);
  pinMode(LED5,     OUTPUT);
  pinMode(LED6,     OUTPUT);
  pinMode(LED7,     OUTPUT);
  pinMode(SW_PB,    INPUT);
  pinMode(ANTNOISE, INPUT);

  randomSeed(analogRead(ANTNOISE));
  Serial.begin(9600);
}

void loop() {
  int diceRoll = random(0,6);
//  Serial.println(diceRoll+1);
  for (int i=0; i<7; i++) { digitalWrite(dice_LEDs[i],LOW); }                // turn off all LEDs
  for (int i=0; i<=diceRoll; i++) { digitalWrite(dice[diceRoll][i], HIGH); } // turn on LEDs for diceRoll
  delay (1000);                                                              // ...pause... for effect
}

