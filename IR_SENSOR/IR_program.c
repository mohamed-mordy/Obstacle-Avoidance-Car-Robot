/*****************************************************************/
/*****************************************************************/
/*************	 Author  : Abdallah Issa	    ******************/
/*************	 Layer   : HAL					******************/
/*************	 SWC   	 : IR   				******************/
/*************	 Date    : 10 Aug 2022			******************/
/*************	 Version : V1.0					******************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "IR_interface.h"



void H_IR_voidInit(void)
{
	M_DIO_voidSetPinDirection(DIOC,0,INPUT);
	M_DIO_voidSetPinDirection(DIOC,1,INPUT);
	
}


u8 IR_u8ReadSignal(u8 Copy_u8Pin) {
	
	return M_DIO_u8GetPinValue(DIOC, Copy_u8Pin);
}
