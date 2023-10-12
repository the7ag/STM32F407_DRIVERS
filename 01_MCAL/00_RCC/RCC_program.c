/** - RCC_program.c
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
/*=======================================================================================*/


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	

/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	- Function To Enable Prepheral :
	
							       - Copy_BusName      :  The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/
void MRCC_voidEnableClock(BusName_t Copy_BusName, u8 Copy_u8PeriNum)
{
	switch(Copy_BusName)
	{
		case AHB1_BUS: 	SET_BIT(RCC_AHB1ENR , Copy_u8PeriNum);	break;
		case AHB2_BUS: 	SET_BIT(RCC_AHB2ENR , Copy_u8PeriNum);	break;
		case APB1_BUS: 	SET_BIT(RCC_APB1ENR , Copy_u8PeriNum);	break;
		case APB2_BUS: 	SET_BIT(RCC_APB2ENR , Copy_u8PeriNum);	break;
		default: 		/*ERR*/									break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

 /*
	- Function To Disable Prepheral :
	
							       - Copy_BusName      :  The Bus Of The Prepheral ( AHB1 , AHB2  , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
							       - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
*/
void MRCC_voidDisableClock(BusName_t Copy_BusName, u8 Copy_u8PeriNum)
{
	switch(Copy_BusName)
	{
		case AHB1_BUS: 	CLEAR_BIT(RCC_AHB1ENR , Copy_u8PeriNum);	break;
		case AHB2_BUS: 	CLEAR_BIT(RCC_AHB2ENR , Copy_u8PeriNum);	break;
		case APB1_BUS: 	CLEAR_BIT(RCC_APB1ENR , Copy_u8PeriNum);	break;
		case APB2_BUS: 	CLEAR_BIT(RCC_APB2ENR , Copy_u8PeriNum);	break;
		default: 	/*ERR*/											break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

/*
* Function To Enable Security System
*/

void MRCC_voidEnableClockSecuritySystem(void)
{
	SET_BIT(RCC_CR,CSSON);
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Disable Security System
*/
void MRCC_voidDisableClockSecuritySystem(void)
{
	CLEAR_BIT(RCC_CR,CSSON);
}

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
 */
 
 void MRCC_voidInitSystemClock(void)
{
	/************************************************HSI**************************************************/
	#if CLKSRC==HSI
		/*Enable HSI*/
		SET_BIT(MRCC->CR , 0U);
		/*while( ( ( GET_BIT( MRCC->CR , 1 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ TimeOut }	 */
		/*INPUT SYSTEM CLOCK*/
		CLEAR_BIT(MRCC->CFGR , 0U);
		CLEAR_BIT(MRCC->CFGR , 1U);
	/*************************************************HSE*************************************************/
	#elif CLKSRC==HSE
		#if HSE_SRC == _HSE_CRYSTAL
			/*EMABLE HSE*/
			SET_BIT(MRCC->CR , 16U);
			/*Bit 17 -> Checking While The HSE Clock Is Stable 
			while( ( ( GET_BIT( MRCC->CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
			if( LOC_u32TimeOut >= 100000 ){ TimeOut} */
			/*DISABLE BYPASS*/
			CLEAR_BIT(MRCC->CR , 18U);
			/*INPUT SYSTEM CLOCK*/
			SET_BIT(MRCC->CFGR , 0U);
			CLEAR_BIT(MRCC->CFGR , 1U);
		#elif HSE_SRC == _HSE_RC
			/*EMABLE HSE*/
			SET_BIT(MRCC->CR , 16U);
			/*Bit 17 -> Checking While The HSE Clock Is Stable 
			while( ( ( GET_BIT( MRCC->CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
			if( LOC_u32TimeOut >= 100000 ){ TimeOut} */
			/*ENABLE BYPASS*/
			SET_BIT(MRCC->CR , 18U);
			/*INPUT SYSTEM CLOCK*/
			SET_BIT(MRCC->CFGR , 0U);
			CLEAR_BIT(MRCC->CFGR , 1U);
		#else
			//err
		#endif
	/**************************************************PLL************************************************/
	#elif CLKSRC==PLL
		#if PLL_SRC == _HSE_PLL
			/*EMABLE HSE*/
			SET_BIT(MRCC->CR , 16U);
			/*Disaple PLL*/
			CLEAR_BIT(MRCC->CR,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/*ENABLE HSE PLL SRC*/
			SET_BIT(MRCC->PLLCFGR , 22U);
			/*Enable PLL*/
			SET_BIT(MRCC->CR,24U);
			/*INPUT SYSTEM CLOCK*/
			CLEAR_BIT(MRCC->CFGR , 0U);
			SET_BIT(MRCC->CFGR , 1U);
		#elif PLL_SRC == _HSI_PLL
			/*EMABLE HSI*/
			SET_BIT(MRCC->CR , 0U);
			/*Disaple PLL*/
			CLEAR_BIT(MRCC->CR,24U);
			/* while ( GET_BIT(RCC_CR, 25)==0);*/
			/*ENABLE HSI PLL SRC*/
			CLEAR_BIT(MRCC->PLLCFGR , 22U);
			/*Enable PLL*/
			SET_BIT(MRCC->CR,24U);
			/*INPUT SYSTEM CLOCK*/
			CLEAR_BIT(MRCC->CFGR , 0U);
			SET_BIT(MRCC->CFGR , 1U);
		#endif

	
	/******************************************************************************************************/
	#else
		//err
	#endif
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/


void MRCC_vOutMCO_1(u8 Copy_u8MC1_0SRC )
{
 switch(Copy_u8MC1_0SRC)
 {
	case MC0_1_LSE : 
	        CLEAR_BIT(RCC_CFGR , 22);
			SET_BIT(RCC_CFGR , 21);
	break  ;
	/*********/
	case MC0_1_HSE  :
	
	        CLEAR_BIT(RCC_CFGR , 21);
			SET_BIT(RCC_CFGR , 22);
	break  ;
	/*********/
	case MC0_1_HSI  :
			CLEAR_BIT(RCC_CFGR , 21);
			CLEAR_BIT(RCC_CFGR , 22);
	break  ;
	/*********/
	case  MC0_1_PLL :
	        SET_BIT(RCC_CFGR , 21);
			SET_BIT(RCC_CFGR , 22);
	break  ;
	default :   /* ERROR*/ break ;
	
	
 }

}



/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/


void MRCC_vOutMCO_1Pre(MCO_1_Pre_t Copy_tPreMco_1 )
{
	switch (Copy_tPreMco_1 )
	{
	 case MCO_1_Div_1 :	 
	       CLEAR_BIT(RCC_CFGR , 26);
	 break ; 
	 case MCO_1_Div_2 :	 
		   CLEAR_BIT(RCC_CFGR , 24);
		   CLEAR_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	 case MCO_1_Div_3 :	 
		   SET_BIT(RCC_CFGR , 24);
		   CLEAR_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	  case MCO_1_Div_4 :	 
		   CLEAR_BIT(RCC_CFGR , 24);
		   SET_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
	  case MCO_1_Div_5 :	 
		   SET_BIT(RCC_CFGR , 24);
		   SET_BIT(RCC_CFGR , 25);
	       SET_BIT(RCC_CFGR , 26);
	 break ; 
		
	}

}

/*====================================================   END_ FUNCTION   ====================================================*/


void MRCC_vInitSystemCLK_Systick(u8 Copy_u8Dev)
{
   /* 1- EN HSI */
	SET_BIT(MRCC->CR , 0U);
	/* 2- CLK SYS --> HSI */
	CLEAR_BIT(MRCC->CFGR, 0U);
	CLEAR_BIT(MRCC->CFGR, 1U);
	if(Copy_u8Dev == 1)
	{
		/* Div (AHB/2) */
		RCC_CFGR |=(0b1000<<4U);
		
	}
	else{/* - Misra */}
}
