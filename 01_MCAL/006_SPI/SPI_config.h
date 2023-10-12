/** - SPI_config.h
	- Created 12/08/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
		*/
/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
/* ************************************************SPI1 CONFIG****************************************/
#define MSPI1_STATUS          MSPI_ENABLE 
/* CK to 1 when idle & The second clock transition is the first data capture edge */ 
#define MSPI1_CLOCK_MODE     SPI_MODE3 
/* */
#define MSPI1_MASTER_SLAVE   SPI_MASTER
/* */
#define MSPI1_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2
/* */
#define MSPI1_DATA_ORDER     SPI_MSB_FIRST
/* */
#define MSPI1_SSM_MANAGE      SSM_SWITCH_OPEN 
/* */
#define MSPI1_SSI_MODE         SSI_VCC

#define MSPI1_DATA_SIZE      SPI_8BIT_DATA
/* */
#define MSPI1_INT_STATUS     SPI_INT_DISABLE
/* */
#define MSPI1_BAUD_RATE     SPI_FPCLK_DIVIDED_BY_2

/**************************************** SPI2 CONFIG*********************************************/
#define MSPI2_STATUS          MSPI_DISABLE 
/* CK to 1 when idle & The second clock transition is the first data capture edge */ 
#define MSPI2_CLOCK_MODE     SPI_MODE3 
/* */
#define MSPI2_MASTER_SLAVE   SPI_MASTER
/* */
#define MSPI2_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2
/* */
#define MSPI2_DATA_ORDER     SPI_MSB_FIRST
/* */
#define MSPI2_SSM_MANAGE      SSM_SWITCH_OPEN 
/* */
#define MSPI2_SSI_MODE         SSI_VCC

#define MSPI2_DATA_SIZE      SPI_8BIT_DATA
/* */
#define MSPI2_INT_STATUS     SPI_INT_DISABLE
/* */
#define MSPI2_BAUD_RATE     SPI_FPCLK_DIVIDED_BY_2
/******************************************* SPI3 CONFIG**********************************************/
#define MSPI3_STATUS          MSPI_DISABLE 
/* CK to 1 when idle & The second clock transition is the first data capture edge */ 
#define MSPI3_CLOCK_MODE     SPI_MODE3 
/* */
#define MSPI3_MASTER_SLAVE   SPI_MASTER
/* */
#define MSPI3_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2
/* */
#define MSPI3_DATA_ORDER     SPI_MSB_FIRST
/* */
#define MSPI3_SSM_MANAGE      SSM_SWITCH_OPEN 
/* */
#define MSPI3_SSI_MODE         SSI_VCC

#define MSPI3_DATA_SIZE      SPI_8BIT_DATA
/* */
#define MSPI3_INT_STATUS     SPI_INT_DISABLE
/* */
#define MSPI3_BAUD_RATE     SPI_FPCLK_DIVIDED_BY_2

/******************************************** SPI4 CONFIG*************************************************/
#define MSPI4_STATUS          MSPI_DISABLE 
/* CK to 1 when idle & The second clock transition is the first data capture edge */ 
#define MSPI4_CLOCK_MODE     SPI_MODE3 
/* */
#define MSPI4_MASTER_SLAVE   SPI_MASTER
/* */
#define MSPI4_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2
/* */
#define MSPI4_DATA_ORDER     SPI_MSB_FIRST
/* */
#define MSPI4_SSM_MANAGE      SSM_SWITCH_OPEN 
/* */
#define MSPI4_SSI_MODE         SSI_VCC

#define MSPI4_DATA_SIZE      SPI_8BIT_DATA
/* */
#define MSPI4_INT_STATUS     SPI_INT_DISABLE
/* */
#define MSPI4_BAUD_RATE     SPI_FPCLK_DIVIDED_BY_2

#endif /* SPI_CONFIG_H */