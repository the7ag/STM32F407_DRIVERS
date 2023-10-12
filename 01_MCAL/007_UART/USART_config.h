/** - USART_config.h
	- Created 12/08/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
		*/
/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#include "USART_enums.h"
/*****     UART 1 configurations        ******/
//if you want to use UART 1 Make this enable otherwise its config values will be discarded
#define UART1_USED             U_ENABLE                /*!<U_ENABLE-U_DISABLE  */ 
#define UART1_SEND_BREAK       U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART1_RECEIVER         U_ENABLE                /*!<U_ENABLE-U_DISABLE  */ 
#define UART1_TRANSMITTER      U_ENABLE                /*!< U_ENABLE-U_DISABLE  */ 
#define UART1_T_COMP_INT       U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART1_RX_INT           U_ENABLE                /*!< U_ENABLE-U_DISABLE  */ 
#define UART1_PARITY_ENABLE    U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART1_PARITY_MODE      U_EVEN_PARITY           /*!<U_EVEN_PARITY - U_ODD_PARITY */ 
#define UART1_WORD_LEN         U_DATA_8                /*!<U_DATA_8 - U_DATA_9 */ 
#define UART1_BUAD_RATE        B_9600;                 /*!<B_1200 -B_2400-B_9600-B_19200-B_38400-B_57600-B_115200  */ 
#define UART1_OVER_SAMPLING    U_OVER_SAMPLING_16      /*!< U_OVER_SAMPLING_16-U_OVER_SAMPLING_8  */ 
#define UART1_STOP_BITS        STOP_1                  /*!<STOP_05 -STOP_1 - STOP_1_05 - STOP_2  */ 


/*****     UART 2 configurations        ******/
//if you want to use UART 2 Make this enable otherwise its config values will be discarded
#define UART2_USED             U_DISABLE              /*!<U_ENABLE-U_DISABLE  */ 
#define UART2_SEND_BREAK       U_DISABLE              /*!< U_ENABLE-U_DISABLE  */ 
#define UART2_RECEIVER         U_ENABLE               /*!<U_ENABLE-U_DISABLE  */ 
#define UART2_TRANSMITTER      U_ENABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART2_T_COMP_INT       U_DISABLE              /*!< U_ENABLE-U_DISABLE  */ 
#define UART2_RX_INT           U_DISABLE              /*!< U_ENABLE-U_DISABLE  */ 
#define UART2_PARITY_ENABLE    U_DISABLE              /*!< U_ENABLE-U_DISABLE  */ 
#define UART2_PARITY_MODE      U_EVEN_PARITY          /*!<U_EVEN_PARITY - U_ODD_PARITY */ 
#define UART2_WORD_LEN         U_DATA_8               /*!<U_DATA_8 - U_DATA_9 */ 
#define UART2_BUAD_RATE        B_9600;                /*!<B_1200 -B_2400-B_9600-B_19200-B_38400-B_57600-B_115200  */ 
#define UART2_OVER_SAMPLING    U_OVER_SAMPLING_16     /*!< U_OVER_SAMPLING_16-U_OVER_SAMPLING_8  */ 
#define UART2_STOP_BITS        STOP_1                 /*!<STOP_05 -STOP_1 - STOP_1_05 - STOP_2  */ 



/*****     UART 6 configurations        ******/
//if you want to use UART 6 Make this enable otherwise its config values will be discarded
#define UART6_USED             U_ENABLE                /*!<U_ENABLE-U_DISABLE  */ 
#define UART6_SEND_BREAK       U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART6_RECEIVER         U_ENABLE                /*!<U_ENABLE-U_DISABLE  */ 
#define UART6_TRANSMITTER      U_ENABLE                /*!< U_ENABLE-U_DISABLE  */ 
#define UART6_T_COMP_INT       U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART6_RX_INT           U_ENABLE                /*!< U_ENABLE-U_DISABLE  */ 
#define UART6_PARITY_ENABLE    U_DISABLE               /*!< U_ENABLE-U_DISABLE  */ 
#define UART6_PARITY_MODE      U_EVEN_PARITY           /*!<U_EVEN_PARITY - U_ODD_PARITY */ 
#define UART6_WORD_LEN         U_DATA_8                /*!<U_DATA_8 - U_DATA_9 */ 
#define UART6_BUAD_RATE        B_9600;                 /*!<B_1200 -B_2400-B_9600-B_19200-B_38400-B_57600-B_115200  */ 
#define UART6_OVER_SAMPLING    U_OVER_SAMPLING_16      /*!< U_OVER_SAMPLING_16-U_OVER_SAMPLING_8  */ 
#define UART6_STOP_BITS        STOP_1                  /*!<STOP_05 -STOP_1 - STOP_1_05 - STOP_2  */ 




#endif /* USART_CONFIG_H */