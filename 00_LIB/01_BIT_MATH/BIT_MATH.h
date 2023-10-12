/** - BIT_MATH.h
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG , BIT) 		REG |= (1U<<BIT)
#define CLEAR_BIT(REG , BIT) 	REG &= ~(1U<<BIT)
#define TOGGLE_BIT(REG , BIT) 	REG ^= (1U<<BIT)
#define GET_BIT(REG , BIT) 		((REG >> BIT) & 1U)


#endif