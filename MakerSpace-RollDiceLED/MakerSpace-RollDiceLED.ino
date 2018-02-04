/*
  Rolling Dice
*/

// Define PINs
#define SW_PB  2
#define LED1   3
#define LED2   4
#define LED3   5
#define LED4   6
#define LED5   9
#define LED6   10
#define LED7   11

static const uint8_t dice_LEDs[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7};
static const uint8_t dice[6][6] = {
  {LED1},
  {LED2,LED3},
  {LED1,LED2,LED3},
  {LED2,LED3,LED4,LED5},
  {LED1,LED2,LED3,LED4,LED5},
  {LED2,LED3,LED4,LED5,LED6,LED7}
};

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(SW_PB,  INPUT);

  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void loop() {
  int diceRoll = random(0,6);
//  Serial.println(diceRoll+1);
  for (int i=0; i<7; i++) { digitalWrite(dice_LEDs[i],LOW); }                // turn off all LEDs
  for (int i=0; i<=diceRoll; i++) { digitalWrite(dice[diceRoll][i], HIGH); } // turn on LEDs for diceRoll
  delay (1000);                                                              // ...pause... for effect
}

