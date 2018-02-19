/*
  Cycle Through Dice LEDs
*/

// Define PINs
#define ANT_NOISE A0
#define SW_PB     2
#define LED1      3
#define LED2      4
#define LED3      5
#define LED4      6
#define LED5      9
#define LED6      10
#define LED7      11

static const uint8_t dice_LEDs[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7};
static const uint8_t dice[6][6] = {
  {LED1},
  {LED2,LED3},
  {LED1,LED2,LED3},
  {LED2,LED3,LED4,LED5},
  {LED1,LED2,LED3,LED4,LED5},
  {LED2,LED3,LED4,LED5,LED6,LED7}
};

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

