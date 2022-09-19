/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	26 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/* TIMER/COUNTER Register */

/* 8 bit Timer/Counter0 */
#define TCNT0	(*((volatile u8*)(0x52)))

/* 16 bit Timer/Counter1 */
#define TCNT1	(*((volatile u16*)(0x4C)))
#define TCNT1L	(*((volatile u8*)(0x4C)))
#define TCNT1H	(*((volatile u8*)(0x4D)))

/* 8 bit Timer/Counter2 */
#define TCNT2	(*((volatile u8*)(0x44)))



/* TIMER/COUNTER Control Register */

/* 8 bit Timer/Counter0 */
#define TCCR0	(*((volatile u8*)(0x53)))
/* 8 bit Timer/Counter0 Clock Prescalar Selection bits 
CS02-CS01-CS00 - 
Timer/Counter0 as a timer
0 NO Clock Timer/Counter0 stopped - 1 Clk_MC - 2 Clk_MC/8 - 3 Clk_MC/64 - 4 Clk_MC/256 - 5 Clk_MC/1024
Timer/Counter0 as a counter
6 External Clk_Source on T0 pin (Clk on falling edge) - 7 External Clk_Source on T0 pin (Clk on rising edge) */
#define CS00	0
#define CS01	1
#define CS02	2
/* 8 bit Timer/Counter0 Waveform Generation Mode bits 
(WGM01-WGM00 = 00 OVF - 01 PWM_PHASE_CORRECT - 10 CTC - 11 FAST_PWM ) */
#define WGM00	6
#define WGM01	3
/* 8 bit Timer/Counter0 Compare Match Output Mode bits */
#define COM00	4
#define COM01	5
/* 8 bit Timer/Counter0 Force Output Compare bit */
#define FOC0	7



/* 16 bit Timer/Counter1 */
#define TCCR1A	(*((volatile u8*)(0x4F)))
/* TIMER/COUNTER1 MODE SELECTIONS bits of 16 modes */
#define WGM10	0
#define WGM11	1
/* TIMER/COUNTER1 FORCE OUTPUT COMPARE bits */
#define FOC1B	2
#define FOC1A	3
/* TIMER/COUNTER1 Output Compare B CONFIG bits */
#define COM1B0	4
#define COM1B1	5
/* TIMER/COUNTER1 Output Compare A CONFIG bits */
#define COM1A0	6
#define COM1A1	7

#define TCCR1B	(*((volatile u8*)(0x4E)))
/* TIMER/COUNTER1 CLOCK SELECTIONS bits */
#define CS10	0
#define CS11	1
#define CS12	2
/* TIMER/COUNTER1 MODE SELECTIONS bits of 16 modes */
#define WGM12	3
#define WGM13	4
/* BIT5 IS RESERVED */
/* TIMER/COUNTER1 INPUT CAPTURE EDGE SELECTION bit */
#define ICES1	6
/* TIMER/COUNTER1 INPUT CAPTURE NOISE CANCELER bit */
#define ICNC1	7



/* 8 bit Timer/Counter2 */
#define TCCR2	(*((volatile u8*)(0x45)))

// Asynchronous Status Register
#define ASSR	(*((volatile u8*)(0x42)))
#define TCR2UB	0
#define OCR2UB	1
#define	TCN2UB	2
/* if AS2 is zero then Timer/Counter2 is clocked from MC_CLK (I/O_clk),
and if AS2 is one then Timer/Counter2 is clocked from a crystal oscillator connected to Timer Oscillator 1 (TOSC1) pin (PC6),
when the value of AS2 is changed, the contents of TCNT2, OCR2 and TCCR2 might be corrupted. */
#define	AS2		3

