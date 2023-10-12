/** - STD_TYPES.h
	- Created 27/7/2023
	- Author Mohamed Ali
	- Version 1-1
	- Notes:*
			*
			*
**/
#ifndef STD_TYPES_H
#define STD_TYPES_H


#ifndef FALSE 
#define FALSE (0U)
#endif

#ifndef TRUE 
#define TRUE (1U)
#endif

typedef unsigned char 			u8  ;			/* 0 : 255 */
typedef unsigned short int  	u16	;			/* 0 : 65535*/
typedef unsigned long int 		u32	;			/* 0 : 4294967295*/

typedef signed char 			s8	;			/*-128 : 127*/
typedef signed short int 		s16	;			/*-32768 : 32767*/
typedef signed long int 		s32	;			/*-2147483648 : 2147483647*/

typedef unsigned long long int 	u64 ;           /*0 : 18,446,744,073,709,551,615*/
typedef signed long long int 	s64	;			/*-9,223,372,036,854,775,808 : 9,223,372,036,854,775,807*/

typedef float 					f32	;			/*3.4E-38 : 3.4E+38*/
typedef double					f64	;			/*1.7E-308 : 1.7E+308	*/




#endif /*STD_TYPES_H*/
