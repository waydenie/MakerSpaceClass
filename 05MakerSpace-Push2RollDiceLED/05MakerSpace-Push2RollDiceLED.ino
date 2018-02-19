/*
  Rolling Dice
*/

// Define PINs
#define ANTNOISE A0
#define SW_PB    2
#define LED1     3
#define LED2     4
#define LED3     5
#define LED4     6
#define LED5     9
#define LED6     10
#define LED7     11

static const uint8_t dice_LEDs[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7};
static const uint8_t dice[6][6] = {
  {LED1},
  {LED2,LED3},
  {LED1,LED2,LED3},
  {LED2,LED3,LED4,LED5},
  {LED1,LED2,LED3,LED4,LED5},
  {LED2,LED3,LED4,LED5,LED6,LED7}
};

int sw_pb=HIGH;

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
  sw_pb = digitalRead(SW_PB);
  if ( sw_pb == LOW ) {
    int diceRoll = random(0,6);
    for (int i=0; i<7; i++) { digitalWrite(dice_LEDs[i],LOW); }                // turn off all LEDs
    for (int i=0; i<=diceRoll; i++) { digitalWrite(dice[diceRoll][i], HIGH); } // turn on LEDs for diceRoll
  }
  delay (25);
}


