#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "libTimer.h"
#include "buzzer.h"

char s1_down, s2_down, s3_down, s4_down;
char switch_state_changed;

static char switch_update_interrupt_sense(){//senses if swith has been pressed.
  char p1val = P2IN;

  P2IES |= (p1val & SWITCHES);
  P2IES &= (p1val | ~SWITCHES);
  return p1val;
  
}

void switch_init(){//initializes the switches
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();
  switch_interrupt_handler();
  led_update();
  
}

void switch_interrupt_handler(){//sets the switches with predetermined outcomes if pressed
  char p1val = switch_update_interrupt_sense();//senses if there has been a button pressed down

  s1_down = (p1val & S1) ? 0:1;
  s2_down = (p1val & S2) ? 0:1;
  s3_down = (p1val & S3) ? 0:1;
  s4_down = (p1val & S4) ? 0:1;


  if(s1_down){


    switch_state_changed = 1;
    
    led_update();
    buzzer_set_period(200);
  }
  else if(s2_down){

    switch_state_changed = 1;

    led_update();

    buzzer_set_period(500);
    
  }
  else if(s3_down){

    switch_state_changed = 1;

    led_update();

    buzzer_set_period(700);
    
  }
  else if(s4_down){

    switch_state_changed = 1;

    led_update();

    buzzer_set_period(1000);
  }else;

  
  


  
}
