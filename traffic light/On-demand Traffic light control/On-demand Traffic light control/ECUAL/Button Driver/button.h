/*
 * button.h
 *
 * Created: 2/8/2023 7:28:09 PM
 *  Author: Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"

// define Button port and pin
#define BUTTON_1_PORT PORT_D 
#define BUTTON_1_PIN PIN2


//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

//initialize button read function
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);



#endif /* BUTTON_H_ */