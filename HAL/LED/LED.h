//**********************************************************//
//**********************************************************//
//**************      Author: Amr Hazem      ***************//
//**************      layer:             ***************//
//**************      SWC:    LED            ***************//
//**************      Version: 1.00          ***************//
//**********************************************************//
//**********************************************************//


#ifndef LED_H_
#define LED_H_
#include "../../LIBRARY/STD_TYPES.h"

void led_init(u8 ledPort, u8 ledPin);
local_eror_enum led_on(u8 ledPort, u8 ledPin);
local_eror_enum led_off(u8 ledPort, u8 ledPin);
local_eror_enum led_toggle(u8 ledPort, u8 ledPin);


#endif
