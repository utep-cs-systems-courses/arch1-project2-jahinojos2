#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT(){//sets a periodic counter that will interrupt the program to switch lights on and off

  static char blink_count = 0;
  if(++blink_count == 120){
    state_advance();
    blink_count=0;
  }
}
