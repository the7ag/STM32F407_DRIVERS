/** - DELAY_interface.h
	- Created 31/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
/*========================================================================================*/

/*========================================================================================
========================   guard of file will call on time in .c  ========================
========================================================================================*/ 
#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H
	 
#include "STD_TYPES.h"


/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/


  /* =============  Function To Delay By Milliseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_voidMsIn16MHz(u16 copy_u16CountNum);

 /* =============  Function To Delay By Microseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_voidUsIn16MHzint (u16 copy_u16CountNum);






#endif //DELAY_INTERFACE_H
