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


  typedef struct
  {
    u32   VECACT    :8;
    u32             :3;
    u32   RETBASE   :1;
    u32   VECPEND   :8;
    u32             :2;
    u32   ISRPEND   :1;
    u32   ISRPRE    :1;
    u32             :1;
    u32   PENDSTCLR :1;
    u32   PENDSTSET :1;
    u32   UNPENDSV  :1;
    u32   PENDSV    :1;
    u32             :2;
    u32   NMISET    :1;
    
  }INTCTRL_BF;

  typedef union{
      u32 R;
      INTCTRL_BF  B;
    
  }INTCTRL_Tag;



/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define   CORTEXM4_PERIPH_BASE_ADDRESS   0xE000E000

#define   INTCTRL                        *((volatile INTCTRL_Tag *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD04))
#define   APINT                          *((volatile u32 *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD0C))


               



/**************************************************

  * GLOBAL DATA PROTOTYPES
  
****************************************************/





#endif /*MCU_HW_H_*/
/**************************************************

  * END FILE Mcu_Hw.h
  
****************************************************/









