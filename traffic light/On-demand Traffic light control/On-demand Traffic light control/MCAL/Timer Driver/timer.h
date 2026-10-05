/*
 * timer.h
 *
 * Created: 2/8/2023 7:35:30 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

//initialize
void TIMER_init();
void TIMER_delay( uint16_t msec); 


#endif /* TIMER_H_ */