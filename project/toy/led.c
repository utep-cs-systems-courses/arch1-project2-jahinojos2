#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "libTimer.h"

unsigned char green = 0, red = 0; 
static char redVal[] = {0, LED_RED}, greenVal[] = {LED_GREEN, 0};

void led_init(){
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if(switch_state_changed){
    char ledFlags = 0;
    if(s1_down){ 
      ledFlags |= s1_down ? LED_RED: 1;
      
    }
    else if(s2_down){
      ledFlags |= s2_down ? LED_GREEN:1;
    }
    else if(s3_down){
      ledFlags |= s3_down ? LED_GREEN:1;
      ledFlags |= s3_down ? LED_RED:1;
    }
    P1OUT &= (0xff - LEDS);
    P1OUT |= ledFlags;
    
  }
  switch_state_changed = 0;
}
