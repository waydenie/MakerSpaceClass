// Define PINs
#define ANTNOISE A0
#define SW_PB    2
#define LED1     3
#define LED2     4
#define LED3     5
#define LED4     6
#define LED5     8
#define LED6     9
#define LED7     10
#define SPK      11

static const uint8_t dice_LEDs[] = {LED1,LED2,LED3,LED4,LED5,LED6,LED7};
static const uint8_t dice[6][6] = {
  {LED1},
  {LED2,LED3},
  {LED1,LED2,LED3},
  {LED2,LED3,LED4,LED5},
  {LED1,LED2,LED3,LED4,LED5},
  {LED2,LED3,LED4,LED5,LED6,LED7}
};


