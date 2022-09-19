/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	23 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*  Register Base addresses Definitions  */

/* PORT A Registers  */	
#define DDRA			*((volatile u8*)(0x003A))
#define PORTA			*((volatile u8*)(0x003B))
#define PINA			*((volatile u8*)(0x0039))


/* PORT B Registers  */	
#define DDRB			*((volatile u8*)(0x0037))
#define PORTB			*((volatile u8*)(0x0038))
#define PINB			*((volatile u8*)(0x0036))



/* PORT C Registers  */	
#define DDRC			*((volatile u8*)(0x0034))
#define PORTC			*((volatile u8*)(0x0035))
#define PINC			*((volatile u8*)(0x0033))

/* PORT C Registers  */	
#define DDRD			*((volatile u8*)(0x0031))
#define PORTD			*((volatile u8*)(0x0032))
#define PIND			*((volatile u8*)(0x0030))
	

/* SFIOR special function Register  */	
#define SFIOR			*((volatile u8*)(0x0050))

#endif