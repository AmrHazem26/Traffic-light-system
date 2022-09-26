/*
 * app.c
 *
 *  Created on: Sep 13, 2022
 *      Author: ideapad
 */

#include "../LIBRARY/STD_TYPES.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER1.h"
#include "../MCAL/EXI/EXTI.h"

#include "../HAL/LED/LED.h"
#include "app.h"



u8 green_value = 0;
u8 yellow_value = 0;
u8 red_value = 0;

void appStart()
{
	//green 0
	// yellow 1
	//red 2

	green_value = 1;
	led_on(DIO_u8PORTA,DIO_u8PIN0); // green on


	TIMER1_delay(5000);

	led_off(DIO_u8PORTA,DIO_u8PIN0); //green off

	green_value = 0;

	yellow_value = 1;


	for(u8 i=0; i<=4; i++)
	{
		led_toggle(DIO_u8PORTA,DIO_u8PIN1); //yellow toggles
	}

	led_off(DIO_u8PORTA,DIO_u8PIN1); //yellow off
    yellow_value = 0;

	led_on(DIO_u8PORTA,DIO_u8PIN2);//red on
	red_value = 1;

	TIMER1_delay(5000);

	led_off(DIO_u8PORTA,DIO_u8PIN2); //red off

	red_value = 0;

	yellow_value=1;

	for(u8 i=0; i<=4; i++)
	{
		led_toggle(DIO_u8PORTA,DIO_u8PIN1);
	}

	led_off(DIO_u8PORTA,DIO_u8PIN1);
	yellow_value = 0;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)

//void _vector_1(void) __attribute__((signal));
//void __vector_1(void)
{
    led_off(DIO_u8PORTA,DIO_u8PIN0);
    led_off(DIO_u8PORTA,DIO_u8PIN1);
	led_off(DIO_u8PORTA,DIO_u8PIN2);

	if(red_value)
	{
		led_on(DIO_u8PORTB,DIO_u8PIN0);
		led_on(DIO_u8PORTA,DIO_u8PIN2);
		TIMER1_delay(5000);
	}



	else if(green_value ||  yellow_value  )
	{
		led_on(DIO_u8PORTB,DIO_u8PIN2);
		led_off(DIO_u8PORTA,DIO_u8PIN0);

		for(u8 i=0; i<=4; i++)
		{
			led_toggle(DIO_u8PORTA,DIO_u8PIN1);
			led_toggle(DIO_u8PORTB,DIO_u8PIN1);
		}

		led_off(DIO_u8PORTB,DIO_u8PIN2);
		led_off(DIO_u8PORTA,DIO_u8PIN1);
		led_off(DIO_u8PORTB,DIO_u8PIN1);

		led_on(DIO_u8PORTA,DIO_u8PIN2);
		led_on(DIO_u8PORTB,DIO_u8PIN0);

		TIMER1_delay(5000);
	}

	led_off(DIO_u8PORTA,DIO_u8PIN2);

	for(u8 i=0 ; i<=4 ; i++)
	{
		led_toggle(DIO_u8PORTA,DIO_u8PIN1);
		led_toggle(DIO_u8PORTB,DIO_u8PIN1);
	}

	led_off(DIO_u8PORTA,DIO_u8PIN1);
    led_off(DIO_u8PORTB,DIO_u8PIN1);

	led_off(DIO_u8PORTB,DIO_u8PIN0);
	led_on(DIO_u8PORTB,DIO_u8PIN2);
	led_on(DIO_u8PORTA,DIO_u8PIN0);

	TIMER1_delay(1000);

    led_off(DIO_u8PORTB,DIO_u8PIN2);



	__asm volatile("jmp 0x00");
}




