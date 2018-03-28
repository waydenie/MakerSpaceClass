/*
  Cycle Through Dice LEDs
*/

#include "MakerSpacePins.h"

int cycle_LED=0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(SW_PB,  INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(dice_LEDs[cycle_LED],HIGH);              // turn on current LED in cycle
  delay(1000);                                          // wait
  digitalWrite(dice_LEDs[cycle_LED],LOW);               // turn off current LED in cycle
  cycle_LED++;
  if (cycle_LED >= 7 ) {                                // if reached end of cycle
    cycle_LED=0;                                        // reset cycle counter, and...
    delay (2000);                                       // ...pause... for effect
  }
}

