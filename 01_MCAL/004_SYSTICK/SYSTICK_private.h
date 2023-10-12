/** - SYSTICK_private.h
	- Created 08/08/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
/*===============================================================================================
*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


/**** Include  ***/
#include "STD_TYPES.h"

typedef struct
{
volatile u32 CTRL ;
volatile u32 LOAD ;
volatile u32 VAL ;	
volatile u32 CALIB ;	
}MSTK_t;

#define SYSTICK_BASE_ADDRESS       0xE000E010
/**/
#define MSTK  ((MSTK_t *) SYSTICK_BASE_ADDRESS )

#endif /* SYSTICK_PRIVATE_H */