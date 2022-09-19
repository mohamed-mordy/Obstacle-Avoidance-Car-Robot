/*
 * CFile1.c
 *
 * Created: 8/10/2022 3:12:33 PM
 *  Author: mohamed
 */ 
#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "INTERRUPTS.h"
#include "STD_TYPES.h"
#include <util/delay.h>


void H_ULTRASONIC_voidInit (void)
{
	M_TIMER_voidTIMERCOUNTER_TIMER1_OVF();
	M_DIO_voidSetPinDirection(DIOA,5,1);
	M_DIO_voidSetPinDirection(DIOA,6,1);
	M_DIO_voidSetPinDirection(DIOA,7,1);
	M_INTERRUPTS_void_Init();
	
}



void H_ULTRASONIC_voidTRIGGER_0(void)
{
	M_DIO_voidSetPinValue(DIOA,5,1);
	_delay_us(30);
	M_DIO_voidSetPinValue(DIOA,5,0);// echo 1 ISR -->>> Distanc ?? ----echo 0--- return distance 

}


void H_ULTRASONIC_voidTRIGGER_1(void)
{
	M_DIO_voidSetPinValue(DIOA,6,HIGH);
	_delay_us(30);
	M_DIO_voidSetPinValue(DIOA,6,LOW);

}


void H_ULTRASONIC_voidTRIGGER_2(void)
{
	TRIG_EXT_INT2_RISING;
	M_DIO_voidSetPinValue(DIOA,7,HIGH);
	_delay_us(30);
	M_DIO_voidSetPinValue(DIOA,7,LOW);

}