/**************************************************

  * FILE DESCRIPTION
  
****************************************************/
/**
*    \file    Mcu_Hw.h
*
*   
*
*   \details  
*
*
*****************************************************/

#ifndef MCU_HW_H_
#define MCU_HW_H_




/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"


/*TODO make struct that cuts the register into bits with the things that the register control */

/*
  typedef struct
  {
    u32   part1 :no.bits;
    u32   part2 :3;
    ..etc
    
  }INTCTRL_BF;

  typedef union{
      u32 R;
      INTCTRL_BF  B;
    
  }INTCTRL_Tag;
*/


/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define   CORTEXM4_PERIPH_BASE_ADDRESS   0xE000E000

#define   INTCTRL                        *((volatile u32 *))(CORTEXM4_PERIPH_BASE_ADDRESS+0xD04))
#define   APINT                          *((volatile u32 *))(CORTEXM4_PERIPH_BASE_ADDRESS+0xD0C))


               

/**************************************************

  * GLOBAL DATA PROTOTYPES
  
****************************************************/





#endif /*MCU_HW_H_*/
/**************************************************

  * END FILE Mcu_Hw.h
  
****************************************************/










#endif