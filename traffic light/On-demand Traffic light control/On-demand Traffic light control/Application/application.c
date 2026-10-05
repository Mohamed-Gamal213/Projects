/*
 * application.c
 *
 * Created: 2/8/2023 7:11:14 PM
 *  Author: Mohamed
 */ 
#include "application.h"
uint8_t car=0; 
uint8_t PED=1;
uint8_t Mode= 1; 
void APP_init(void){
	// LED initialization
	
	LED_init(CAR_PORT,CAR_G_PIN);	LED_init(CAR_PORT,CAR_Y_PIN);
	
	LED_init(CAR_PORT,CAR_R_PIN);	LED_init(PED_PORT,PED_G_PIN);
	
	LED_init(PED_PORT,PED_Y_PIN);	LED_init(PED_PORT,PED_R_PIN);
	
		//Button initialization
		
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	//Enable interrupts
		sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}
void APP_start(void)
{
	
	uint8_t i;
	
	//star car green ped red
	//else error
	if(Mode || car==GREEN || car==1)
	{
		
		//normal mode
		switch(car)
		{
			//car led green          ped red
			//else error
			case GREEN:
				G_CAR_ON				R_PED_ON
				
				R_CAR_OFF                G_PED_OFF
				
				for(i=0;i<50;i++)
				{
					TIMER_delay(68);
					if(!Mode)break;
				}
				
				car=1;				PED=GREEN;
				break;

			// car yellow 
			//else error
			case 1:
				
				//ped mode 
				if(!Mode)
				{
					if(PED!=2)
					{
						R_PED_ON
						
						for(i=0;i<5;i++)
						{
							Y_CAR_ON							
							
							delay
							Y_CAR_OFF							Y_PED_OFF
														
							delay
							Y_CAR_ON							Y_PED_ON
							
							
						}
					}
					PED=1;					car=2;
					
					R_CAR_ON
				}
				else{
					
					for(i=0;i<5;i++)
					{
						//yellow led blinking
						//else error
						Y_CAR_ON					
						
						delay
						Y_CAR_OFF						
						
						delay
						Y_CAR_ON						
						
						
						if(!Mode)
						{
							PED=1;
							break;
						}
					}
				}
				Y_CAR_OFF				Y_PED_OFF
				
				if(PED==0)
				{
					car=2;					PED=1;
					
				}
				else if(PED==2)
				{
					car=0;					PED=1;
					
				}
				break;
			//car red ped green
			case 2:
				G_CAR_OFF				Y_CAR_OFF
				
		    	R_PED_OFF				R_CAR_ON
								
				G_PED_ON
				for(i=0;i<50;i++)
				{
					TIMER_delay(68);
					if(!Mode)break;
				}
				PED=2;				car=1;
				
				break;
			default:
				car=2;				PED=1;
				
				break;
		}
		
	}
	else{
		
		G_PED_ON		Y_PED_OFF
		R_PED_OFF
		
		G_CAR_OFF		Y_CAR_OFF
		
		R_CAR_ON
		TIMER_delay(5000);
		
		
		
		
		for(i=0;i<5;i++)
		{
			Y_CAR_ON			Y_PED_ON
			
			delay
			Y_CAR_OFF			Y_PED_OFF
			
			delay
			Y_CAR_ON			Y_PED_ON
			
			
		}
		
		Y_CAR_OFF		Y_PED_OFF
		
		R_PED_ON
		//back to normal mode
		Mode=Normal;
		
		car=0;		PED=1;
	}
	
}

ISR(EXT_INT_0) //start interrupt when press push button
{
	Mode=PED_STRAIN;
}