#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init(){//initializes the speaker to the set bits in p2

  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}
void buzzer_set_period(short cycles){//sets the speaker frequency
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
