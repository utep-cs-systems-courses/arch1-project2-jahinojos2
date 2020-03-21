#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

void main(void){//initiates the whole msp430 to what it will be using
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();

  
  or_sr(0x18);
}
