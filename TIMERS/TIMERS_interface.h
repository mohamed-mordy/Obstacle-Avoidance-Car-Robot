/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

#define OVF						0
#define CTC						1
#define PWM_PHASE_CORRECT		2
#define FAST_PWM				3


void Timer_Init(void);

//t0
void M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(u8 Copy_u8DutyCycle);

//t2
void M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(u8 Copy_u8DutyCycle);


void M_TIMER_voidTIMERCOUNTER_TIMER1_OVF(void);


#endif