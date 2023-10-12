/** - USART_program.c
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
		#include "USART_private.h"
		#include "USART_interface.h"
		#include "USART_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
/* */
void (*MUSART1_CallBack)(void);

/*====================================================   Start_FUNCTION   ====================================================*/
/******************************************************************************
* \Syntax          : void MUART_vInit(void)      
* \Description     :                                        
* \Sync\Async      :                              
* \Reentrancy      :                          
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   :                                  
*******************************************************************************/
void MUART_vInit(void){
	/*===========	UART_1	 ===========*/
	#if (UART1_USED == U_ENABLE)
		/*1)   */
		UART1_REG->CR1.SBK = UART1_SEND_BREAK;
		/*2)  */
		UART1_REG->CR1.RE = UART1_RECEIVER;
		/*3)  */
		UART1_REG->CR1.TE = UART1_TRANSMITTER;
		/*4)  */
		UART1_REG->CR1.RXNEIE = UART1_RX_INT;
		/*5)  */
		UART1_REG->CR1.TCIE = UART1_T_COMP_INT;
		/*6)  */
		UART1_REG->CR1.PCE = UART1_PARITY_ENABLE;
		/*7)  */
		UART1_REG->CR1.PS = UART1_PARITY_MODE;
		/*8)  */
		UART1_REG->CR1.M = UART1_WORD_LEN;
		/*9)  */
		UART1_REG->CR1.OVER8	= UART1_OVER_SAMPLING;
		/*10)  */
		UART1_REG->BRR = UART1_BUAD_RATE;
		/*11)  */
		UART1_REG->CR2 |= (UART1_STOP_BITS << 12);
	#endif
	   /*===========	UART_2	 ===========*/
	#if (UART2_USED == U_ENABLE)
		/*1)   */
		UART2_REG->CR1.SBK = UART2_SEND_BREAK;
		/*2)  */
		UART2_REG->CR1.RE = UART2_RECEIVER;
		/*3)  */
		UART2_REG->CR1.TE = UART2_TRANSMITTER;
		/*4)  */
		UART2_REG->CR1.RXNEIE = UART2_RX_INT;
		/*5)  */
		UART2_REG->CR1.TCIE = UART2_T_COMP_INT;
		/*6)  */
		UART2_REG->CR1.PCE = UART2_PARITY_ENABLE;
		/*7)  */
		UART2_REG->CR1.PS = UART2_PARITY_MODE;
		/*8)  */
		UART2_REG->CR1.M = UART2_WORD_LEN;
		/*9)  */
		UART2_REG->CR1.OVER8	= UART2_OVER_SAMPLING;
		/*10)  */
		UART2_REG->BRR = UART2_BUAD_RATE;
		/*11)  */
		UART2_REG->CR2 |= (UART2_STOP_BITS << 12);
	#endif
   /*===========	UART_6	 ===========*/
	#if (UART6_USED == U_ENABLE)
		/*1)   */
		UART6_REG->CR1.SBK = UART6_SEND_BREAK;
		/*2)  */
		UART6_REG->CR1.RE = UART6_RECEIVER;
		/*3)  */
		UART6_REG->CR1.TE = UART6_TRANSMITTER;
		/*4)  */
		UART6_REG->CR1.RXNEIE = UART6_RX_INT;
		/*5)  */
		UART6_REG->CR1.TCIE = UART6_T_COMP_INT;
		/*6)  */
		UART6_REG->CR1.PCE = UART6_PARITY_ENABLE;
		/*7)  */
		UART6_REG->CR1.PS = UART6_PARITY_MODE;
		/*8)  */
		UART6_REG->CR1.M = UART6_WORD_LEN;
		/*9)  */
		UART6_REG->CR1.OVER8	= UART6_OVER_SAMPLING;
		/*10)  */
		UART6_REG->BRR = UART6_BUAD_RATE;
		/*11)  */
		UART6_REG->CR2 |= (UART6_STOP_BITS << 12);
	#endif
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void MUART_vEnable(u8 copy_u8Index){
	/*1) */
	switch(copy_u8Index){
		/* */
		case 1: UART1_REG -> CR1.UE = 1; break;
		/* */
		case 2: UART2_REG -> CR1.UE = 1; break;
		/* */
		case 6: UART6_REG -> CR1.UE = 1; break;
		/* */
		default : /* */ break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void MUART_vDisable(u8 copy_u8Index){
	/* */
	switch (copy_u8Index)
	{   /* */
		case 1: UART1_REG -> CR1.UE = 0; break;
		/* */
		case 2: UART2_REG -> CR1.UE = 0; break;
		/* */
		case 6: UART6_REG -> CR1.UE = 0; break;
		/* */
		default : /* */ break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :SYNCH DATA SEND
*
*/
void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len){
     /* */
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	/* */
	for(u8 counter = 0; counter < copy_u8Len; counter++){
		uhandler ->DR = copy_u8Data[counter];
		/* */
		while(!GET_BIT(uhandler->SR, 6));
	} 
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
u8 MUART_u8ReadData(u8 copy_u8Index){
	/* */
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	/* */
	return (u8) uhandler->DR;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
UART_REG MUART_GetHandler(u8 copy_u8Index){
	/* */
	UART_REG L_handle= (UART_REG) UART1_BASE_ADDRESS;
	switch (copy_u8Index)
	{   /* */
		case 1: L_handle =  (UART_REG) UART1_BASE_ADDRESS; break;
		/* */
		case 2: L_handle =  (UART_REG) UART2_BASE_ADDRESS; break;
		/* */
		case 6: L_handle =  (UART_REG) UART6_BASE_ADDRESS; break;
		default : /* */ break;
	}
	return L_handle;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/

void MUSART1_VidSetCallBack( void (*ptr) (void) ){
    /* */
	MUSART1_CallBack = ptr ;

}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function :
*
*/
void USART1_IRQHandler(void){
    /* */
	UART1_REG -> SR = 0 ;
	/* */
	MUSART1_CallBack();

}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MUART_vSendChar(u8 copy_u8Index ,u8 Copy_u8Char)
{
	UART_REG uhandler = MUART_GetHandler(copy_u8Index);
	uhandler ->DR = Copy_u8Char;
		/* */
	while(!GET_BIT(uhandler->SR, 6));
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MUART_vSendString(u8 copy_u8Index , u8* Copy_u8Data)
{
	u8 L_counter=0;
	while(Copy_u8Data[L_counter] != '\0')
	{
	MUART_vSendChar(copy_u8Index ,Copy_u8Data[L_counter]);
	L_counter++;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
