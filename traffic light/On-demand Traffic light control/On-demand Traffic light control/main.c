/*
 * On-demand Traffic light control.c
 *
 * Created: 2/8/2023 7:03:09 PM
 *  Author: Mohamed
 */ 

#include "Application/application.h"


int main(void)
{
	//Initialize
    APP_init();
	
	//Main loop
	while(1){
		APP_start();
	}
}

//testing 
//int main(void){
//BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
//LED_init(LED_CAR_PORT,LED_CAR_G_PIN); LED_init(LED_PED_PORT,LED_PED_G_PIN);
//TIMER_init();
//uint8_t value;
//while(1){
//BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&value);
//if(value==HIGH){
//LED_toggle(LED_CAR_PORT,LED_CAR_G_PIN);

//G_PED_ON
//delay
//G_PED_OFF
//delay
//
//}else{
//G_CAR_ON
//}
//


