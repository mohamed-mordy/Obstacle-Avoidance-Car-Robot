/****************************************************/
/* AUTHOR		:	 	ABDELWAHED ELBEHEIRY		*/
/* DATE			:   	16 AUG 2020					*/
/* VERSION		: 		V01							*/
/****************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT)			(REG |= (1 << (BIT)))
#define CLR_BIT(REG,BIT)			(REG &= ~(1 << (BIT)))
#define TOG_BIT(REG,BIT)			(REG ^= (1 << (BIT)))
#define GET_BIT(REG,BIT)			((REG >> BIT) & 1 )			/* ((REG&(1<<BIT))>>BIT) */
#define IS_BIT_SET(REG,BIT)			((REG >> BIT) & 1 )
#define IS_BIT_CLR(REG,BIT)			(!((REG >> BIT) & 1 ))
#define ROL(REG,REG_SIZE,BIT)		(REG = (REG >> (REG_SIZE - BIT)) | (REG << BIT))
#define ROR(REG,REG_SIZE,BIT)		(REG = (REG << (REG_SIZE - BIT)) | (REG >> BIT))
#define SET_2BITS(REG,BIT1,BIT2)	(REG |= ( (1 << BIT1) | (1 << BIT2) ) )
#define CLR_2BITS(REG,BIT1,BIT2)	(REG &= ( ~( (1 << BIT1) | (1 << BIT2) ) ) )

#endif