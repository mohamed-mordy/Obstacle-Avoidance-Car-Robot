/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	23 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"
/*  DIO PORTS  */
#define DIOA	0
#define DIOB	1
#define DIOC	2
#define DIOD	3


/*  DIO PINS OUTPUT VALUE */
#define LOW		0
#define HIGH	1


/*  DIO PINS MODES */
#define INPUT		0
#define OUTPUT		1


void M_DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void M_DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void M_DIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);
u8 	 M_DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void M_DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode);
/*void M_DIO_voidWR_on_PortValue(u8 Copy_u8Port, u8 Copy_u8Starting_Pin, u8 Copy_u8PinsNumber, u8 Copy_u8Value);*/
void M_DIO_voidWR_on_PortAnyValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8 	 M_DIO_u8GetPortValue(u8 Copy_u8Port);
void M_DIO_voidTogglePort(u8 Copy_u8Port);
/* set Copy_u8ConfigMode as HIGH to activate internal pull up for the pin and LOW to deactivate internal pull up for the pin  */
void M_DIO_voidConfigureInternalPullUp(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConfigMode);
/* the PUD bit in the SFIOR Register can be set to disable all pull-ups in all ports */
/* set Copy_u8ConfigMode as HIGH to activate internal pull up for all the pins of 4 DIO ports and LOW to deactivate internal pull up for all the pins of 4 DIO ports   */
void M_DIO_voidConfigureAllInternalPullUps(u8 Copy_u8ConfigMode);
void M_DIO_voidSet_LowNibble_Direction(u8 Copy_u8Port, u8 Copy_u8Mode);
void M_DIO_voidSet_HighNibble_Direction(u8 Copy_u8Port, u8 Copy_u8Mode);
void M_DIO_voidWR_on_LowNibbleOfPort_Value(u8 Copy_u8Port, u8 Copy_u8Value);
void M_DIO_voidWR_on_HighNibbleOfPort_Value(u8 Copy_u8Port, u8 Copy_u8Value);
u8 M_DIO_u8Get_LowNibbleOfPort_Value(u8 Copy_u8Port);
u8 M_DIO_u8Get_HighNibbleOfPort_Value(u8 Copy_u8Port);


#endif