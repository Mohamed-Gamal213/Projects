/*
 * led.h
 *
 * Created: 2/8/2023 7:03:01 PM
 *  Author: Mohamed
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/dio.h"

// define Car port and pins
#define CAR_PORT PORT_A
#define CAR_G_PIN PIN0
#define CAR_Y_PIN PIN1
#define CAR_R_PIN PIN2
// define ped port and pins
#define PED_PORT PORT_B
#define PED_G_PIN PIN0
#define PED_Y_PIN PIN1
#define PED_R_PIN PIN2

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);



#endif /* LED_H_ */