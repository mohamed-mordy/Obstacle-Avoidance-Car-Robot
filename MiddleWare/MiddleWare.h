#ifndef MIDDLE_WARE_H_
#define MIDDLE_WARE_H_


#include "STD_TYPES.h"

extern volatile u32    distance_0 ; //front
extern volatile u32    distance_1 ; //right
extern volatile u32    distance_2 ; //left
extern volatile u32    START_0 ;
extern volatile u32    END_0;
extern volatile u32    START_1;
extern volatile u32    END_1;
extern volatile u32    START_2;
extern volatile u32    END_2;


/*
typedef enum {
	DISTANCE_00 = 5,
	DISTANCE_01 = 10,
	DISTANCE_02 = 15,
	DISTANCE_03 = 20,
	DISTANCE_04 = 25,
	DISTANCE_05 = 30,
	DISTANCE_06 = 35,
	DISTANCE_07 = 40,
} UltraSonicDistanceValue_t;
*/

typedef u32 UltraSonicDistanceValue_t;

typedef enum {
	OBSTACLE_NOT_FOUND=20,
	OBSTACLE_FOUND=0,
} InfraRedValue_t;

typedef enum {
	BACKWARD_DIR = 0,
	FORWARD_DIR = 1,
} MotorDirection_t;

typedef enum {
	FRONT_US_SENSOR,
	RIGHT_US_SENSOR,
	LEFT_US_SENSOR,
} USSensor_t;

typedef enum {
	RIGHT_IR_SENSOR_ID,
	LEFT_IR_SENSOR_ID,
} IRSensor_t;

typedef enum {
	RIGHT_MOTOR_ID,
	LEFT_MOTOR_ID,
} Motor_t;


typedef u32 MotorPwmValue_t;


UltraSonicDistanceValue_t    ReadUSSensorValue(USSensor_t ID);
InfraRedValue_t                       ReadIRSensorValue(IRSensor_t ID);


void  WriteMotorDir(Motor_t ID, MotorDirection_t dir);
void WriteMotorPwm(Motor_t ID, MotorPwmValue_t pwm);



#endif
