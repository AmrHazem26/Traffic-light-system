
#include "../../LIBRARY/STD_TYPES.h"
#include "../../LIBRARY/BIT_MATH.h"

#include "EXTI.h"

/****************************************************Functions Body**********************************************/

void EXTI_Int0Init(void)
{
	/*initialize INT0 to operate at falling edge*/

   SET_BIT(MCUCR,MCUCR_ISC01);

   CLR_BIT(MCUCR,MCUCR_ISC00);

   /*Enabling peripheral interrupt enable*/
   SET_BIT(GICR,GICR_INT0);

}
local_eror_enum GlobalInterruptEnable(void)
{
	local_eror_enum x = ok;
	SET_BIT(SREG,SREG_I);
	return x;
}
