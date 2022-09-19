/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPTS.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"


/*
	Configuration of TIMERS
*/

void Timer_Init(void) 
{
	//set OC0 pin as output to EN1
	M_DIO_voidSetPinDirection(DIOB,3,OUTPUT);
		//set OC0 pin as output to EN1
		M_DIO_voidSetPinDirection(DIOD,7,OUTPUT);
	
	// set Timer/Counter0 mode of operation as Fast_PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	// set Timer/Counter2 mode of operation as Fast_PWM
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);

	

	/* Set Timer/Counter0 as a timer with a Clk prescalar of 1024, timer_clk=8M/1024=8KHZ,
	tick_time=(1/8)ms */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	
	/*Non Inverting mode more OCR0 more duty_cycle_OC0,
	clear on Compare Match and set on overflow, 
	foc0=(fclk_IO/(256*prescalar))=(8M/(256*1024))=30.6HZ,
	Toc0=32.6ms,DutyCycle=(64/256)=25%, Ton=24.45ms */
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR2,COM21);
}

//t0
void M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(u8 Copy_u8DutyCycle)
{
		/* For after signal of duty_cycle_OC0=25%=(64/255)=(Ton/Toff) for Non Inverting*/
		/* For after signal of duty_cycle_OC0=75%=(256-64/256)=(Ton/Toff) for Inverting*/
		u32 Loc_u32t = ((u32)Copy_u8DutyCycle * 255) / 100;
		OCR0 = (u8) Loc_u32t;

}


//t2
void M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(u8 Copy_u8DutyCycle)
{
	/* For after signal of duty_cycle_OC0=25%=(64/255)=(Ton/Toff) for Non Inverting*/
	/* For after signal of duty_cycle_OC0=75%=(256-64/256)=(Ton/Toff) for Inverting*/
	u32 Loc_u32t = ((u32)Copy_u8DutyCycle * 255) / 100;
	OCR2 = (u8) Loc_u32t;
}

void M_TIMER_voidTIMERCOUNTER_TIMER1_OVF(void)
{


	/* Set Timer/Counter0 as a timer with a Clk prescalar of 1024, timer_clk=8M/1024=8KHZ,
	tick_time=(1/8)ms */
	SET_BIT(TIMSK,TOIE1);
	SET_BIT(TCCR1B,CS10);


	
}