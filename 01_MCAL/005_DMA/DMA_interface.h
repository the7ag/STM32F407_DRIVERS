/** - DMA_interface.h
	- Created 09/08/2023
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
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


#include "STD_TYPE.h"

/*1- Function To Init DMA : */
void MDMA_vStreamInit(u8 Copy_u8DMAID , u8 Copy_StreamID);
/*2- Function :	To Set Addrese Of Source & Distination , block size*/
void MDMA_vSetAdresses(u8 Copy_u8DMAID, u8 Copy_StreamID, u32 * Ptr_SrcAdd ,u32 * Ptr_DisAdd , u32 Copy_u32Size );
/*3- Function :	To EN_DMA */
void MDMA_vEnable(u8 Copy_u8DMAID , u8 Copy_StreamID);

#define _DMA_1 		0U
#define _DMA_2		1U


#endif /* DMA_INTERFACE_H */