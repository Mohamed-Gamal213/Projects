/*
 * button.c
 *
 * Created: 2/8/2023 7:23:09 PM
 *  Author: Mohamed
 */ 
#include "button.h"

//button initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

//initialize button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}
// button high when press
//low without
//else error