/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Mcu_ClockType.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef MCU_CLOCKTYPE_H_
#define MCU_CLOCKTYPE_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"


/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/
/******RESET SOURCE******/
/*
* the reset source is put in Reset Cause (RESC) register 
* the address of RESC is *((volatile u32 *)(0x400FE000+0x05C)
* 
* software reset use Special registers located at (0x400FE000+0x500+) set then clear make corresponding peripheral cleared 
*/

#define MCU_EXTERNAL_RESET          0 /* bit field 0*/
#define MCU_POWER_ON_RESET          1  /*bit field 1*/
#define MCU_BROWN_OUT_RESET         2  /*bit field 2*/
#define MCU_SOFTWARE_RESET          3 /*bit field 4*/ 
#define MCU_WATCHDOG_RESET          4  /*bit field 5 for WDT1 and 3 for WDT0*/
#define MCU_MOSC_FAILURE_RESET      5 /*bit field 16*/

/************CLOCK SOURCES**************/

#define MCU_PIOSC_CLOCK       0   /*precision internal oscillator*/
#define MCU_MOSC_CLOCK        1   /*Main oscillator*/
#define MCU_LFIOSC_CLOCK      2   /*Low-frequency internal oscillator*/
#define MCU_HIBERNATION_CLOCK 3


/*************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


 



#endif /*MCU_CLOCKTYPE_H_*/

/**************************************************

  * END FILE Mcu_ClockType.h
  
****************************************************/






