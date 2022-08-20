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

/*******INTCTRL*******/
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

/*************GPIOHBCTL_RCGCGPIO*****************/
  typedef struct
  {
    u32   PortA    :1;
    u32   PortB    :1;
    u32   PortC    :1;
    u32   PortD    :1;
		u32   PortE    :1;
    u32   PortF    :1;
		u32						 :26;
  }GPIOHBCTL_RCGCGPIO_BF;

  typedef union{
      u32 R;
      GPIOHBCTL_RCGCGPIO_BF  B;
    
  }GPIOHBCTL_RCGCGPIO_Tag;

/*************GPIOHBCTL_RCGCGPIO*****************/
  typedef struct
  {
    u32   PMC0    :4;
    u32   PMC1    :4;
    u32   PMC2    :4;
    u32   PMC3    :4;
		u32   PMC4    :4;
    u32   PMC5    :4;
		u32		PMC6    :4;
		u32   PMC7    :4;
  }GPIOPCTL_BF;

  typedef union{
      u32 R;
      GPIOPCTL_BF  B;
    
  }GPIOPCTL_Tag;


/*************RCGCWD*****************/
  typedef struct
  {
    u32   R0    :1;
    u32   R1    :1;
		u32					:30;
  }RCGCWD_BF;

  typedef union{
      u32 R;
      RCGCWD_BF  B;
    
  }RCGCWD_Tag;

	
/*************WDTCTL*****************/
  typedef struct
  {
    u32   INTEN    	:1;
    u32   RESEN    	:1;
		u32   INTTYPE  	:1;
		u32							:28;
		u32		WRC				:1;
  }WDTCTL_BF;

  typedef union{
      u32 R;
      WDTCTL_BF  B;
    
  }WDTCTL_Tag;

	

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define   CORTEXM4_PERIPH_BASE_ADDRESS        	0xE000E000
#define 	CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS	0x400FE000
#define		CORTEXM4_WDT0_BASE_ADDRESS						0x40000000
#define		CORTEXM4_WDT1_BASE_ADDRESS						0x40001000
	
/*********GPIO ADDRESSES************/	
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

/**************WDT REGISTERS****************/

#define 	WDTLOAD_OFFSET			0x000
#define 	WDTVALUE_OFFSET			0x004
#define 	WDTCTL_OFFSET	  		0x008
#define 	WDTICR_OFFSET				0x00C
#define 	WDTRIS_OFFSET				0x010
#define 	WDTMIS_OFFSET			  0x014
#define 	WDTTEST_OFFSET			0x418
#define 	WDTLOCK_OFFSET	  	0xC00
#define 	WDTPERIPHID4_OFFSET	0xFD0
#define 	WDTPERIPHID5_OFFSET	0xFD4
#define 	WDTPERIPHID6_OFFSET	0xFD8
#define 	WDTPERIPHID7_OFFSET	0xFDC
#define 	WDTPERIPHID0_OFFSET	0xFE0
#define 	WDTPERIPHID1_OFFSET	0xFE4
#define 	WDTPERIPHID2_OFFSET	0xFE8
#define 	WDTPERIPHID3_OFFSET	0xFEC
#define 	WDTPCELLID0_OFFSET	0xFF0
#define 	WDTPCELLID1_OFFSET	0xFF4
#define 	WDTPCELLID2_OFFSET	0xFF8
#define 	WDTPCELLID3_OFFSET	0xFFC


#define   INTCTRL                        (*((volatile INTCTRL_Tag *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD04)))
#define   APINT                          (*((volatile u32 *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD0C)))
#define 	GPIOHBCTL											 (*((volatile GPIOHBCTL_RCGCGPIO_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x06C)))
#define		RCGCGPIO											 (*((volatile GPIOHBCTL_RCGCGPIO_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x608)))
#define		RCGCWD												 (*((volatile RCGCWD_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x600)))


#define GPIOLOCK_KEY		0x4C4F434B
#define WDTLOCK_KEY			0x1ACCE551

/**************************************************

  * GLOBAL DATA PROTOTYPES
  
****************************************************/





#endif /*MCU_HW_H_*/
/**************************************************

  * END FILE Mcu_Hw.h
  
****************************************************/









