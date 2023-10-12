/** - EXTI_private.h
	- Created 06/08/2023
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
					- Struct	:	NO
					
===================================================================================================*/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "STD_TYPE.h"

typedef struct
{
	volatile u32 IMR   ;      /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	volatile u32 EMR   ;      /*!< EXTI Event mask register,                Address offset: 0x04 */
	volatile u32 RTSR  ;      /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	volatile u32 FTSR  ;      /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	volatile u32 SWIER ;      /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	volatile u32 PR    ;      /*!< EXTI Pending register,                   Address offset: 0x14 */
	
	
}EXTI_t;
 


#define _EXTI_BASE_ADDRESS     0x40013C00

#define EXTI                  ((EXTI_t    *)(_EXTI_BASE_ADDRESS ))

#define _SYSCFG_BASE_ADDRESS    0x40013800 

#define SYSCFG_EXTICR1                  (*((u32 *)( _SYSCFG_BASE_ADDRESS  +	0x08    )))     
#define SYSCFG_EXTICR2                  (*((u32 *)( _SYSCFG_BASE_ADDRESS  +	0x0C    )))
#define SYSCFG_EXTICR3                  (*((u32 *)( _SYSCFG_BASE_ADDRESS  +	0x10    )))
#define SYSCFG_EXTICR4                  (*((u32 *)( _SYSCFG_BASE_ADDRESS  +	0x14    )))

#endif /* EXTI_PRIVATE_H */