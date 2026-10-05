/*
 * dio.h
 *
 * Created: 2/8/2023 7:11:04 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"

// typedefs
// macros
// function prototypes

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#define IN 0 
#define OUT 1


#define LOW 0 
#define HIGH 1


void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); 
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); 


#endif /* DIO_H_ */