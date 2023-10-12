/** - DMA_program.c
	- Created 09/08/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "DMA_private.h"
		#include "DMA_interface.h"
		#include "DMA_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	

/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function To init DMA(2)--> Stream(0) By :

									1 - SoftWare Priority Stream : VeryHigh   	      .
									2 - Set DIR Mode             : ( M T M )    	  .
									3 - Set S & D SIZE BIT       : (Word) =32 bit	  . 
									4 - Disable Direct Mode to used FIFO              .
									5 - Set FIFO Threshold       :  (Use full)	      .
									6 - SRC & DIS Increament     : S & D              .
									7 - EN Interrput Of 		 : Transfer Complete  .
 												
					*/
					
void MDMA_vStreamInit(u8 Copy_u8DMAID , u8 Copy_StreamID);
{
	switch(Copy_u8DMAID)
	{
		case _DMA_1:
			/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
			if( (DMA_1->StreamID[Copy_StreamID].CR) == 1U)
			{
					/* Disable It*/
				DMA_1->StreamID[Copy_StreamID].CR &=~(1U<<0U);
				/*It Take Time To Be Disable So Wait Time */
				while((DMA_1->StreamID[Copy_StreamID].CR) == 1U){}
			}
			else { /* For Misra */}
			/*******************************************************************************/
			/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Memory To Memory Not Use bits from 25 to 27*/ 
			// (DMA_1-> StreamID[Copy_StreamID].CR)|= ; // not used 
			/*******************************************************************************/
			/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
			DMA_1->StreamID[Copy_StreamID].CR |=(1U<<16U)|(1<<17U);
			/*******************************************************************************/
			/* 4- Set DIR Mode :{ ( MTM ) ,PTM ,MTP} BIT (6,7) */
			DMA_1->StreamID[Copy_StreamID].CR 	&=~	(1U<<7U);
			DMA_1->StreamID[Copy_StreamID].CR 	|= 	(1U<<6U);
			/*******************************************************************************/
			/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
			/* 	As Word 32 For Source	*/ 
			DMA_1->StreamID[Copy_StreamID].CR 	&=~	(1U<<11U);
			DMA_1->StreamID[Copy_StreamID].CR 	|=	(1U<<12U);
						/* 	As Word 32 For Distination	*/
			DMA_1->StreamID[Copy_StreamID].CR 	&=~	(1U<<13U);
			DMA_1->StreamID[Copy_StreamID].CR 	|=	(1U<<14U);
			/*******************************************************************************/
			/* 6- Disable Direct Mode to used FIFO  */
			DMA_1->StreamID[Copy_StreamID].FCR 	|=	(1U<<2U);
			/*******************************************************************************/
			/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
						/* (Use full)*/
			DMA_1->StreamID[Copy_StreamID].FCR 	|=	(1U<<0U) | (1U<<1U);
			/*******************************************************************************/
			/* 8-SRC & DIS Increament For Both */
			DMA_1->StreamID[Copy_StreamID].CR 	|=	(1U<<9U) | (1U<<10U);
			/*******************************************************************************/
			/* 9- EN Interrput Of (Transfer Complete) or(   ,  ,  , )  */
			DMA_1->StreamID[Copy_StreamID].CR 	|=	(1U<<4U);
			break;
			/*******************************************************************************/
					/**************************************/
		case _DMA_2:
			/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
			if( (DMA_2->StreamID[Copy_StreamID].CR) == 1U)
			{
					/* Disable It*/
				DMA_2->StreamID[Copy_StreamID].CR &=~(1U<<0U);
				/*It Take Time To Be Disable So Wait Time */
				while((DMA_1->StreamID[Copy_StreamID].CR) == 1U){}
			}
			else { /* For Misra */}
			/*******************************************************************************/
			/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Memory To Memory Not Use bits from 25 to 27*/ 
			// (DMA_1-> StreamID[Copy_StreamID].CR)|= ; // not used 

			/*******************************************************************************/
			/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
			DMA_2->StreamID[Copy_StreamID].CR |=(1U<<16U)|(1<<17U);
			/*******************************************************************************/
			/* 4- Set DIR Mode :{ ( MTM ) ,PTM ,MTP} BIT (6,7) */
			DMA_2->StreamID[Copy_StreamID].CR 	&=~	(1U<<7U);
			DMA_2->StreamID[Copy_StreamID].CR 	|= 	(1U<<6U);
			/*******************************************************************************/
			/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
			/* 	As Word 32 For Source	*/ 
			DMA_2->StreamID[Copy_StreamID].CR 	&=~	(1U<<11U);
			DMA_2->StreamID[Copy_StreamID].CR 	|=	(1U<<12U);
						/* 	As Word 32 For Distination	*/
			DMA_2->StreamID[Copy_StreamID].CR 	&=~	(1U<<13U);
			DMA_2->StreamID[Copy_StreamID].CR 	|=	(1U<<14U);
			/*******************************************************************************/
			/* 6- Disable Direct Mode to used FIFO  */
			DMA_2->StreamID[Copy_StreamID].FCR 	|=	(1U<<2U);
			/*******************************************************************************/
			/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
						/* (Use full)*/
			DMA_2->StreamID[Copy_StreamID].FCR 	|=	(1U<<0U) | (1U<<1U);
			/*******************************************************************************/
			/* 8-SRC & DIS Increament For Both */
			DMA_2->StreamID[Copy_StreamID].CR 	|=	(1U<<9U) | (1U<<10U);
			/*******************************************************************************/
			/* 9- EN Interrput Of (Transfer Complete) or(   ,  ,  , )  */
			DMA_2->StreamID[Copy_StreamID].CR 	|=	(1U<<4U);
		break;
	}
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/* Function :	To Set Addrese Of Source & Distination , block size*/
void MDMA_vSetAdresses(u8 Copy_u8DMAID, u8 Copy_StreamID, u32 * Ptr_SrcAdd ,u32 * Ptr_DisAdd , u32 Copy_u32Size )
{
	switch(Copy_u8DMAID)
	{
		case _DMA_1:
			/* 1- Set the Source port register address in the DMA_SxPAR register.*/
			DMA_1->StreamID[Copy_StreamID].PAR 	=	(u32)Ptr_SrcAdd;
			/* 2- Set the Distination  address in the DMA_SxMA0R register */
			DMA_1->StreamID[Copy_StreamID].M0AR =	(u32)Ptr_DisAdd;
			/* 3- Configure the total number of data items to be transferred in the DMA_SxNDTR register.   */
			DMA_1->StreamID[Copy_StreamID].NDTR =	(u32)Copy_u32Size;
		break;
		case _DMA_2:
			/* 1- Set the Source port register address in the DMA_SxPAR register.*/
			DMA_2->StreamID[Copy_StreamID].PAR 	=	(u32)Ptr_SrcAdd;
			/* 2- Set the Distination  address in the DMA_SxMA0R register */
			DMA_2->StreamID[Copy_StreamID].M0AR =	(u32)Ptr_DisAdd;
			/* 3- Configure the total number of data items to be transferred in the DMA_SxNDTR register.   */
			DMA_2->StreamID[Copy_StreamID].NDTR =	(u32)Copy_u32Size;
		break;

	}
}
/*********************************************************** END_ FUNCTION   *********************************************************/
/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function :	Enable DMA  
*/
void MDMA_vEnable(u8 Copy_u8DMAID , u8 Copy_StreamID)
{
	switch(Copy_u8DMAID)
	{
		case _DMA_1:
		/* All Flag == 0 or make them =0 */
		switch(Copy_StreamID)
		{
			case 0:	(DMA_1->LIFCR)|=((1U<<0U)|(1U<<2U)|(1U<<3U)|(1U<<4U)|(1U<<5U);  break;
			case 1:	(DMA_1->LIFCR)|=((1U<<6U)|(1U<<8U)|(1U<<9U)|(1U<<10U)|(1U<<11U);  break;
			case 2:	(DMA_1->LIFCR)|=((1U<<16U)|(1U<<18U)|(1U<<19U)|(1U<<20U)|(1U<<21U);  break;
			case 3:	(DMA_1->LIFCR)|=((1U<<22U)|(1U<<24U)|(1U<<25U)|(1U<<26U)|(1U<<27U);  break;
			case 4:	(DMA_1->HIFCR)|=((1U<<0U)|(1U<<2U)|(1U<<3U)|(1U<<4U)|(1U<<5U);  break;
			case 5:	(DMA_1->HIFCR)|=((1U<<6U)|(1U<<8U)|(1U<<9U)|(1U<<10U)|(1U<<11U);  break;
			case 6:	(DMA_1->HIFCR)|=((1U<<16U)|(1U<<18U)|(1U<<19U)|(1U<<20U)|(1U<<21U);  break;
			case 7:	(DMA_1->HIFCR)|=((1U<<22U)|(1U<<24U)|(1U<<25U)|(1U<<26U)|(1U<<27U);  break;
		}
		 /* EN Bit One Way To Stearm */
		DMA_1->StreamID[Copy_StreamID].CR|=(1U<<0U);
		break;
		case _DMA_2:
		/* All Flag == 0 or make them =0 */
		switch(Copy_StreamID)
		{
			case 0:	(DMA_2->LIFCR)|=((1U<<0U)|(1U<<2U)|(1U<<3U)|(1U<<4U)|(1U<<5U);  break;
			case 1:	(DMA_2->LIFCR)|=((1U<<6U)|(1U<<8U)|(1U<<9U)|(1U<<10U)|(1U<<11U);  break;
			case 2:	(DMA_2->LIFCR)|=((1U<<16U)|(1U<<18U)|(1U<<19U)|(1U<<20U)|(1U<<21U);  break;
			case 3:	(DMA_2->LIFCR)|=((1U<<22U)|(1U<<24U)|(1U<<25U)|(1U<<26U)|(1U<<27U);  break;
			case 4:	(DMA_2->HIFCR)|=((1U<<0U)|(1U<<2U)|(1U<<3U)|(1U<<4U)|(1U<<5U);  break;
			case 5:	(DMA_2->HIFCR)|=((1U<<6U)|(1U<<8U)|(1U<<9U)|(1U<<10U)|(1U<<11U);  break;
			case 6:	(DMA_2->HIFCR)|=((1U<<16U)|(1U<<18U)|(1U<<19U)|(1U<<20U)|(1U<<21U);  break;
			case 7:	(DMA_2->HIFCR)|=((1U<<22U)|(1U<<24U)|(1U<<25U)|(1U<<26U)|(1U<<27U);  break;
		}
		/* EN Bit One Way To Stearm */
		DMA_2->StreamID[Copy_StreamID].CR|=(1U<<0U);
		break;
	}
}
/*********************************************************** END_ FUNCTION   *********************************************************/