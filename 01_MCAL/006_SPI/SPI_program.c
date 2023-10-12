/** - SPI_program.c
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
		#include "SPI_private.h"
		#include "SPI_interface.h"
		#include "SPI_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
/* */
void (*MSPI1_CallBack)(void);

/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI_VidInit ( void ){
	
#if   MSPI1_STATUS == MSPI_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
	#if		MSPI1_CLOCK_MODE == MSPI_MODE0
		MSPI1->CR1.CPHA=0;
		MSPI1->CR1.CPOL=0;
	#elif	MSPI1_CLOCK_MODE == MSPI_MODE1
		MSPI1->CR1.CPHA=2;
		MSPI1->CR1.CPOL=0;
	#elif	MSPI1_CLOCK_MODE == MSPI_MODE2

		MSPI1->CR1.CPHA=0;
		MSPI1->CR1.CPOL=1;
	#elif	MSPI1_CLOCK_MODE == MSPI_MODE3
		MSPI1->CR1.CPHA=1;
		MSPI1->CR1.CPOL=1;
	#endif
/*****************       Master selection       *****************/
	#if    MSPI1_MASTER_SLAVE == MSPI_MASTER
		MSPI1->CR1.MSTR=1;
	#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE
		MSPI1->CR1.MSTR=0;
	#endif
/*****************       Frame format       *****************/
	#if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST
		MSPI1->CR1.LSBFIRST=0;
	#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST
		MSPI1->CR1.LSBFIRST=1;
	#endif
/*****************       Software slave management       *****************/
	#if   MSPI1_SSM_MANAGE  == SSM_SWITCH_CLOSE
		MSPI1->CR1.SSM=0;
	#elif MSPI1_SSM_MANAGE == SSM_SWITCH_OPEN
       /* As master pin not connect out */
		MSPI1->CR1.SSM=1;
	#endif
/*****************       SSI VCC OR GROUND only when SET ssm    *****************/
	#if   MSPI1_SSI_MODE  == SSI_GROUND
		MSPI1->CR1.SSI=0;
	#elif MSPI1_SSI_MODE == SSI_VCC
		MSPI1->CR1.SSI=1;
	#endif
/*****************       Data Size        *****************/
   #if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA
		MSPI1->CR1.DFF=0;
	#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA
		MSPI1->CR1.DFF=1;
	#endif
/*****************       Interrput enable | disabled      *****************/
	#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

		/*MSPI_NUM*/ MSPI1 -> CR2 = 0 ;

	#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/  MSPI1 -> CR2 , TXEIE );
	#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/ MSPI1 -> CR2 , RXNEIE );
	#endif
/*****************       Baud rate control      *****************/
		MSPI1->CR1.BR=MSPI1_BAUD_RATE;

/*****************       SPI enable       *****************/
	MSPI1->CR1.SPE=1;
/*****************       SPI disabled       *****************/
#elif MSPI1_STATUS == MSPI_DISABLE
	MSPI1->CR1.SPE=0;
#endif
/******************************************************************************************/
#if   MSPI2_STATUS == MSPI_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
	#if		MSPI2_CLOCK_MODE == MSPI_MODE0
		MSPI2->CR1.CPHA=0;
		MSPI2->CR1.CPOL=0;
	#elif	MSPI2_CLOCK_MODE == MSPI_MODE1
		MSPI2->CR1.CPHA=2;
		MSPI2->CR1.CPOL=0;
	#elif	MSPI2_CLOCK_MODE == MSPI_MODE2

		MSPI2->CR1.CPHA=0;
		MSPI2->CR1.CPOL=1;
	#elif	MSPI2_CLOCK_MODE == MSPI_MODE3
		MSPI2->CR1.CPHA=1;
		MSPI2->CR1.CPOL=1;
	#endif
/*****************       Master selection       *****************/
	#if    MSPI2_MASTER_SLAVE == MSPI_MASTER
		MSPI2->CR1.MSTR=1;
	#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE
		MSPI2->CR1.MSTR=0;
	#endif
/*****************       Frame format       *****************/
	#if   MSPI2_DATA_ORDER == MSPI_MSB_FIRST
		MSPI2->CR1.LSBFIRST=0;
	#elif MSPI2_DATA_ORDER == MSPI_LSB_FIRST
		MSPI2->CR1.LSBFIRST=1;
	#endif
/*****************       Software slave management       *****************/
	#if   MSPI2_SSM_MANAGE  == SSM_SWITCH_CLOSE
		MSPI2->CR1.SSM=0;
	#elif MSPI2_SSM_MANAGE == SSM_SWITCH_OPEN
       /* As master pin not connect out */
		MSPI2->CR1.SSM=1;
	#endif
/*****************       SSI VCC OR GROUND only when SET ssm    *****************/
	#if   MSPI2_SSI_MODE  == SSI_GROUND
		MSPI2->CR1.SSI=0;
	#elif MSPI2_SSI_MODE == SSI_VCC
		MSPI2->CR1.SSI=1;
	#endif
/*****************       Data Size        *****************/
   #if   MSPI2_DATA_SIZE == MSPI_8BIT_DATA
		MSPI2->CR1.DFF=0;
	#elif MSPI2_DATA_SIZE == MSPI_16BIT_DATA
		MSPI2->CR1.DFF=1;
	#endif
/*****************       Interrput enable | disabled      *****************/
	#if   MSPI2_INT_STATUS == MSPI_INT_DISABLE

		/*MSPI_NUM*/ MSPI2 -> CR2 = 0 ;

	#elif MSPI2_INT_STATUS == MSPI_TXE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/  MSPI2 -> CR2 , TXEIE );
	#elif MSPI2_INT_STATUS == MSPI_RXNE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/ MSPI2 -> CR2 , RXNEIE );
	#endif
/*****************       Baud rate control      *****************/
		MSPI2->CR1.BR=MSPI2_BAUD_RATE;

/*****************       SPI enable       *****************/
	MSPI2->CR1.SPE=1;
/*****************       SPI disabled       *****************/
#elif MSPI2_STATUS == MSPI_DISABLE
MSPI2->CR1.SPE=0;
#endif
/*******************************************************************************/
#if   MSPI3_STATUS == MSPI_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
	#if		MSPI3_CLOCK_MODE == MSPI_MODE0
		MSPI3->CR1.CPHA=0;
		MSPI3->CR1.CPOL=0;
	#elif	MSPI3_CLOCK_MODE == MSPI_MODE1
		MSPI3->CR1.CPHA=2;
		MSPI3->CR1.CPOL=0;
	#elif	MSPI3_CLOCK_MODE == MSPI_MODE2

		MSPI3->CR1.CPHA=0;
		MSPI3->CR1.CPOL=1;
	#elif	MSPI3_CLOCK_MODE == MSPI_MODE3
		MSPI3->CR1.CPHA=1;
		MSPI3->CR1.CPOL=1;
	#endif
/*****************       Master selection       *****************/
	#if    MSPI3_MASTER_SLAVE == MSPI_MASTER
		MSPI3->CR1.MSTR=1;
	#elif  MSPI3_MASTER_SLAVE == MSPI_SLAVE
		MSPI3->CR1.MSTR=0;
	#endif
/*****************       Frame format       *****************/
	#if   MSPI3_DATA_ORDER == MSPI_MSB_FIRST
		MSPI3->CR1.LSBFIRST=0;
	#elif MSPI3_DATA_ORDER == MSPI_LSB_FIRST
		MSPI3->CR1.LSBFIRST=1;
	#endif
/*****************       Software slave management       *****************/
	#if   MSPI3_SSM_MANAGE  == SSM_SWITCH_CLOSE
		MSPI3->CR1.SSM=0;
	#elif MSPI3_SSM_MANAGE == SSM_SWITCH_OPEN
       /* As master pin not connect out */
		MSPI3->CR1.SSM=1;
	#endif
/*****************       SSI VCC OR GROUND only when SET ssm    *****************/
	#if   MSPI3_SSI_MODE  == SSI_GROUND
		MSPI3->CR1.SSI=0;
	#elif MSPI3_SSI_MODE == SSI_VCC
		MSPI3->CR1.SSI=1;
	#endif
/*****************       Data Size        *****************/
   #if   MSPI3_DATA_SIZE == MSPI_8BIT_DATA
		MSPI3->CR1.DFF=0;
	#elif MSPI3_DATA_SIZE == MSPI_16BIT_DATA
		MSPI3->CR1.DFF=1;
	#endif
/*****************       Interrput enable | disabled      *****************/
	#if   MSPI3_INT_STATUS == MSPI_INT_DISABLE

		/*MSPI_NUM*/ MSPI3 -> CR2 = 0 ;

	#elif MSPI3_INT_STATUS == MSPI_TXE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/  MSPI3 -> CR2 , TXEIE );
	#elif MSPI3_INT_STATUS == MSPI_RXNE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/ MSPI3 -> CR2 , RXNEIE );
	#endif
/*****************       Baud rate control      *****************/
		MSPI3->CR1.BR=MSPI3_BAUD_RATE;

/*****************       SPI enable       *****************/
	MSPI3->CR1.SPE=1;
/*****************       SPI disabled       *****************/
#elif MSPI3_STATUS == MSPI_DISABLE
	MSPI3->CR1.SPE=0;
#endif
/**************************************************************************************************************/

#if   MSPI4_STATUS == MSPI_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
	#if		MSPI4_CLOCK_MODE == MSPI_MODE0
		MSPI4->CR1.CPHA=0;
		MSPI4->CR1.CPOL=0;
	#elif	MSPI4_CLOCK_MODE == MSPI_MODE1
		MSPI4->CR1.CPHA=2;
		MSPI4->CR1.CPOL=0;
	#elif	MSPI4_CLOCK_MODE == MSPI_MODE2

		MSPI4->CR1.CPHA=0;
		MSPI4->CR1.CPOL=1;
	#elif	MSPI4_CLOCK_MODE == MSPI_MODE3
		MSPI4->CR1.CPHA=1;
		MSPI4->CR1.CPOL=1;
	#endif
/*****************       Master selection       *****************/
	#if    MSPI4_MASTER_SLAVE == MSPI_MASTER
		MSPI4->CR1.MSTR=1;
	#elif  MSPI4_MASTER_SLAVE == MSPI_SLAVE
		MSPI4->CR1.MSTR=0;
	#endif
/*****************       Frame format       *****************/
	#if   MSPI4_DATA_ORDER == MSPI_MSB_FIRST
		MSPI4->CR1.LSBFIRST=0;
	#elif MSPI4_DATA_ORDER == MSPI_LSB_FIRST
		MSPI4->CR1.LSBFIRST=1;
	#endif
/*****************       Software slave management       *****************/
	#if   MSPI4_SSM_MANAGE  == SSM_SWITCH_CLOSE
		MSPI4->CR1.SSM=0;
	#elif MSPI4_SSM_MANAGE == SSM_SWITCH_OPEN
       /* As master pin not connect out */
		MSPI4->CR1.SSM=1;
	#endif
/*****************       SSI VCC OR GROUND only when SET ssm    *****************/
	#if   MSPI4_SSI_MODE  == SSI_GROUND
		MSPI4->CR1.SSI=0;
	#elif MSPI4_SSI_MODE == SSI_VCC
		MSPI4->CR1.SSI=1;
	#endif
/*****************       Data Size        *****************/
   #if   MSPI4_DATA_SIZE == MSPI_8BIT_DATA
		MSPI4->CR1.DFF=0;
	#elif MSPI4_DATA_SIZE == MSPI_16BIT_DATA
		MSPI4->CR1.DFF=1;
	#endif
/*****************       Interrput enable | disabled      *****************/
	#if   MSPI4_INT_STATUS == MSPI_INT_DISABLE

		/*MSPI_NUM*/ MSPI4 -> CR2 = 0 ;

	#elif MSPI4_INT_STATUS == MSPI_TXE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/  MSPI4 -> CR2 , TXEIE );
	#elif MSPI4_INT_STATUS == MSPI_RXNE_INT_ENABLE
		SET_BIT(/*MSPI_NUM*/ MSPI4 -> CR2 , RXNEIE );
	#endif
/*****************       Baud rate control      *****************/
		MSPI4->CR1.BR=MSPI4_BAUD_RATE;

/*****************       SPI enable       *****************/
	MSPI4->CR1.SPE=1;
/*****************       SPI disabled       *****************/
#elif MSPI4_STATUS == MSPI_DISABLE
	MSPI4->CR1.SPE=0;
#endif
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

/* */
SPI_t MSPI_GetHandler(u8 Copy_u8SPIIndex)
{
	SPI_REG L_handle= (SPI_REG) SPI1_BASE_ADDRESS;
	switch (copy_u8Index)
	{   /* */
		case 1: L_handle =  (SPI_REG) SPI1_BASE_ADDRESS; break;
		/* */
		case 2: L_handle =  (SPI_REG) SPI2_BASE_ADDRESS; break;
		/* */
		case 3: L_handle =  (SPI_REG) SPI3_BASE_ADDRESS; break;
		/* */
		case 4: L_handle =  (SPI_REG) SPI4_BASE_ADDRESS; break;
		default : /* */ break;
	}
	return L_handle;
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/


void MSPI_vEnable(u8 Copy_u8SPIIndex)
{
	switch(Copy_u8SPIIndex)
	{
		case 1:	MSPI1->CR1.SPE=1;  break;
		case 2: MSPI2->CR1.SPE=1;  break;
		case 3:	MSPI3->CR1.SPE=1;  break;
		case 4:	MSPI4->CR1.SPE=1; break;
		default : /* */ break;
	}
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI_vDisable(u8 Copy_u8SPIIndex)
{
	switch(Copy_u8SPIIndex)
	{
		case 1:	MSPI1->CR1.SPE=0;  break;
		case 2: MSPI2->CR1.SPE=0;  break;
		case 3:	MSPI3->CR1.SPE=0;  break;
		case 4:	MSPI4->CR1.SPE=0; break;
		default : /* */ break;
	}	
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

u16 MSPI_u16TrasRes(u8 Copy_u8SPIIndex , u16 Copy_u16Data )
{
	SPI_REG L_handle= MSPI_GetHandler(Copy_u8SPIIndex);
	 /* Write data in DR */
	/*MSPI_NUM*/ L_handle -> DR = Copy_u16Data;
      /* Wait BSY : SPIis busy in communication or Tx buffer is not empty
             This flag is set and cleared by hardware */
	while ( GET_BIT( /*MSPI_NUM*/ L_handle -> SR , BSY ) == 1 );
     /* Return data From DR */
	return (u16)/*MSPI_NUM*/  L_handle -> DR ;
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void MSPI1_vSetCallBack( void (* ptr)(void) )
{
	MSPI1_CallBack=ptr;
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}
/*********************************************************** END_ FUNCTION   *********************************************************/