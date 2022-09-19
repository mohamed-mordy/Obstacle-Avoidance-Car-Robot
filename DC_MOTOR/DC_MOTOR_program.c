/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"


/*
M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,EN1,HIGH);
M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,EN2,HIGH);

M_TIMERS_voidGenerate_Wave_Fast_PWM();
M_TIMERS_voidGenerate_Wave_Fast_PWM();
*/


void setRightMotorDir (u8 dir)
 {
	 if (dir == 1) {
		 	M_DIO_voidSetPinValue(DIOA	,0,HIGH);
		 	M_DIO_voidSetPinValue(DIOA,1,LOW);
	 } else if (dir == 0) {
		 	M_DIO_voidSetPinValue(DIOA	,0,LOW);
		 	M_DIO_voidSetPinValue(DIOA,1,HIGH);
	 }
	 
 }
 
 void setLeftMotorDir (u8 dir)
 {
	 	 if (dir == 1) {
		 	 M_DIO_voidSetPinValue(DIOA,2,LOW);
			 M_DIO_voidSetPinValue(DIOA	,3,HIGH);

	 	 } else if (dir == 0) {
			 M_DIO_voidSetPinValue(DIOA,2,HIGH);
		 	 M_DIO_voidSetPinValue(DIOA	,3,LOW);
	 	 } else {
			  	M_DIO_voidSetPinValue(DIOA	,0,HIGH);
			  	M_DIO_voidSetPinValue(DIOA,1,LOW);
			  	M_DIO_voidSetPinValue(DIOA	,2,LOW);
			  	M_DIO_voidSetPinValue(DIOA,3,HIGH);
		  }
 }
 
 
 void setRightMotorPwm (u8 pwm)
 {
	 M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(pwm);
 }
 
 void setLeftMotorPwm (u8 pwm)
 {
	  M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(pwm);
 }


void H_DC_MOTOR_voidInit_DC_MOTOR()
{
	M_DIO_voidSetPinDirection(DIOA,0,OUTPUT);
	M_DIO_voidSetPinDirection(DIOA,1,OUTPUT);
	M_DIO_voidSetPinDirection(DIOA,2,OUTPUT);
	M_DIO_voidSetPinDirection(DIOA,3,OUTPUT);
	
	Timer_Init();
}



void vMotor_Start()
{
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(25);	
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(25);
	M_DIO_voidSetPinValue(DIOA	,0,HIGH);
	M_DIO_voidSetPinValue(DIOA,1,LOW);
	M_DIO_voidSetPinValue(DIOA	,2,LOW);
	M_DIO_voidSetPinValue(DIOA,3,HIGH);

}



void vMotor_Stop()
{
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(0);
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(0);

	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN1,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT, IN2,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN3,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT, IN4,LOW);

}



void vMotor_TurnRight()
{
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(10);
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(0);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN1,HIGH);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN2,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN3,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN4,LOW);

}

void vMotor_TurnLeft()
{
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(0);
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(10);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN1,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN2,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN3,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN4,HIGH);

}

void vMotor_TurnBack()
{
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T0(0);
	M_TIMERS_voidGenerate_Wave_Fast_PWM_T2(10);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN1,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN2,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT	,IN3,LOW);
	M_DIO_voidSetPinValue(MOTOR_DRIVER_PORT,IN4,HIGH);

}

