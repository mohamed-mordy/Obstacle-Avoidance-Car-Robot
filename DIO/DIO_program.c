/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	23 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPTS.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "math.h"

void M_DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{	
	switch(Copy_u8Port)
	{
		case DIOA :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Mode == OUTPUT)
						{
							SET_BIT(DDRA,Copy_u8Pin);
						}
						else if(Copy_u8Mode == INPUT)
						{
							CLR_BIT(DDRA,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOB :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Mode == OUTPUT)
						{
							SET_BIT(DDRB,Copy_u8Pin);
						}
						else if(Copy_u8Mode == INPUT)
						{
							CLR_BIT(DDRB,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOC :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Mode == OUTPUT)
						{
							SET_BIT(DDRC,Copy_u8Pin);
						}
						else if(Copy_u8Mode == INPUT)
						{
							CLR_BIT(DDRC,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOD :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Mode == OUTPUT)
						{
							SET_BIT(DDRD,Copy_u8Pin);
						}
						else if(Copy_u8Mode == INPUT)
						{
							CLR_BIT(DDRD,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		/*default	:	break;*/
	}

}


void M_DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{	
	switch(Copy_u8Port)
	{
		case DIOA :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Value == HIGH)
						{
							SET_BIT(PORTA,Copy_u8Pin);
						}
						else if(Copy_u8Value == LOW)
						{
							CLR_BIT(PORTA,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOB :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Value == HIGH)
						{
							SET_BIT(PORTB,Copy_u8Pin);
						}
						else if(Copy_u8Value == LOW)
						{
							CLR_BIT(PORTB,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOC :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Value == HIGH)
						{
							SET_BIT(PORTC,Copy_u8Pin);
						}
						else if(Copy_u8Value == LOW)
						{
							CLR_BIT(PORTC,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOD :
					if (Copy_u8Pin <=7)
					{
						if(Copy_u8Value == HIGH)
						{
							SET_BIT(PORTD,Copy_u8Pin);
						}
						else if(Copy_u8Value == LOW)
						{
							CLR_BIT(PORTD,Copy_u8Pin);
						}
						else
						{
							/* Return Error */
						}
					}
					else
					{
						/* Return Error */
					}
		break;
		/*default	:	break; */
	}
}

void M_DIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{	
	switch(Copy_u8Port)
	{
		case DIOA :
					if (Copy_u8Pin <=7)
					{
						TOG_BIT(PORTA,Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOB :
					if (Copy_u8Pin <=7)
					{
						TOG_BIT(PORTB,Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOC :
					if (Copy_u8Pin <=7)
					{
						TOG_BIT(PORTC,Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
		break;
		case DIOD :
					if (Copy_u8Pin <=7)
					{
						TOG_BIT(PORTD,Copy_u8Pin);
					}
					else
					{
						/* Return Error */
					}
		break;
		/*default	:	break; */
	}
}


u8 	 M_DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{	
	u8 LOC_ReadPinValue = 0;
	switch(Copy_u8Port)
	{
		case DIOA :	LOC_ReadPinValue = GET_BIT(PINA, Copy_u8Pin);	break;
		case DIOB :	LOC_ReadPinValue = GET_BIT(PINB, Copy_u8Pin);	break;
		case DIOC :	LOC_ReadPinValue = GET_BIT(PINC, Copy_u8Pin);	break;
		case DIOD :	LOC_ReadPinValue = GET_BIT(PIND, Copy_u8Pin);	break;
		/*default    :												break;*/
	}
	return LOC_ReadPinValue;
}

void M_DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode)
{	
	switch(Copy_u8Port)
	{
		case DIOA :
				DDRA = Copy_u8Mode;	/* can be in any format like: 0x01 or 0b00001111 depending on choosing mode whether (i/p:0) or (o/p:1) */ 
		break;
		case DIOB :
				DDRB = Copy_u8Mode;
		break;
		case DIOC :
				DDRC = Copy_u8Mode;
		break;
		case DIOD :
				DDRD = Copy_u8Mode;
		break;
		/*default	:	break;*/
	}

}

/*
void M_DIO_voidWR_on_PortValue(u8 Copy_u8Port, u8 Copy_u8Starting_Pin, u8 Copy_u8PinsNumber, u8 Copy_u8Value)
{
		switch(Copy_u8Port)
	{
		case DIOA:
			PORTA &= (~( ((u8)(pow(2, Copy_u8PinsNumber)-1)) << Copy_u8Starting_Pin ));
			PORTA |= (Copy_u8Value << Copy_u8Starting_Pin);
		break;
		case DIOB:
			PORTB &= ~( ((u8)(pow(2, Copy_u8PinsNumber)-1)) << Copy_u8Starting_Pin );
			PORTB |= (Copy_u8Value << Copy_u8Starting_Pin);
		break;
		case DIOC:
			PORTC &= ~( ((u8)(pow(2, Copy_u8PinsNumber)-1)) << Copy_u8Starting_Pin );
			PORTC |= (Copy_u8Value << Copy_u8Starting_Pin);
		break;
		case DIOD:
			PORTD &= (~( ((u8)(pow(2, Copy_u8PinsNumber)-1)) << Copy_u8Starting_Pin ));
			PORTD |= (Copy_u8Value << Copy_u8Starting_Pin);
		break;
	}
}
*/

void M_DIO_voidWR_on_PortAnyValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA = Copy_u8Value;
		break;
		case DIOB:
			PORTB = Copy_u8Value;
		break;		
		case DIOC:
			PORTC = Copy_u8Value;
		break;
		case DIOD:
			PORTD = Copy_u8Value;
		break;
	}
}

u8 M_DIO_u8GetPortValue(u8 Copy_u8Port)
{	
	u8 LOC_ReadPinValue = 0;
	switch(Copy_u8Port)
	{
		case DIOA :	LOC_ReadPinValue = PINA;	break;
		case DIOB :	LOC_ReadPinValue = PINB;	break;
		case DIOC :	LOC_ReadPinValue = PINC;	break;
		case DIOD :	LOC_ReadPinValue = PIND;	break;
		/*default    :								break;*/
	}
	return LOC_ReadPinValue;
}

void M_DIO_voidTogglePort(u8 Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case DIOA :	PORTA = ~PORTA;		break;	/* Toggle all port. PORTA ^= 0xFF , Toggle pins3,4 in portA. PORTA^= ((1<<4)|(1<<5))  */
		case DIOB :	PORTB = ~PORTB;		break;
		case DIOC :	PORTC = ~PORTC;		break;
		case DIOD :	PORTD = ~PORTD;		break;
		/*default    :						break;*/
	}
}

/*
If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is
activated. To switch the pull-up resistor off, PORTxn has to be written logic zero or the pin has to
be configured as an output pin. The port pins are tri-stated when a reset condition becomes
active, even if no clocks are running.
*/
void M_DIO_voidConfigureInternalPullUp(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConfigMode)
{
	switch(Copy_u8Port)
	{
		case DIOA :	
			if(Copy_u8ConfigMode==HIGH)
			{
				SET_BIT(PORTA,Copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTA,Copy_u8Pin);
			}
		break;
		case DIOB :
			if(Copy_u8ConfigMode==HIGH)
			{
				SET_BIT(PORTB,Copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTB,Copy_u8Pin);
			}
		break;
		case DIOC :
			if(Copy_u8ConfigMode==HIGH)
			{
				SET_BIT(PORTC,Copy_u8Pin);
			}
			else
			{
				CLR_BIT(PORTC,Copy_u8Pin);
			}
		break;
		case DIOD :
		if(Copy_u8ConfigMode==HIGH)
		{
			SET_BIT(PORTD,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTD,Copy_u8Pin);
		}
		break;
		/*default    :						break;*/
	}
}

/* the PUD bit in the SFIOR Register can be set to disable all pull-ups in all ports */
/* set Copy_u8ConfigMode as HIGH to activate internal pull up for all the pins of 4 DIO ports and LOW to deactivate internal pull up for all the pins of 4 DIO ports   */
/* PUD by default is zero meaning that the internal pull up for all the pins of 4 DIO ports is activated */
void M_DIO_voidConfigureAllInternalPullUps(u8 Copy_u8ConfigMode)
{
	//configure PUD bit in SFIOR
	if(Copy_u8ConfigMode==LOW)
	{
		//disable all internal pull up
		SET_BIT(SFIOR,2);
	}
	else
	{
		//enable all internal pull up
		CLR_BIT(SFIOR,2);
	}
}

void M_DIO_voidSet_LowNibble_Direction(u8 Copy_u8Port, u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{	
		case OUTPUT:
			switch(Copy_u8Port)
			{
				case DIOA:
					DDRA |= 0x0f;
				break;
				case DIOB:
					DDRB |= 0x0f;
				break;
				case DIOC:
					DDRC |= 0x0f;
				break;
				case DIOD:
					DDRD |= 0x0f;
				break;
			}
		break;
		case INPUT:
			switch(Copy_u8Port)
			{
				case DIOA:
					DDRA &= 0xf0;
				break;
				case DIOB:
					DDRB &= 0xf0;
				break;
				case DIOC:
					DDRC &= 0xf0;
				break;
				case DIOD:
					DDRD &= 0xf0;
				break;
			}
		break;
	}
}

void M_DIO_voidSet_HighNibble_Direction(u8 Copy_u8Port, u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{	
		case OUTPUT:
			switch(Copy_u8Port)
			{
				case DIOA:
					DDRA |= 0xf0;
				break;
				case DIOB:
					DDRB |= 0xf0;
				break;
				case DIOC:
					DDRC |= 0xf0;
				break;
				case DIOD:
					DDRD |= 0xf0;
				break;
			}
		break;
		case INPUT:
			switch(Copy_u8Port)
			{
				case DIOA:
					DDRA &= 0x0f;
				break;
				case DIOB:
					DDRB &= 0x0f;
				break;
				case DIOC:
					DDRC &= 0x0f;
				break;
				case DIOD:
					DDRD &= 0x0f;
				break;
			}
		break;
	}
}

void M_DIO_voidWR_on_LowNibbleOfPort_Value(u8 Copy_u8Port, u8 Copy_u8Value)
{
	Copy_u8Value &= 0x0f;
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA &= 0xf0;
			PORTA |= Copy_u8Value;
		break;
		case DIOB:
			PORTB &= 0xf0;
			PORTB |= Copy_u8Value;
		break;
		case DIOC:
			PORTC &= 0xf0;
			PORTC |= Copy_u8Value;
		break;
		case DIOD:
			PORTD &= 0xf0;
			PORTD |= Copy_u8Value;
		break;
	}
	
/*	u8 i;
	for (i=0; i<=3; i++)
	{
		M_DIO_voidSetPinValue(Copy_u8_7SEG_Port, i, GET_BIT(Copy_u8_DisplayValue,i));
	}	*/
}

void M_DIO_voidWR_on_HighNibbleOfPort_Value(u8 Copy_u8Port, u8 Copy_u8Value)
{
	Copy_u8Value <<= 4;
	switch(Copy_u8Port)
	{
		case DIOA:
			PORTA &= 0x0f;
			PORTA |= Copy_u8Value;
		break;
		case DIOB:
			PORTB &= 0x0f;
			PORTB |= Copy_u8Value;
		break;
		case DIOC:
			PORTC &= 0x0f;
			PORTC |= Copy_u8Value;
		break;
		case DIOD:
			PORTD &= 0x0f;
			PORTD |= Copy_u8Value;
		break;
	}
	
/*	u8 i;
	Copy_u8_DisplayValue <<= 4;
	for (i=4; i<=7; i++)
	{
		M_DIO_voidSetPinValue(Copy_u8_7SEG_Port, i, GET_BIT(Copy_u8_DisplayValue,i));
	}	*/
}

u8 M_DIO_u8Get_LowNibbleOfPort_Value(u8 Copy_u8Port)
{
	u8 Loc_u8ReadValue=0;
	switch(Copy_u8Port)
	{
		case DIOA :	Loc_u8ReadValue = PINA;		Loc_u8ReadValue &= 0x0f;	break;
		case DIOB :	Loc_u8ReadValue = PINB;		Loc_u8ReadValue &= 0x0f;	break;
		case DIOC :	Loc_u8ReadValue = PINC;		Loc_u8ReadValue &= 0x0f;	break;
		case DIOD :	Loc_u8ReadValue = PIND;		Loc_u8ReadValue &= 0x0f;	break;
		/*default    :								break;*/
	}
	return Loc_u8ReadValue;
}

u8 M_DIO_u8Get_HighNibbleOfPort_Value(u8 Copy_u8Port)
{
	u8 Loc_u8ReadValue=0;
	switch(Copy_u8Port)
	{
		case DIOA :	Loc_u8ReadValue = PINA;		Loc_u8ReadValue >>= 4;	break;
		case DIOB :	Loc_u8ReadValue = PINB;		Loc_u8ReadValue >>= 4;	break;
		case DIOC :	Loc_u8ReadValue = PINC;		Loc_u8ReadValue >>= 4;	break;
		case DIOD :	Loc_u8ReadValue = PIND;		Loc_u8ReadValue >>= 4;	break;
		/*default    :								break;*/
	}
	return Loc_u8ReadValue;
}