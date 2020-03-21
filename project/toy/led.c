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

void led_update(){//updates led in regards to which LED is being pushed down
  if(switch_state_changed){
    char ledFlags = 0;
    if(s1_down){//toggles the green LED on and off
      red = 0;
      if(green){
	green = 0;
	ledFlags |= s1_down ? 0:LED_RED;
      }else{
	green = 1;
	ledFlags |= s1_down ? LED_RED:1;
      }
     
    }
    else if(s2_down){//toggles the red led on and off
      if(red){
	red = 0;
	ledFlags |= s2_down ? 0:LED_GREEN;
      }else{
	red = 1;
	ledFlags|= s2_down ? LED_GREEN:1;
      }
      green = 0;
    }
    else if(s3_down){// toggles the green and red on and off at the same time
      if(green == 1 && red == 1){
	ledFlags |= s3_down ? 0:LED_GREEN;
	ledFlags |= s3_down ? 0:LED_RED;
      }else{
	ledFlags |= s3_down ? LED_GREEN:1;
	ledFlags |= s3_down ? LED_RED:1;
	green = 1;
	red = 1;
      }
    }
    else if(s4_down){
      ledFlags |= s4_down ? 0:LED_GREEN;
      ledFlags |= s4_down ? 0:LED_RED;
      green = 0;
      red = 0;
    }
    P1OUT &= (0xff - LEDS);
    P1OUT |= ledFlags;
    
  }
  switch_state_changed = 0;
}
