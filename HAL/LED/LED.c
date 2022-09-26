//**********************************************************//
//**********************************************************//
//**************      Author: Amr Hazem      ***************//
//**************      layer:  HAL            ***************//
//**************      SWC:    LED            ***************//
//**************      Version: 1.00          ***************//
//**********************************************************//
//**********************************************************//

#include "../../LIBRARY/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/TIMER1.h"
#include "LED.h"


void led_init(u8 ledPort, u8 ledPin)
{
	DIO_u8SetPinDirection(ledPort, ledPin, DIO_u8PIN_OUTPUT);
}
local_eror_enum led_on(u8 ledPort, u8 ledPin)
{
	local_eror_enum x = ok;

	DIO_u8SetPinVlue(ledPort, ledPin, DIO_u8PIN_HIGH);

	return x;
}
local_eror_enum led_off(u8 ledPort, u8 ledPin)
{
	local_eror_enum x = ok;
	DIO_u8SetPinVlue(ledPort, ledPin, DIO_u8PIN_LOW);
	return x;
}

local_eror_enum led_toggle(u8 ledPort, u8 ledPin)
{
	local_eror_enum x = ok;
	DIO_u8SetPinVlue(ledPort, ledPin, DIO_u8PIN_HIGH);

	TIMER1_delay(500);

	DIO_u8SetPinVlue(ledPort, ledPin, DIO_u8PIN_LOW);

	TIMER1_delay(500);

	return x;
}


