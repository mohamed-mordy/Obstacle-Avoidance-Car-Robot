/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	16 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* SREG status Register  */
#define SREG	(*((volatile u8*)(0x005F)))
#define GICR	(*((volatile u8*)(0x005B)))
#define GIFR	(*((volatile u8*)(0x005A)))
#define MCUCR	(*((volatile u8*)(0x0055)))
#define MCUCSR	(*((volatile u8*)(0x0054)))



/* External Interrupts Enable Bits */
/* General Interrupt Control Register */
#define INT0	6
#define INT1	7
#define INT2	5

#define INTF0	6
#define INTF1	7
#define INTF2	5

#define ISC00	0
#define ISC01	1

#define ISC10	2
#define ISC11	3

#define ISC2	6

#define ENABLE_EXT_INT0		SET_BIT(GICR,INT0)
#define DISABLE_EXT_INT0	CLR_BIT(GICR,INT0)
#define ENABLE_EXT_INT1		SET_BIT(GICR,INT1)

#define DISABLE_EXT_INT1	CLR_BIT(GICR,INT1)
#define ENABLE_EXT_INT2		SET_BIT(GICR,INT2)
#define DISABLE_EXT_INT2	CLR_BIT(GICR,INT2)
#define CLR_EXT_INTF0	SET_BIT(GIFR,INTF0)
#define CLR_EXT_INTF1	SET_BIT(GIFR,INTF1)
#define CLR_EXT_INTF2	SET_BIT(GIFR,INTF2)
#define IS_EXT_INTF0_SET	GET_BIT(GIFR,INTF0)
#define IS_EXT_INTF1_SET	GET_BIT(GIFR,INTF1)
#define IS_EXT_INTF2_SET	GET_BIT(GIFR,INTF2)



#define I_BIT	7
#define ENABLE_GLOBAL_INTERRUPT		SET_BIT(SREG,I_BIT)
#define DISABLE_GLOBAL_INTERRUPT	CLR_BIT(SREG,I_BIT)



/* External Interrupts INT0 Activations */
/* MCU Control Register */

#define TRIG_EXT_INT0_LOW_LVL				CLR_2BITS(MCUCR,ISC00,ISC01)
#define TRIG_EXT_INT0_RISING				SET_2BITS(MCUCR,ISC00,ISC01)
#define TRIG_EXT_INT0_ANY_LOGICAL_CHNG		SET_BIT(MCUCR,ISC00);CLR_BIT(MCUCR,ISC01)
#define TRIG_EXT_INT0_FALLING				CLR_BIT(MCUCR,ISC00);SET_BIT(MCUCR,ISC01)

/* External Interrupts INT1 Activations */

#define TRIG_EXT_INT1_LOW_LVL				CLR_2BITS(MCUCR,ISC10,ISC11)
#define TRIG_EXT_INT1_RISING				SET_2BITS(MCUCR,ISC10,ISC11)
#define TRIG_EXT_INT1_ANY_LOGICAL_CHNG		SET_BIT(MCUCR,ISC10);CLR_BIT(MCUCR,ISC11)
#define TRIG_EXT_INT1_FALLING				CLR_BIT(MCUCR,ISC10);SET_BIT(MCUCR,ISC11)

/* External Interrupts INT2 Activations */
/* MCU Control and Status Register */
#define TRIG_EXT_INT2_FALLING	CLR_BIT(MCUCSR,ISC2)
#define TRIG_EXT_INT2_RISING	SET_BIT(MCUCSR,ISC2)


/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */

#define _VECTOR(N)			__vector_ ## N

#define BADISR_vect			__vector_default

#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(2)
#define INT1_vect_num        2

/* External Interrupt Request 2 */
#define INT2_vect            _VECTOR(3)
#define INT2_vect_num        3

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(16)
#define ADC_vect_num        16

/* EEPROM Ready */
#define EE_RDY_vect            _VECTOR(17)
#define EE_RDY_vect_num        17



/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect            _VECTOR(4)
#define TIMER2_COMP_vect_num        4

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(5)
#define TIMER2_OVF_vect_num        5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(6)
#define TIMER1_CAPT_vect_num        6

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(7)
#define TIMER1_COMPA_vect_num        7

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(8)
#define TIMER1_COMPB_vect_num        8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(9)
#define TIMER1_OVF_vect_num        9

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect            _VECTOR(10)
#define TIMER0_COMP_vect_num        10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11



#  define ISR_NOBLOCK    __attribute__((interrupt))
#  define ISR_NAKED      __attribute__((naked))
#  define __INTR_ATTRS used

#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __attribute__((interrupt)) __VA_ARGS__; \
void vector (void)


/*
// __attribute__((signal,used)) - (signal) - to tell avr that this is a fn. executes by a signal from H-W. - (used) - to prevent some compilers from deleting ISR code as they detect it as if it will never be called.
//__attribute__((interrupt)) - set Ibit at the first of ISR before push.
//__attribute__((naked)) - hide assembly and we will need to set Ibit in the last of fn.
void __vector_1(void) __attribute__((signal,used)) __attribute__((interrupt));
//void __vector_1(void) __attribute__((signal,used)) __attribute__((naked));
void __vector_2(void) __attribute__((signal,used)) __attribute__((interrupt));
void __vector_3(void) __attribute__((signal,used)) __attribute__((interrupt));
*/
void M_INTERRUPTS_void_Init (void);

#endif