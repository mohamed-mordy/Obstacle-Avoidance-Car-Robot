#include "MiddleWare.h"
#include "ULTRASONIC.h"
#ifndef F_CPU
#define  F_CPU 8000000UL
#endif
#include <util/delay.h>
#include "STD_TYPES.h"
#include "IR_interface.h"
#include "DC_MOTOR_interface.h"

volatile u32 distance_0; //front
volatile u32 distance_1; //right
volatile u32 distance_2; //left
                         
volatile u32 START_0 =0;
volatile u32 END_0=0;
volatile u32 START_1 =0;
volatile u32 END_1=0;
volatile u32 START_2 =0;
volatile u32 END_2=0;


UltraSonicDistanceValue_t ReadUSSensorValue(USSensor_t ID)
{	
	distance_0=40;
	distance_1=40;
	distance_2=40;
	
	H_ULTRASONIC_voidTRIGGER_0();	
	_delay_us(8192);
	
	H_ULTRASONIC_voidTRIGGER_1();	
	_delay_us(8192);
	
	H_ULTRASONIC_voidTRIGGER_2();	
	_delay_us(8192);

	switch(ID) {
		case FRONT_US_SENSOR:
			return distance_0;
			break;
		case RIGHT_US_SENSOR:
			return distance_1;
			break;
		case LEFT_US_SENSOR:
			return distance_2;
			break;
		default:return 25;
			break;
	}
}

InfraRedValue_t ReadIRSensorValue(IRSensor_t ID)
{
	switch(ID){
		case RIGHT_IR_SENSOR_ID: //C0
			if (IR_u8ReadSignal(0) == 0){
				return OBSTACLE_NOT_FOUND;
			}
			else{
				return OBSTACLE_FOUND;
			}
			break;
		case LEFT_IR_SENSOR_ID: //C1
			if (IR_u8ReadSignal(1) == 0){
				return OBSTACLE_NOT_FOUND;
			}
			else{
				return OBSTACLE_FOUND;
			}
			break;
		default:return OBSTACLE_NOT_FOUND;
			break;
	}
}


void WriteMotorDir(Motor_t ID, MotorDirection_t dir)
{	
	switch(ID){
		case RIGHT_MOTOR_ID: 
			setRightMotorDir(dir);
		break;
		case LEFT_MOTOR_ID: 
			setLeftMotorDir(dir);
		break;
		default:
		break;
	}
}

void WriteMotorPwm(Motor_t ID, MotorPwmValue_t pwm)
{
	switch(ID){
		case RIGHT_MOTOR_ID: 
			setRightMotorPwm(pwm);
		break;
		case LEFT_MOTOR_ID: 
			setLeftMotorPwm(pwm);
		break;
		default:
		break;
	}
}
