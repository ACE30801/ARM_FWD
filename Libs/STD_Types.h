/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
                  standard macros
 *
 *********************************************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Platform_Types.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES
 *********************************************************************************************************************/

  
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;

typedef volatile u8 v_u8;
typedef volatile s8 v_s8;

typedef volatile u16 v_u16;
typedef volatile s16 v_s16;

typedef volatile u32 v_u32;
typedef volatile s32 v_s32;

typedef volatile u64 v_u64;
typedef volatile s64 v_s64;

typedef u8  Std_ReturnType;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define HIGH  1
#define LOW   0

#define ON    1
#define OFF    0

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* STD_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
 
 
