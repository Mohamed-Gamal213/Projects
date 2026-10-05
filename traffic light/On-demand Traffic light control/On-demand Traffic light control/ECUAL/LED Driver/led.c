/*
 * led.c
 *
  * Created: 2/8/2023 7:27:09 PM
  *  Author: Mohamed
 */ 
#include "led.h"


void LED_init(uint8_t ledPort,uint8_t ledPin){
	DIO_init(ledPort,ledPin,OUT);
}
//led on
//if off error
void LED_on(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);
}
//led off
//if on error
void LED_off(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin){
	DIO_toggle(ledPort,ledPin);
}
