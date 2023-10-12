/** - RCC_interface.h
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*
	Config RCC Enum
	- Crystal CLK SRC (RCC_HSE : External ,RCC_HSI : Internal  ,RCC_PLL Use_PLL) ---->ClkSrcName_t
	- For External Crystal CLK From (HSE_Crystal , HSE_RC )--->HSESrcName_t
	- For PLL Can Be For (HSE , HSI) --------->PllSrcName_t
	- PLL  Prescaller ( M /(2:63) N*(50:432) P Q )               ---> User Select By #define                  
	- AHB  Prescaller ( 1 : 512 )  							---> AHBPreName_t
	- APB1 Prescaller (1  : 16)    							---> APB1_Prescaller
	- APB2_Prescaller (1  : 16)    							---> APB2_Prescaller
	- Select Bus ( AHB1 AHB2 AHB3 APB1  APB2 )  --->BusName_t
         
	*/
	/**********  APH1_Prescaller   **********/
	typedef enum 
	{
		AHB_Pre1 = 0 , 			// No Action
		AHB_Pre2	 ,
		AHB_Pre4	 ,
		AHB_Pre8	 ,
		AHB_Pre16	 ,
		AHB_Pre32	 ,
		AHB_Pre64	 ,
		AHB_Pre128	 ,
		AHB_Pre256	 ,
		AHB_Pre512	 
		
	}AHBPreName_t;
/**********  APB1_Prescaller   **********/
	typedef enum
	{
		ABP1_Pre1 = 0 ,
		ABP1_Pre2	 ,
		ABP1_Pre4	 ,
		ABP1_Pre8	 ,
		ABP1_Pre16	 
	}APB1PreName_t ;
	
/**********   APB2_Prescaller   **********/ 
	typedef enum
	{
		ABP2_Pre1 = 0 ,
		ABP2_Pre2	 ,
		ABP2_Pre4	 ,
		ABP2_Pre8	 ,
		ABP2_Pre16
	}APB2PreName_t ;
	/**************/
typedef enum {
	AHB1=0U,
	AHB2,
	APB1,
	APB2
}BusName_t;

/********************CLK SRC*********************/
typedef enum {
	RCC_HSI=0U,
	RCC_HSE,
	RCC_PLL
}CLKSrcName_t;
/********************************/
typedef enum {
	HSE_PLL=0U,
	HSI_PLL
}PLLSrc_t;
/*********************************/
typedef enum {
	HSE_CRYSTAL=0U,
	HSE_RC
}HSESrc_t;
/***********************************/

/* MCO_1 Prescaller */
typedef enum
{
	MCO_1_Div_1 =0 ,
	MCO_1_Div_2    ,
	MCO_1_Div_3    ,
	MCO_1_Div_4    ,
	MCO_1_Div_5    ,

}MCO_1_Pre_t;

/******************************************/

#define AHB1_BUS  0U
#define AHB2_BUS  1U
#define APB1_BUS  2U
#define APB2_BUS  3U


/****************************************/
#define HSI 					0U
#define HSE 					1U
#define PLL 					2U
/****************************************/
#define _HSE_CRYSTAL 			0U
#define _HSE_RC					1U
/****************************************/
#define _HSE_PLL				0U
#define _HSI_PLL				1U
/****************************************/
/**********   **********/
#define MC0_1_LSE   0U
#define MC0_1_HSE   1U
#define MC0_1_HSI   2U
#define MC0_1_PLL   3U
/***************************/


/*
-Fnction To Enable Prephiral
		-Copy_BusName:The name of the bus of the prephiral (AHB1 , AHB2 , APB1 , APB2)
		-COPY_u8PeriNum: The Number of the Prephiral
*/

