#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

void main(void){//initializes the msp430 board
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x18);
}
