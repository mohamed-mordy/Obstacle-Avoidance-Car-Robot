/*
 * CFile1.c
 *
 * Created: 8/10/2022 2:23:35 PM
 *  Author: mohamed
 */ 

#include "INTERRUPTS.h"
#include "DIO_interface.h"
#include "STD_TYPES.h"

void M_INTERRUPTS_void_Init (void)
{
	M_DIO_voidSetPinDirection(DIOD,2,0);
	M_DIO_voidSetPinDirection(DIOD,3,0);
	M_DIO_voidSetPinDirection(DIOB,2,0);

	TRIG_EXT_INT0_RISING;
	TRIG_EXT_INT1_RISING;
	TRIG_EXT_INT2_RISING;

	ENABLE_EXT_INT0	;
	ENABLE_EXT_INT1	;
	ENABLE_EXT_INT2	;

	ENABLE_GLOBAL_INTERRUPT;
}


