/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef DC_MOTOR_CONFIG_H
#define DC_MOTOR_CONFIG_H

/*		H_DC_MOTOR_u8ReadDC_MOTOR_Status(u8 Copy_u8Port, u8 Copy_u8Pin) :
return 1 if DC_MOTOR is on and 0 if DC_MOTOR is off */

// L293D driver control pins for 2 motors 
#define MOTOR_DRIVER_PORT	DIOA
#define IN1					0
#define IN2					1
#define IN3					2
#define IN4					3

/* set to DIR for direction control only or 
DIR_SPEED direction and speed control */
//#define MOTOR1_DRIVER_CONTROL	DIR_SPEED
//#define MOTOR2_DRIVER_CONTROL	DIR_SPEED

#endif