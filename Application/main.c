#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPTS.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_config.h"
#include "ULTRASONIC.h"
#include "DIO_private.h"
#include "MiddleWare.h"
#include "IR_interface.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

// sensors data(input) 
UltraSonicDistanceValue_t frontUSSensor;
UltraSonicDistanceValue_t rightUSSensor;
UltraSonicDistanceValue_t leftUSSensor;
InfraRedValue_t           rightIRSensor;
InfraRedValue_t           leftIRSensor;

// motors data(output) 
MotorDirection_t          rightMotorDir;
MotorDirection_t          leftMotorDir;
MotorPwmValue_t           rightMotorPwm;
MotorPwmValue_t           leftMotorPwm;

void (*Current_State_Ptr)(void);

void Forward_State_Handle(void);
void Stop_State_Handle(void);
void Back_State_Handle(void);
void TurnRight_State_Handle(void);
void TurnLeft_State_Handle(void);
void Rotate_State_Handle(void);
void ReadInput(void);
void WriteOutput(void);

int main(void)
{
	H_ULTRASONIC_voidInit();
	H_DC_MOTOR_voidInit_DC_MOTOR();
	H_IR_voidInit();

    /* Initialize State Pointer */
    Current_State_Ptr = &Forward_State_Handle;
    while (1) {
        Current_State_Ptr();
    }
}

void Forward_State_Handle(void)
{
    rightMotorDir = FORWARD_DIR;
    leftMotorDir  = FORWARD_DIR;
    rightMotorPwm = 100; 
    leftMotorPwm  = 100;
    WriteOutput();

    ReadInput();
    if (frontUSSensor < 30 || rightIRSensor == 0 || leftIRSensor == 0)
        Current_State_Ptr = &Stop_State_Handle;
}

void Stop_State_Handle(void)
{
    rightMotorDir = FORWARD_DIR;
    leftMotorDir  = FORWARD_DIR;
    rightMotorPwm = 0;
    leftMotorPwm  = 0;
    WriteOutput();
    _delay_ms(100); /* some delay to protect the motors from burning */
    ReadInput();
    Current_State_Ptr = &Back_State_Handle;
}

void Back_State_Handle(void)
{
    rightMotorDir = BACKWARD_DIR;
    leftMotorDir  = BACKWARD_DIR;
    rightMotorPwm = 50;
    leftMotorPwm  = 50;
    WriteOutput();
    _delay_ms(500);
    ReadInput();
    if (rightUSSensor > leftUSSensor) {
        Current_State_Ptr = &TurnRight_State_Handle;
    } else if (rightUSSensor < leftUSSensor) {
        Current_State_Ptr = &TurnLeft_State_Handle;
    } else {
        Current_State_Ptr = &Rotate_State_Handle;
    }
}

void TurnRight_State_Handle(void)
{
    rightMotorDir = BACKWARD_DIR;
    leftMotorDir  = FARWARD_DIR;
    rightMotorPwm = 50;
    leftMotorPwm  = 50;
    WriteOutput();
    _delay_ms(800);
    ReadInput();
    Current_State_Ptr = &Forward_State_Handle;
}

void TurnLeft_State_Handle(void)
{
    rightMotorDir = FARWARD_DIR;
    leftMotorDir  = BACKWARD_DIR;
    rightMotorPwm = 50;
    leftMotorPwm  = 50;         
    WriteOutput();
    _delay_ms(800);
    ReadInput();
    Current_State_Ptr = &Forward_State_Handle;
}

void Rotate_State_Handle(void)
{
    rightMotorDir = BACKWARD_DIR;
    leftMotorDir  = FARWARD_DIR; 
    rightMotorPwm = 50;
    leftMotorPwm  = 50;          
    WriteOutput();
    _delay_ms(1500);
    ReadInput();
    Current_State_Ptr = &Forward_State_Handle;
}

void ReadInput(void)
{
    frontUSSensor = ReadUSSensorValue( FRONT_US_SENSOR);
    rightUSSensor = distance_1;
    leftUSSensor  = distance_2;
    rightIRSensor = ReadIRSensorValue(rightIRSensor);
    leftIRSensor  = ReadIRSensorValue(leftIRSensor);
}

