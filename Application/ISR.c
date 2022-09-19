#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPTS.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"
#include "ULTRASONIC.h"
#include "DIO_private.h"
#include "MiddleWare.h"
#include "IR_interface.h"

ISR(INT0_vect)
{
	if (M_DIO_u8GetPinValue(DIOD,2)==1) {
		TCNT1=0;
		TRIG_EXT_INT0_FALLING;
	} else if ((M_DIO_u8GetPinValue(DIOD,2)==0)) {
		END_0 = TCNT1 ;
		distance_0 = (((END_0)*34000)/8000000)/2;
		TRIG_EXT_INT0_RISING;
	}
}

ISR(INT1_vect)
{
	if (M_DIO_u8GetPinValue(DIOD,3)==1) {
		TCNT1=0;
		TRIG_EXT_INT1_FALLING;
	} else if ((M_DIO_u8GetPinValue(DIOD,3)==0)) {
		END_1 = TCNT1 ;
		distance_1 =  (((END_1)*34000)/8000000)/2;
		TRIG_EXT_INT1_RISING;

	}
}


ISR(INT2_vect)
{
		if (M_DIO_u8GetPinValue(DIOB,2)==1) {
			TCNT1=0;
			TRIG_EXT_INT2_FALLING;

		} else if ((M_DIO_u8GetPinValue(DIOB,2)==0)) {
			END_2 = TCNT1 ;
			distance_2 =  (((END_2)*34000)/8000000)/2;
			//if(distance_2<30)
			//{M_DIO_voidTogglePin(DIOC,7);}
			TRIG_EXT_INT2_RISING;

		}

}

ISR(TIMER1_OVF_vect)
{
	TRIG_EXT_INT0_RISING;
	TRIG_EXT_INT1_RISING;
	TRIG_EXT_INT2_RISING;
	//END_0=0;
	//END_1=0;
	//END_2 = 0;

}
