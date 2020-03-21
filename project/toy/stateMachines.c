#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"



void state_advance(){//periodic interrupts to be able to switch on or off the leds
  switch_state_changed=1;
  led_update();


}