void MRCC_voidEnableClock(BusName_t Copy_BusName, u8 Copy_u8PeriNum);
/*
-Fnction To Disable Prephiral
		-Copy_BusName:The name of the bus of the prephiral (AHB1 , AHB2 , APB1 , APB2)
		-COPY_u8PeriNum: The Number of the Prephiral
*/
void MRCC_voidDisableeClock(BusName_t Copy_BusName, u8 Copy_u8PeriNum);
/*
-Fnction To Enable Clock Security System
*/
void MRCC_voidEnableClockSecuritySystem(void);
/*
-Fnction To Disable Clock Security System
*/
void MRCC_voidDisableClockSecuritySystem(void);
/*
-Function To Set System CLK From Enum Type Send :
												* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL	
												* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
												* AHBPreName_t    : AHB  Prescaller ( 1 : 512 )
												* APB1PreName_t   : APB1 Prescaller ( 1 : 16  )  
												* APB2PreName_t   : APB2_Prescaller ( 1 : 16  ) 
												*( M N P Q )      : By #define .															
*/
void MRCC_voidInitClock(CLKSrcName_t Copy_tCLKSrc , HSESrc_t Copy_tHSESrc , PLLSrc_t Copy_tPLLSrc);
/* Function To Set System CLK  */
void MRCC_voidInitSystemClock(void);

/*Function To Set MCO_1 Output  */
void MRCC_vOutMCO_1(u8 Copy_u8MC1_0SRC );
/*Function To Set MCO_1 Output Prescaller */
void MRCC_vOutMCO_1Pre(MCO_1_Pre_t Copy_tPreMco_1 );

/*********** Macros Of :- RCC AHB1 CLK ENABLE ***************/

#define _PERIPHERAL_EN_GPIOA     0U 
#define _PERIPHERAL_EN_GPIOB     1U 
#define _PERIPHERAL_EN_GPIOC     2U            
#define _PERIPHERAL_EN_GPIOD     3U 
#define _PERIPHERAL_EN_GPIOE     4U 
#define _PERIPHERAL_EN_GPIOH     7U 
#define _PERIPHERAL_EN_CRCEN     12U 
#define _PERIPHERAL_EN_DMA1EN    21U 
#define _PERIPHERAL_EN_DMA2EN    22U 


/********* Macros Of :- RCC APB1 peripheral clock enable register *********/

#define PERIPHERAL_EN_TIM2						0U
#define PERIPHERAL_EN_TIM3						1U
#define PERIPHERAL_EN_TIM4						2U
#define PERIPHERAL_EN_TIM5					    3U
#define PERIPHERAL_EN_TIM6						4U
#define PERIPHERAL_EN_TIM7						5U
#define PERIPHERAL_EN_TIM12					    6U
#define PERIPHERAL_EN_TIM13					    7U
#define PERIPHERAL_EN_TIM14					    8U
#define PERIPHERAL_EN_WWDG						11U
#define PERIPHERAL_EN_SPI2						14U
#define PERIPHERAL_EN_SPI3						15U
#define PERIPHERAL_EN_UART2						17U
#define PERIPHERAL_EN_UART3						18U
#define PERIPHERAL_EN_UART4						19U
#define PERIPHERAL_EN_UART5						20U
#define PERIPHERAL_EN_I2C1						21U
#define PERIPHERAL_EN_I2C2						22U
#define PERIPHERAL_EN_I2C3						23U
#define PERIPHERAL_EN_CAN1						25U
#define PERIPHERAL_EN_CAN2						26U
#define PERIPHERAL_EN_PWR						28U
#define PERIPHERAL_EN_DAC						29U



/**********  Macros Of :- RCC APB2 peripheral clock enable register (RCC_APB2ENR) *********/
			         					
#define PERIPHERAL_EN_TIM1  				 0U
#define PERIPHERAL_EN_TIM8					 1U
#define PERIPHERAL_EN_USART1				 4U
#define PERIPHERAL_EN_USART6				 5U
#define PERIPHERAL_EN_ADC1					 8U
#define PERIPHERAL_EN_ADC2					 9U
#define PERIPHERAL_EN_ADC3					 10U
#define PERIPHERAL_EN_SDIO					 11U
#define PERIPHERAL_EN_SPI1					 12U
#define PERIPHERAL_EN_SYSCFG				 14U
#define PERIPHERAL_EN_TIM9					 16U
#define PERIPHERAL_EN_TIM10					 17U
#define PERIPHERAL_EN_TIM11 				 18U

/*****************************************************************************************/


#endif
