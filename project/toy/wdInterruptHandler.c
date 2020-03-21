#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  if (++blink_count == 120){//counter used to set periodic interrupts
    state_advance();
    blink_count = 0;
  }
  
}