/* 8 bit Timer/Counter2 Clock Prescalar Selection bits 
CS22-CS21-CS20 - 
Timer/Counter2 as a timer
0 NO Clock Timer/Counter2 stopped - 1 Clk_T2S - 2 Clk_T2S/8 - 3 Clk_T2S/32 - 4 Clk_T2S/64 - 
5 Clk_T2S/128 - 6 Clk_T2S/256 - 7 Clk_T2S/1024	*/
#define CS20	0
#define CS21	1
#define CS22	2
/* 8 bit Timer/Counter2 Waveform Generation Mode bits 
(WGM21-WGM20 = 00 OVF - 01 PWM_PHASE_CORRECT - 10 CTC - 11 FAST_PWM ) */
#define WGM20	6
#define WGM21	3
/* 8 bit Timer/Counter2 Compare Match Output Mode bits */
#define COM20	4
#define COM21	5
/* 8 bit Timer/Counter2 Force Output Compare bit */
#define FOC2	7


/* TIMER/COUNTER Output Compare Register */

/* 8 bit Timer/Counter0 */
#define OCR0	(*((volatile u8*)(0x5C)))

/* 16 bit Timer/Counter1 */
#define OCR1A	(*((volatile u16*)(0x4A)))
#define OCR1AL	(*((volatile u8*)(0x4A)))
#define OCR1AH	(*((volatile u8*)(0x4B)))
#define OCR1B	(*((volatile u16*)(0x48)))
#define OCR1BL	(*((volatile u8*)(0x48)))
#define OCR1BH	(*((volatile u8*)(0x49)))

/* 16 bit Timer/Counter1 Input Capture Register */
#define ICR1	(*((volatile u16*)(0x46)))
#define ICR1L	(*((volatile u8*)(0x46)))
#define ICR1H	(*((volatile u8*)(0x47)))

/* 8 bit Timer/Counter2 */
#define OCR2	(*((volatile u8*)(0x43)))



/* TIMER/COUNTER Interrupt Mask Register */
#define TIMSK	(*((volatile u8*)(0x59)))
/* TIMER/COUNTER0 Overflow Interrupt Enable bit */
#define TOIE0	0
/* TIMER/COUNTER0 Output Compare Interrupt Enable bit */
#define OCIE0	1
/* TIMER/COUNTER1 Overflow Interrupt Enable bit */
#define TOIE1	2
/* TIMER/COUNTER1 Output Compare Interrupt Enable bit */
#define OCIE1B	3
/* TIMER/COUNTER1 Output Compare Interrupt Enable bit */
#define OCIE1A	4
/* TIMER/COUNTER1 Input Capture Interrupt Enable bit */
#define TICIE1	5
/* TIMER/COUNTER2 Overflow Interrupt Enable bit */
#define TOIE2	6
/* TIMER/COUNTER2 Output Compare Interrupt Enable bit */
#define OCIE2	7


/* TIMER/COUNTER Interrupt Flag Register */
#define TIFR	(*((volatile u8*)(0x58)))
/* TIMER/COUNTER0 Overflow Interrupt flag bit */
#define TOV0	0
/* TIMER/COUNTER0 Output Compare Interrupt flag bit */
#define OCF0	1
/* TIMER/COUNTER1 Overflow Interrupt flag bit */
#define TOV1	2
/* TIMER/COUNTER1 Output Compare B Interrupt flag bit */
#define OCF1B	3
/* TIMER/COUNTER1 Output Compare A Interrupt flag bit */
#define OCF1A	4
/* TIMER/COUNTER1 Input Capture Interrupt flag bit */
#define ICF1	5
/* TIMER/COUNTER2 Overflow Interrupt flag bit */
#define TOV2	6
/* TIMER/COUNTER2 Output Compare Interrupt flag bit */
#define OCF2	7


/*
	If TIMER/COUNTER INPUT CLOCK PRESCALAR (DIVISION FACTOR) is set as 1024 so 
	TIMER/COUNTER INPUT CLOCK = (MC_CLK) 8M/1024 (prescalar) = 8KHZ	
	TIMER/COUNTER Tick Time = (1/8k) = (1/8)ms
	so if in CTC mode for 1sec time we load OCR0 with a value=(1/((1/8)m))= 8000
*/



#endif