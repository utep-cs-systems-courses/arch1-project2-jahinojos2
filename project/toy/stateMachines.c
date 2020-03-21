#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"


void state_advance(){//depending of which switch was pressed it will keep on switching on and off the led light that was set

  switch_state_changed = 1;
  led_update();
  
}
