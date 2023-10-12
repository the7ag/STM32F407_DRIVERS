/** - USART_interface.h
	- Created 12/08/2023
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
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/*===========  Include  ===========*/
#include "STD_TYPES.h"
#include "USART_private.h"


/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/
/*********************************/
#define U_ENABLE              1U         /*!< -  */ 
#define U_DISABLE             0U         /*!< -  */ 
/*********************************/
#define U_EVEN_PARITY         0U         /*!< -  */ 
#define U_ODD_PARITY          1U         /*!< -  */ 
/*********************************/
#define U_DATA_8              0U         /*!< -  */ 
#define U_DATA_9              1U         /*!< -  */ 
/*********************************/
#define U_OVER_SAMPLING_16    0U         /*!< -  */ 
#define U_OVER_SAMPLING_8     1U         /*!< -  */ 
/*********************************/
#define STOP_1         		  1U         /*!< -  */ 
#define STOP_05        		  2U         /*!< -  */ 
#define STOP_2         		  3U         /*!< -  */ 
#define STOP_1_05      		  4U         /*!< -  */ 
/*********************************/
typedef enum{
    B_1200   = 0x44505400,           	/*!< -  */ 
    B_2400   = 0x43d05800,           	/*!< -  */ 
    B_9600   = 0x0683,               	/*!< -  */ 
    B_19200  = 0x42504000,           	/*!< -  */ 
    B_38400  = 0x41d08000,           	/*!< -  */ 
    B_57600  = 0x418b0000,           	/*!< -  */ 
    B_115200 = 0x410b0000            	/*!< -  */ 
}u_BaudRate_t;                 
/*********************************/
/*===========================     Function Prototypes     ===========================*/
/*===============   1-Function To 	 ===============*/
void MUART_vInit(void);
/*===============   2-Function To 	 ===============*/
void MUART_vEnable(u8 copy_u8Index);
/*===============   3-Function To 	 ===============*/
void MUART_vDisable(u8 copy_u8Index);
/*===============   4-Function To 	 ===============*/
void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len);
/*===============   5-Function To 	 ===============*/
u8 MUART_u8ReadData(u8 copy_u8Index);
/*===============   6-Function To 	 ===============*/
UART_REG MUART_GetHandler(u8 copy_u8Index);
/*===============   7-Function To 	 ===============*/
void USART1_IRQHandler(void);
/*===============   8-Function To 	 ===============*/
void MUSART1_VidSetCallBack( void (*ptr) (void) );
/*===============   9-Function To 	 ===============*/
void MUART_vSendChar(u8 copy_u8Index , u8 Copy_u8Char);
/*===============   10-Function To 	 ===============*/
void MUART_vSendString(u8 copy_u8Index , u8* Copy_u8Data);





#endif /* USART_INTERFACE_H */