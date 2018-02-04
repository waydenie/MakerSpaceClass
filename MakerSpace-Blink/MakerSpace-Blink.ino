/*
  Blink with PushButton Enable
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

int toggle_LED=1;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(SW_PB,INPUT);

  Serial.begin(9600);
}

void loop() {
  if (toggle_LED == 0) {
    digitalWrite(LED1, HIGH); // turn the LED on
    delay(500);               // wait 
  }
  digitalWrite(LED1, LOW);    // turn the LED off
  delay(500);                   // wait
  toggle_LED=digitalRead(SW_PB);
}