void WriteOutput(void)
{
    WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
    WriteMotorPwm(LEFT_MOTOR_ID , leftMotorPwm);
	WriteMotorDir(RIGHT_MOTOR_ID, rightMotorDir);
	WriteMotorDir(LEFT_MOTOR_ID , leftMotorDir);
}
#if 0
int main(void)
{
	
	H_ULTRASONIC_voidInit();
	H_DC_MOTOR_voidInit_DC_MOTOR();
	H_IR_voidInit();

	WriteMotorDir(RIGHT_MOTOR_ID,FORWARD_DIR);
	WriteMotorDir(LEFT_MOTOR_ID, FORWARD_DIR);

	while (1) {
		//max US 40
		//max IR 15
          
		// Read Input
		frontUSSensor =  ReadUSSensorValue( FRONT_US_SENSOR);
		rightUSSensor =  distance_1;
		leftUSSensor =    distance_2;
		rightIRSensor =  ReadIRSensorValue(rightIRSensor);
		leftIRSensor =     ReadIRSensorValue(leftIRSensor);
		
		// Stopping State
		if (frontUSSensor < 30 || rightIRSensor == 0 || leftIRSensor == 0) {
            
               /* Stop State */
			rightMotorPwm=0;
			leftMotorPwm=0;
            WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
            WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);
			//vMotor_Stop();

            /* Back State */
            setRightMotorDir(BACKWARD_DIR);
            setLeftMotorDir(BACKWARD_DIR);
            rightMotorPwm=50;
            leftMotorPwm=50;
            WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
            WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);
            _delay_ms(500);

			
			if (rightUSSensor > leftUSSensor || leftUSSensor==0) { /*TurnRight state*/
					setRightMotorDir(BACKWARD_DIR);
					setLeftMotorDir(FARWARD_DIR) ;
					rightMotorPwm=50;
					leftMotorPwm=50;
					WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
					WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);
					_delay_ms(800);

			} else if (rightUSSensor<leftUSSensor||rightUSSensor==0) { /*TurnLeft state*/ 
					setRightMotorDir (FORWARD_DIR);
					setLeftMotorDir (BACKWARD_DIR) ;
					rightMotorPwm=50;
					leftMotorPwm=50;
					WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
					WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);
					_delay_ms(800);

			} else if (rightUSSensor==leftUSSensor) { /*Rotate state*/
					setrightmotordir(BACKWARD_DIR);
					setleftmotordir(FARWARD_DIR) ;
					rightMotorPwm=50;
					leftMotorPwm=50;
					WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
					WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);
					_delay_ms(1500);
			} else {

            }
		} else /* Forward State */ {
            setrightmotordir(FARWARD_DIR);
            setleftmotordir(FARWARD_DIR) ;
			s32 SensorReadingSum = rightUSSensor - leftUSSensor + rightIRSensor - leftIRSensor;
			rightMotorPwm =  frontUSSensor;
			leftMotorPwm =    frontUSSensor;
			
			if(SensorReadingSum < 0) {
				SensorReadingSum *=  -1; 	//take absolute value - turn left
				rightMotorPwm += (SensorReadingSum);
				leftMotorPwm    -=  (SensorReadingSum);
			} else if(SensorReadingSum > 0) {
				rightMotorPwm -=(SensorReadingSum);
				leftMotorPwm    += (SensorReadingSum);
			}
	
			if (leftMotorPwm > 100 || rightMotorPwm > 100) { //trim pwm at 100
				u32 temp;
				if (leftMotorPwm > rightMotorPwm) {
					temp = leftMotorPwm - 100;
					leftMotorPwm -= temp;
					rightMotorPwm -= temp;
				} else {
					temp = rightMotorPwm - 100;
					rightMotorPwm -= temp;
					leftMotorPwm -= temp;
				}
			}
			if (leftMotorPwm < 0 ) { leftMotorPwm=0; }
			if (rightMotorPwm < 0) { rightMotorPwm=0; }

			WriteMotorPwm(RIGHT_MOTOR_ID, rightMotorPwm);
			WriteMotorPwm(LEFT_MOTOR_ID, leftMotorPwm);

		}
	}
}
#endif

