#ifndef led_included
#define led_included

#define LED_GREEN BIT0
#define LED_RED BIT6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();


extern unsigned char leds_change;
extern unsigned char green, red;


#endif
