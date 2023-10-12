/** - RCC_config.h
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*
CLKSRC config:
			-HSI
			-HSE
			-PLL
*/
#define CLKSRC HSI

/*
HSE_SRC config:
			-_HSE_CRYSTAL
			-_HSE_RC
			
*/
#define HSE_SRC _HSE_CRYSTAL

/*
PLL config:
			-_HSE_PLL
			-_HSI_PLL
*/
#define PLL_SRC _HSE_PLL

#endif