#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "stateMachines_asse.h"

void state_advance(){//depending of which switch was pressed it will keep on switching on and off the led light that was set

  /*switch(x){
  case 1:
    s1_down=1;
    break;
  case 2:
    s2_down = 1;
    break;
  case 3:
    s3_down = 1;
    break;
  case 4:
    s4_down = 1;
    break;
  default:
    ;
    }*/
  
  switch_advance();
  
  switch_state_changed = 1;
  led_update();
  
}
