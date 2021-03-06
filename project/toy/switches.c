#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "libTimer.h"
#include "buzzer.h"
char s1_down, s2_down, s3_down, s4_down;
char switch_state_changed;
int x;

static char switch_update_interrupt_sense(){
  char p1val = P2IN;

  P2IES |= (p1val & SWITCHES);
  P2IES &= (p1val | ~SWITCHES);
  return p1val;
  
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();
  switch_interrupt_handler();
  led_update();
  
}

void switch_interrupt_handler(){
  char p1val = switch_update_interrupt_sense();

  s1_down = (p1val & S1) ? 0:1;
  s2_down = (p1val & S2) ? 0:1;
  s3_down = (p1val & S3) ? 0:1;
  s4_down = (p1val & S4) ? 0:1;


  if(s1_down){


    switch_state_changed = 1;
    buzzer_set_period(250);
    x = 1;
    led_update();
  }
  else if(s2_down){

    switch_state_changed = 1;
    buzzer_set_period(500);
    x = 2;
    led_update();
  }
  else if(s3_down){

    switch_state_changed = 1;
    buzzer_set_period(750);
    x = 3;
    led_update();
  }
  else if(s4_down){

    switch_state_changed = 1;
    buzzer_set_period(1000);
    x = 4;
    led_update();
    
  }else;

  
  


  
}
