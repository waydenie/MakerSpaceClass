/*
  Rolling Dice
*/

#include <PCM.h>

#include "MakerSpacePins.h"
#include "MakerSpaceDiceSample.h"

int sw_pb=HIGH;
int sw_was=HIGH;

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

void RollDice(int Num, int Pause) {
  int diceRoll;
  for (int y=0; y<Num; y++) {
    diceRoll = random(0,6);
    for (int i=0; i<7; i++) { digitalWrite(dice_LEDs[i],LOW); }                // turn off all LEDs
    for (int i=0; i<=diceRoll; i++) { digitalWrite(dice[diceRoll][i], HIGH); } // turn on LEDs for diceRoll 
    delay (Pause);
  }
}

void loop() {
  sw_pb = digitalRead(SW_PB);
  if ( sw_pb == LOW ) {
    sw_was=LOW;
    RollDice(1,25);
  }
  if ((sw_pb==HIGH) && (sw_was==LOW)) {
    startPlayback(sample, sizeof(sample));
    sw_was=HIGH;
    RollDice(30,25);
  }
}


