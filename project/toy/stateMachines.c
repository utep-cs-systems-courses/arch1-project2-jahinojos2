#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"


void state_advance(){

  switch_state_changed = 1;
  led_update();
  
}
