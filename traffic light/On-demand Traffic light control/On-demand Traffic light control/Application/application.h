/*
 * application.h
 *
 * Created: 2/8/2023 7:23:09 PM
 *  Author: Mohamed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/interrupt/interrupts.h"


void APP_init(void);
void APP_start(void);
#define delay TIMER_delay(485); 
#define Normal 1

#define PED_STRAIN 0
 
#define GREEN 0

#define RED 1

#define  YELLOW 2

#define R_PED_ON  LED_on(PED_PORT,PED_R_PIN);

#define R_PED_OFF  LED_off(PED_PORT,PED_R_PIN);

#define Y_PED_ON   LED_on(PED_PORT,PED_Y_PIN);

#define Y_PED_OFF  LED_off(PED_PORT,PED_Y_PIN);

#define G_PED_ON  LED_on(PED_PORT,PED_G_PIN);

#define G_PED_OFF LED_off(PED_PORT,PED_G_PIN);

#define G_CAR_ON LED_on(CAR_PORT,CAR_G_PIN);

#define Y_CAR_ON LED_on(CAR_PORT,CAR_Y_PIN);

#define R_CAR_ON LED_on(CAR_PORT,CAR_R_PIN);

#define G_CAR_OFF LED_off(CAR_PORT,CAR_G_PIN);

#define Y_CAR_OFF LED_off(CAR_PORT,CAR_Y_PIN);

#define R_CAR_OFF LED_off(CAR_PORT,CAR_R_PIN);



#endif /* APPLICATION_H_ */