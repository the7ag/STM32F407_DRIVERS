/** - SYSTICK_interface.h
	- Created 08/08/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#include "STD_TYPES.h"

#define _MSTK_CLK_AHB        0U
#define _MSTK_CLK_AHB_8      1U
/**/
#define _MSTK_SINGLE_        0U
#define _MSTK_PERIODIC       1U


/*	1- Function Only Apply The Clock From Configer ( AHB or( AHB/8---> 1MHZ) So 1 = 1Msec & Disable SysTick Interrupt & Disa-ble SysTick  */
void MSTK_voidInit(void);
/*
	2- Function Take Count or Ticks So Timer Count Them And you Config ( Tick = Time ) MSec  ---> Make Delay (Synchronous_Fun)
*/
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks);
/* 
	3- Function  Return The Remaining Time To Make ISR Only Rad Value REG 
*/
u32 MSTK_u32GetRemainingTime(void);

/* 
	4- Function  Return The Elapsed Time From Start To Count Load Value - Value REG 
*/
u32 MSTK_u32GetElapsedTime(void);

/* 5- The Same Of Function (3) But Only Differant At ISR Will Not Mack Load And Value = 0 */
			 /*  Send Time To Clock it And What Will Call After Time Finsh   */						
		      /* Global Var Take Adress Of Function And
										After Time Out ISR Call The Global_Var Which Point To Function  
*/
								
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void ( *Copy_ptr ) ( void ));
/* 6- Function Asynchronous Take Tick And Start To Count Them , Give Flag And Work One Time ,
		And Give Me Function And i Will Resive In Pointer To Function To Call it After Counting Ticks .
		I Will Tick The Adress Of Function And Give It To Global Var ( Call back )  And ISR D o this Func */				
			/* Only One Time */	

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void ( *Copy_ptr ) ( void ));

/*
	7- Function Will Stop The Interval If It Was Periodic Or Single
*/
void MSTK_voidStopInterval(void) ;


#endif /* SYSTICK_INTERFACE_H */