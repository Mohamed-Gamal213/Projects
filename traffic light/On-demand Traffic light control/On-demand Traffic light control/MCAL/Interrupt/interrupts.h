/*
 * interrupts.h
 *
  * Created: 2/8/2023 7:43:09 PM
  *  Author: Mohamed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../Utilities/registers.h"


#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//Enable interrupts
//start inturrpt when press button
//else error
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")


#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)


#define SETUP_INT0() GICR|=(1<<6)



#define ISR(INT_VECT) \
	void INT_VECT(void) __attribute__ ((signal,used)); \
	void INT_VECT(void)

#endif /* INTERRUPTS_H_ */