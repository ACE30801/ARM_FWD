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


#ifndef MCU_TYPE_H_
#define MCU_TYPE_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"
#include "Mcu_TypeCfg.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/
/******RESET SOURCE******/
/*
* the reset source is put in Reset Cause (RESC) register 
* the address of RESC is *((volatile u32 *)(0x400FE000+0x05C))
* 
* software reset use Special registers located at (0x400FE000+0x500+) set then clear make corresponding peripheral cleared 
*/

#define MCU_EXTERNAL_RESET          0 /* bit field 0*/
#define MCU_POWER_ON_RESET          1  /*bit field 1*/
#define MCU_BROWN_OUT_RESET         2  /*bit field 2*/
#define MCU_SOFTWARE_RESET          3 /*bit field 4*/ 
#define MCU_WATCHDOG_RESET          4  /*bit field 5 for WDT1 and 3 for WDT0*/
#define MCU_MOSC_FAILURE_RESET      5 /*bit field 16*/
/*typedef struct {
  u32  EXT      :1;
  u32  POR      :1;
  u32  BOR      :1;
  u32  WDT0     :1;
  u32  SW       :1;
  u32  WDT1     :1;  
  u32           :10;
  u32  MOSCFAIL :1
  u32           :15;
}RESC_BF;

typedef union
{
  u32       R;
  RESC_BF   B;
}RESC_Tag;

#define   RESC    (*((volatile RESC_Tag *)(0x400FE000+0x05C)))  
*/
/************CLOCK SOURCES**************/

#define MCU_PIOSC_CLOCK       0   /*precision internal oscillator*/
#define MCU_MOSC_CLOCK        1   /*Main oscillator*/
#define MCU_LFIOSC_CLOCK      2   /*Low-frequency internal oscillator*/
#define MCU_HIBERNATION_CLOCK 3




/*****************PLL MODES********************/

#define MCU_PLL_MODE_NORMAL     0
#define MCU_PLL_MODE_POWER_DOWN 1





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/****************PLL STATUS***************/

typedef enum
{
  MCU_PLL_STATUS_LOCKED,
  MCU_PLL_STATUS_UNLOCKED    
}Mcu_PllStatusType;



/**************MCU CONFIGURATION TYPE************/
typedef u8  Mcu_ClockType;
typedef u8  Mcu_RawResetType;

typedef struct{
  Mcu_ClockType Mcu_ClockSourceType;
  _bool         Mcu_PllActive;
  u32           Freq; /*KHz*/
}Mcu_ConfigType;
 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



void Mcu_Init(const Mcu_ConfigType * ConfigPtr);


Mcu_RawResetType Mcu_GetResetRawValue(void);

void Mcu_PerformReset(void);

Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);

Std_ReturnType Mcu_DistributePllClock(void); 

Mcu_PllStatusType Mcu_GetPllStatus(void);


#endif /*MCU_TYPE_H_*/

/**************************************************

  * END FILE Mcu_Type.h
  
****************************************************/






