/** - RCC_private.h
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*
--------------> MACROS
				*Base Address is (RCC) 0x40023800
*/
#define MRCC_BASE_ADDRESS  	0x40023800

/*RCC REGISTERS*/
#define RCC_CR 				(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x00) )))
#define ٌ RCC_PLLCFGR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x04) )))
#define RCC_CFGR 			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x08) )))
#define RCC_CIR 			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x0C) )))
#define RCC_AHB1RSTR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x10) )))
#define RCC_AHB2RSTR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x14) )))
#define RCC_APB1RSTR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x20) )))
#define RCC_APB2RSTR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x24) )))
#define RCC_AHB1ENR			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x30) )))
#define RCC_AHB2ENR			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x34) )))
#define RCC_APB1ENR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x40) )))
#define RCC_APB2ENR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x44) )))
#define RCC_AHB1LPENR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x50) )))
#define RCC_AHB2LPENR		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x54) )))
#define RCC_APB1LPENR		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x60) )))
#define RCC_APB2LPENR 		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x64) )))
#define RCC_BDCR			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x70) )))
#define RCC_CSR 			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x74) )))
#define RCC_SSCGR 			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x80) )))
#define RCC_PLLI2SCFGR		(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x84) )))
#define RCC_DCKCFGR			(*((volatile u32*)( (MRCC_BASE_ADDRESS) + (0x8C) )))


/*************************************/
#define CSSON 				19U

typedef struct 
{
	volatile u32 CR;     		  	//MRCC_BASE_ADDRESS + 0x00 
	volatile u32 PLLCFGR;		 	// MRCC_BASE_ADDRESS + 0x04
	volatile u32 CFGR;				// MRCC_BASE_ADDRESS + 0x08	
	volatile u32 CIR;				//(MRCC_BASE_ADDRESS) + (0x0C)
	volatile u32 AHB1RSTR; 	        //(MRCC_BASE_ADDRESS) + (0x10)
	volatile u32 AHB2RSTR;	        //(MRCC_BASE_ADDRESS) + (0x14)
	volatile u32 RESERVED0[2];		//MRCC_BASE_ADDRESS) + (0x18) MRCC_BASE_ADDRESS) + (0x1C)
	volatile u32 APB1RSTR;	        //(MRCC_BASE_ADDRESS) + (0x20)
	volatile u32 APB2RSTR; 	        //(MRCC_BASE_ADDRESS) + (0x24)
	volatile u32 RESERVED1[2];		//MRCC_BASE_ADDRESS) + (0x28) //MRCC_BASE_ADDRESS) + (0x2C)
	volatile u32 AHB1ENR;		    //(MRCC_BASE_ADDRESS) + (0x30)
	volatile u32 AHB2ENR;		    //(MRCC_BASE_ADDRESS) + (0x34)
	volatile u32 RESERVED2[2];		//MRCC_BASE_ADDRESS) + (0x38) //MRCC_BASE_ADDRESS) + (0x3C)
	volatile u32 APB1ENR; 	        //(MRCC_BASE_ADDRESS) + (0x40)
	volatile u32 APB2ENR; 	        //(MRCC_BASE_ADDRESS) + (0x44)
	volatile u32 RESERVED3[2];		//MRCC_BASE_ADDRESS) + (0x48)//MRCC_BASE_ADDRESS) + (0x4C)
	volatile u32 AHB1LPENR; 	    //(MRCC_BASE_ADDRESS) + (0x50)
	volatile u32 AHB2LPENR;	        //(MRCC_BASE_ADDRESS) + (0x54)
	volatile u32 RESERVED4[2];		//MRCC_BASE_ADDRESS) + (0x58) //MRCC_BASE_ADDRESS) + (0x5C)
	volatile u32 APB1LPENR;	        //(MRCC_BASE_ADDRESS) + (0x60)
	volatile u32 APB2LPENR; 	    //(MRCC_BASE_ADDRESS) + (0x64)
	volatile u32 RESERVED5[2];		//MRCC_BASE_ADDRESS) + (0x68) //MRCC_BASE_ADDRESS) + (0x6C)
	volatile u32 BDCR;		        //(MRCC_BASE_ADDRESS) + (0x70)
	volatile u32 CSR; 		        //(MRCC_BASE_ADDRESS) + (0x74)
	volatile u32 RESERVED6[2];		//MRCC_BASE_ADDRESS) + (0x78) //MRCC_BASE_ADDRESS) + (0x7C)
	volatile u32 SSCGR; 		    //(MRCC_BASE_ADDRESS) + (0x80)
	volatile u32 PLLI2SCFGR;	    //(MRCC_BASE_ADDRESS) + (0x84)
	volatile u32 RESERVED7;			//MRCC_BASE_ADDRESS) + (0x88)
    volatile u32 DCKCFGR;		    //(MRCC_BASE_ADDRESS) + (0x8C)
}RCC_TypeDef;

#define MRCC ((RCC_TypeDef *) MRCC_BASE_ADDRESS)

#endif