/**************************************************

  * FILE DESCRIPTION
  
****************************************************/
/**
*    \file    Dio_Pri.h
*
*   
*
*   \details  
*
*
*****************************************************/


#ifndef DIO_PRI_H_
#define DIO_PRI_H_



/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"



/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

/******************PORT BASE ADDRESSES*****************/
#ifndef CORTEXM4_GPIO_A_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_A_APB_BASE_ADDRESS    0x40004000
#endif
#ifndef CORTEXM4_GPIO_A_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_A_AHB_BASE_ADDRESS    0x40058000
#endif
#ifndef CORTEXM4_GPIO_B_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_B_APB_BASE_ADDRESS    0x40005000
#endif
#ifndef CORTEXM4_GPIO_B_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_B_AHB_BASE_ADDRESS    0x40059000
#endif
#ifndef CORTEXM4_GPIO_C_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_C_APB_BASE_ADDRESS    0x40006000
#endif
#ifndef CORTEXM4_GPIO_C_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_C_AHB_BASE_ADDRESS    0x4005A000
#endif
#ifndef CORTEXM4_GPIO_D_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_D_APB_BASE_ADDRESS    0x40007000
#endif
#ifndef CORTEXM4_GPIO_D_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_D_AHB_BASE_ADDRESS    0x4005B000
#endif
#ifndef CORTEXM4_GPIO_E_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_E_APB_BASE_ADDRESS    0x40024000
#endif
#ifndef CORTEXM4_GPIO_E_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_E_AHB_BASE_ADDRESS    0x4005C000
#endif
#ifndef CORTEXM4_GPIO_F_APB_BASE_ADDRESS
#define   CORTEXM4_GPIO_F_APB_BASE_ADDRESS    0x40025000
#endif
#ifndef CORTEXM4_GPIO_F_AHB_BASE_ADDRESS
#define   CORTEXM4_GPIO_F_AHB_BASE_ADDRESS    0x4005D000
#endif

/*****************************OFFSET******************************/

/*************PORT CONTROL**************/
#define   GPIOPCTL_OFFSET     0x52C


/***************COMMIT CONTROL*******************/
#define   GPIOLOCK_OFFSET     0x520
#define   GPIOCR_OFFSET       0x524

/*****************MODE CONTROL*********************/
#define   GPIOAFSEL_OFFSET    0x420
#define   GPIOADCCTL_OFFSET   0x530
#define   GPIODMACTL_OFFSET   0x534

/*****************DATA CONTROL*********************/

#define   GPIODATA_OFFSET     0x000
#define   GPIODIR_OFFSET      0x400


/*****************INTERRUPT CONTROL*********************/

#define   GPIOIS_OFFSET       0x404
#define   GPIOIBE_OFFSET      0x408
#define   GPIOIEV_OFFSET      0x40C
#define   GPIOIM_OFFSET       0x410
#define   GPIORIS_OFFSET      0x414
#define   GPIOMIS_OFFSET      0x418
#define   GPIOICR_OFFSET      0x41C

/******************PAD CONTROL*********************/

#define   GPIODR2R_OFFSET     0x500
#define   GPIODR4R_OFFSET     0x504
#define   GPIODR8R_OFFSET     0x508
#define   GPIOODR_OFFSET      0x50C
#define   GPIOPUR_OFFSET      0x510
#define   GPIOPDR_OFFSET      0x514
#define   GPIOSLR_OFFSET      0x518
#define   GPIODEN_OFFSET      0x51C
#define   GPIOAMSEL_OFFSET    0x528

/***************IDENTIFICATION REGISTERS***************/
#define   GPIOPID4_OFFSET       0xFD0
#define   GPIOPID5_OFFSET       0xFD4
#define   GPIOPID6_OFFSET       0xFD8
#define   GPIOPID7_OFFSET       0xFDC
#define   GPIOPID0_OFFSET       0xFE0
#define   GPIOPID1_OFFSET       0xFE4
#define   GPIOPID2_OFFSET       0xFE8
#define   GPIOPID3_OFFSET       0xFEC
#define   GPIOPCID0_OFFSET      0xFF0
#define   GPIOPCID1_OFFSET      0xFF4
#define   GPIOPCID2_OFFSET      0xFF8
#define   GPIOPCID3_OFFSET      0xFFC




/**************************************************

  * GLOBAL DATA PROTOTYPES
  
****************************************************/





#endif /*DIO_PRI_H_*/
/**************************************************

  * END FILE Dio_Pri.h
  
****************************************************/








