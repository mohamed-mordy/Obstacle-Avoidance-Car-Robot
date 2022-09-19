/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

//this driver will be equiped to use motors with motor drivers

/* DIOA, DIOB, DIOC or DIOD */
/*  DIO PORTS  */
#define DIOA	0
#define DIOB	1
#define DIOC	2
#define DIOD	3

/* Pins from 0 to 8 for all ports */


/*	DC_MOTOR ON : HIGH , 
	DC_MOTOR OFF : LOW */

//motor motion direction in Copy_u8Motor_Dir
#define CLOCKWISE		0
#define ANTI_CLOCKWISE	1

/* direction only or direction and speed*/
#define DIR			0
#define DIR_SPEED	1



//Copy_u8Motor_No = 1 or 2 
void H_DC_MOTOR_voidInit_DC_MOTOR();
void setRightMotorDir (u8);
void setLeftMotorDir (u8);
void setRightMotorPwm (u8);
void setLeftMotorPwm (u8);
void vMotor_Start();
void vMotor_Stop();
void vMotor_TurnRight();
void vMotor_TurnLeft();
void vMotor_TurnBack();



#endif