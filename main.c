/*
 * main.c
 *
 *  Created on: Sep 14, 2022
 *      Author: ideapad
 */

#include "app/app.h"
#include "HAL/LED/LED.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/TIMER1.h"
#include "MCAL/EXI/EXTI.h"
#include "LIBRARY/STD_TYPES.h"
#include "LIBRARY/BIT_MATH.h"

void main()
{

	led_init(DIO_u8PORTA,  DIO_u8PIN0 );
    led_init(DIO_u8PORTA,  DIO_u8PIN1 );
    led_init(DIO_u8PORTA,  DIO_u8PIN2 );
    led_init(DIO_u8PORTB,  DIO_u8PIN0 );
	led_init(DIO_u8PORTB,  DIO_u8PIN1 );
    led_init(DIO_u8PORTB,  DIO_u8PIN2 );


    EXTI_Int0Init();
    GlobalInterruptEnable();

    TIMER1_init();
    while(1)
    {
    	appStart();
    }
}


