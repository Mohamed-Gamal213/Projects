/*
 * timer.c
 *
 * Created: 2/8/2023 7:73:06 PM
 *  Author: Mohamed
 */ 
#include "timer.h"
#include <math.h>


void TIMER_delay(uint16_t msec)
//timer tick
{
	uint8_t Number_over_flows; 	uint8_t Timer;
		
	uint8_t over_Flow_count=0;                       	
	
	if(msec<65.536){
		Timer = (65.536-msec)/(256.0/1000.0);
		Number_over_flows = 1;
		
	}else if(msec == 65.536){
		Timer=0;
		Number_over_flows=1;
	}else{
		Number_over_flows = ceil((double)msec/65.536);
		Timer = (1<<8) - ((double)msec/(256.0/1000.0))/Number_over_flows;
		
	}
	//start
	TCNT0 = Timer;
	TCCR0 |= (1<<2); 
	while(over_Flow_count<Number_over_flows)
	{
		
		while((TIFR &(1<<0))==0);
		
		TIFR |=(1<<0);
		
		over_Flow_count++;
	}
	//end
	TCCR0 = 0x00;
}