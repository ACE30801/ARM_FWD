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

/*************GPIO PINS CONTROL*****************/
  typedef struct
  {
    u32   CONTROL_PIN0    :1;
    u32   CONTROL_PIN1    :1;
    u32   CONTROL_PIN2    :1;
    u32   CONTROL_PIN3    :1;
		u32   CONTROL_PIN4    :1;
    u32   CONTROL_PIN5    :1;
		u32		CONTROL_PIN6    :1;
		u32   CONTROL_PIN7    :1;
		u32										:24;
  }GPIOPINS_BF;

  typedef union{
      u32 R;
      GPIOPINS_BF  B;
    
  }GPIOPINS_Tag;


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


/*************GPTMTAMR*****************/
  typedef struct
  {
    u32   TAMR    	:2;
    u32   TACMR    	:1;
		u32   TAAMS   	:1;
		u32   TACDIR   	:1;
    u32   TAMIE    	:1;
		u32   TAWOT   	:1;
		u32   TASNAPS  	:1;
		u32   TAILD   	:1;
    u32   TAPWMIE  	:1;
		u32   TAMRSU   	:1;
		u32   TAPLO   	:1;
		u32							:20;
  }GPTMTAMR_BF;

  typedef union{
      u32 R;
      GPTMTAMR_BF  B;
    
  }GPTMTAMR_Tag;
  typedef union{
      u32 R;
      GPTMTAMR_BF  B;
    
  }GPTMTBMR_Tag;

/*************GPTMCTL*****************/
  typedef struct
  {
    u32   TAEN    	:1;
    u32   TASTALL  	:1;
		u32   TAEVENT  	:2;
		u32   RTCEN   	:1;
    u32   TAOTE    	:1;
		u32   TAPWML   	:1;
		u32   			   	:1;
		u32   TBEN	  	:1;
		u32   TBSTALL  	:1;
    u32   TBEVENT  	:2;
		u32   			   	:1;
		u32   TBOTE    	:1;
		u32   TBPWML   	:1;
		u32							:17;
  }GPTMCTL_BF;

  typedef union{
      u32 R;
      GPTMCTL_BF  B;
    
  }GPTMCTL_Tag;
  
	
	/*************GPTMTAPR*****************/
  typedef struct
  {
		u32   TAPSR    	:8;
		u32   TAPSRH   	:8;
		u32							:16;
  }GPTMTAPR_BF;

  typedef union{
      u32 R;
      GPTMTAPR_BF  B;
    
  }GPTMTAPR_Tag;
  
			/*************ADCACTSS*****************/
  typedef struct
  {
		u32   ASEN0    	:1;
		u32   ASEN1    	:1;
		u32   ASEN2    	:1;
		u32   ASEN3    	:1;
		u32							:12;
		u32		BUSY			:1;/*READ ONLY*/
		u32							:15;
  }ADCACTSS_BF;

  typedef union{
      u32 R;
      ADCACTSS_BF  B;
    
  }ADCACTSS_Tag;
  
/*************ADCEMUX*****************/
  typedef struct
  {
		u32   EM0    	:4;
		u32   EM1    	:4;
		u32   EM2    	:4;
		u32   EM3    	:4;
		u32						:16;
  }ADCEMUX_BF;

  typedef union{
      u32 R;
      ADCEMUX_BF  B;
    
  }ADCEMUX_Tag;
  
/*************ADCSSMUX*****************/
  typedef struct
  {
		u32   MUX0    	:4;
		u32   MUX1    	:4;
		u32   MUX2    	:4;
		u32   MUX3    	:4;
		u32   MUX4    	:4;
		u32   MUX5    	:4;
		u32   MUX6    	:4;
		u32   MUX7    	:4;
  }ADCSSMUX_BF;

  typedef union{
      u32 R;
      ADCSSMUX_BF  B;
    
  }ADCSSMUX_Tag;

/*************ADCSSCTL*****************/
  typedef struct
  {
		u32   D0    	:1;
		u32   END0    :1;
		u32   IE0	    :1;
		u32   TS0	    :1;
		u32   D1    	:1;
		u32   END1    :1;
		u32   IE1	    :1;
		u32   TS1	    :1;
		u32   D2    	:1;
		u32   END2    :1;
		u32   IE2	    :1;
		u32   TS2	    :1;
		u32   D3    	:1;
		u32   END3    :1;
		u32   IE3	    :1;
		u32   TS3	    :1;
		u32   D4    	:1;
		u32   END4    :1;
		u32   IE4	    :1;
		u32   TS4	    :1;
		u32   D5    	:1;
		u32   END5    :1;
		u32   IE5	    :1;
		u32   TS5	    :1;
		u32   D6    	:1;
		u32   END06   :1;
		u32   IE6	    :1;
		u32   TS6	    :1;
		u32   D7    	:1;
		u32   END7    :1;
		u32   IE7  	  :1;
		u32   TS7  	  :1;
  }ADCSSCTL_BF;

  typedef union{
      u32 R;
      ADCSSCTL_BF  B;
    
  }ADCSSCTL_Tag;
	


/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define   CORTEXM4_PERIPH_BASE_ADDRESS        	0xE000E000
#define 	CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS	0x400FE000
/***************WHATCH DOG TIMERS BASE ADDRESSES**************/
#define		CORTEXM4_WDT0_BASE_ADDRESS						0x40000000
#define		CORTEXM4_WDT1_BASE_ADDRESS						0x40001000
/******************ADC BASE ADDRESSES********************/
#define 	CORTEXM4_ADC0_BASE_ADDRESS  	        0x40038000
#define 	CORTEXM4_ADC1_BASE_ADDRESS  	        0x40039000	

/********************GENERAL PURPOSE TIMERS BASE ADDRESSES********************/
	
#define		CORTEXM4_16_32_BIT_TIMER0_BASE_ADDRESS	0x40030000
#define		CORTEXM4_16_32_BIT_TIMER1_BASE_ADDRESS	0x40031000
#define		CORTEXM4_16_32_BIT_TIMER2_BASE_ADDRESS	0x40032000
#define		CORTEXM4_16_32_BIT_TIMER3_BASE_ADDRESS	0x40033000
#define		CORTEXM4_16_32_BIT_TIMER4_BASE_ADDRESS	0x40034000
#define		CORTEXM4_16_32_BIT_TIMER5_BASE_ADDRESS	0x40035000

#define		CORTEXM4_32_64_BIT_TIMER0_BASE_ADDRESS	0x40036000
#define		CORTEXM4_32_64_BIT_TIMER1_BASE_ADDRESS	0x40037000
#define		CORTEXM4_32_64_BIT_TIMER2_BASE_ADDRESS	0x4004C000
#define		CORTEXM4_32_64_BIT_TIMER3_BASE_ADDRESS	0x4004D000
#define		CORTEXM4_32_64_BIT_TIMER4_BASE_ADDRESS	0x4004E000
#define		CORTEXM4_32_64_BIT_TIMER5_BASE_ADDRESS	0x4004F000

	
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



/********************SYSTEM CONTROL********************/
#define 	RCC_OFFSET					0x060
	
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


/******************GPT REGISTERS******************/
#define GPTMCFG_OFFSET					0x000
#define GPTMTAMR_OFFSET					0x004
#define GPTMTBMR_OFFSET					0x008
#define GPTMCTL_OFFSET					0x00C
#define GPTMSYNC_OFFSET					0x010
#define GPTMIMR_OFFSET					0x018
#define GPTMRIS_OFFSET					0x01C
#define GPTMMIS_OFFSET					0x020
#define GPTMICR_OFFSET					0x024
#define GPTMTAILR_OFFSET				0x028
#define GPTMTBILR_OFFSET				0x02C
#define GPTMTAMATCHR_OFFSET			0x030
#define GPTMTBMATCHR_OFFSET			0x034
#define GPTMTAPR_OFFSET					0x038
#define GPTMTBPR_OFFSET					0x03C
#define GPTMTAPMR_OFFSET				0x040
#define GPTMTBPMR_OFFSET				0x044
#define GPTMTAR_OFFSET					0x048
#define GPTMTBR_OFFSET					0x04C
#define GPTMTAV_OFFSET					0x050
#define GPTMTBV_OFFSET					0x054
#define GPTMRTCPD_OFFSET				0x058
#define GPTMTAPS_OFFSET					0x05C
#define GPTMTBPS_OFFSET					0x060
#define GPTMTAPV_OFFSET					0x064
#define GPTMTBPV_OFFSET					0x068
#define GPTMPP_OFFSET			  		0xFC0

/*****************ADC OFFSET*****************/
#define ADCACTSS_OFFSET  		0x000
#define ADCRIS_OFFSET 			0x004
#define ADCIM_OFFSET  			0x008
#define ADCSC_OFFSET  			0x00C
 #define ADCOSTAT_OFFSET  	0x010
#define ADCEMUX_OFFSET  		0x014
#define ADCUSTAT_OFFSET  		0x018
#define ADCTSSEL_OFFSET  		0x01C
#define ADCSSPRI_OFFSET  		0x020
#define ADCSPC_OFFSET  			0x024
#define ADCPSSI_OFFSET  		0x028
#define ADCSAC_OFFSET  			0x030
#define ADCDCISC_OFFSET  		0x034
#define ADCCTL_OFFSET  			0x038
#define ADCSSMUX0_OFFSET  	0x040
#define ADCSSCTL0_OFFSET  	0x044
#define ADCSSFIFO0_OFFSET  	0x048
#define ADCSSFSTAT0_OFFSET  0x04C
#define ADCSSOP0_OFFSET  		0x050
#define ADCSSDC0_OFFSET  		0x054
#define ADCSSMUX1_OFFSET  	0x060
#define ADCSSCTL1_OFFSET  	0x064
#define ADCSSFIFO1_OFFSET  	0x068
#define ADCSSFSTAT1_OFFSET  0x06C
#define ADCSSOP1_OFFSET  		0x070
#define ADCSSDC1_OFFSET  		0x074
#define ADCSSMUX2_OFFSET  	0x080
#define ADCSSCTL2_OFFSET  	0x084
#define ADCSSFIFO2_OFFSET  	0x088
#define ADCSSFSTAT2_OFFSET  0x08C
#define ADCSSOP2_OFFSET  		0x090
#define ADCSSDC2_OFFSET  		0x094
#define ADCSSMUX3_OFFSET  	0x0A0
#define ADCSSCTL3_OFFSET  	0x0A4
#define ADCSSFIFO3_OFFSET  	0x0A8
#define ADCSSFSTAT3_OFFSET  0x0AC
#define ADCSSOP3_OFFSET  		0x0B0
#define ADCSSDC3_OFFSET  		0x0B4
#define ADCSSDCRIC_OFFSET  	0xD00
#define ADCDCCTL0_OFFSET  	0xE00
#define ADCDCCTL1_OFFSET  	0xE04
#define ADCDCCTL2_OFFSET  	0xE08
#define ADCDCCTL3_OFFSET  	0xE0C
#define ADCDCCTL4_OFFSET  	0xE10
#define ADCDCCTL5_OFFSET  	0xE14
#define ADCDCCTL6_OFFSET  	0xE18
#define ADCDCCTL7_OFFSET  	0xE1C
#define ADCDCCMP0_OFFSET  	0xE40
#define ADCDCCMP1_OFFSET  	0xE44
#define ADCDCCMP2_OFFSET  	0xE48
#define ADCDCCMP3_OFFSET  	0xE4C
#define ADCDCCMP4_OFFSET  	0xE50
#define ADCDCCMP5_OFFSET  	0xE54
#define ADCDCCMP6_OFFSET  	0xE58
#define ADCDCCMP7_OFFSET  	0xE5C
#define ADCPP_OFFSET 			  0xFC0
#define ADCPC_OFFSET 			  0xFC4
#define ADCCC_OFFSET 			  0xFC8
 

#define   INTCTRL                        (*((volatile INTCTRL_Tag *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD04)))
#define   APINT                          (*((volatile u32 *)(CORTEXM4_PERIPH_BASE_ADDRESS+0xD0C)))
#define 	GPIOHBCTL											 (*((volatile GPIOHBCTL_RCGCGPIO_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x06C)))
#define 	GPIODEN(BASE_ADDRESS)					 (*((volatile GPIOPINS_Tag *)(BASE_ADDRESS+GPIODEN_OFFSET)))
#define 	GPIOAFSEL(BASE_ADDRESS)				 (*((volatile GPIOPINS_Tag *)(BASE_ADDRESS+GPIOAFSEL_OFFSET)))
#define 	GPIOAMSEL(BASE_ADDRESS)				 (*((volatile GPIOPINS_Tag *)(BASE_ADDRESS+GPIOAMSEL_OFFSET)))
#define 	GPIOADCCTL(BASE_ADDRESS)				 (*((volatile u32 *)(BASE_ADDRESS+GPIOADCCTL_OFFSET)))
#define		RCGCGPIO											 (*((volatile GPIOHBCTL_RCGCGPIO_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x608)))
#define		RCGCWD												 (*((volatile RCGCWD_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS+0x600)))
#define		GPTMCFG(BASE_ADDRESS)	 				 (*((volatile u32*)(BASE_ADDRESS+0x000)))
#define		GPTMTAMR(BASE_ADDRESS) 				 (*((volatile GPTMTAMR_Tag*)(BASE_ADDRESS+GPTMTAMR_OFFSET)))
#define		GPTMTBMR(BASE_ADDRESS) 				 (*((volatile GPTMTBMR_Tag*)(BASE_ADDRESS+GPTMTBMR_OFFSET)))
#define		GPTMTAILR(BASE_ADDRESS)	 			 (*((volatile u32*)(BASE_ADDRESS+GPTMTAILR_OFFSET)))
#define		GPTMCTL(BASE_ADDRESS)	 				 (*((volatile GPTMCTL_Tag*)(BASE_ADDRESS+GPTMTAILR_OFFSET)))		
#define		GPTMTAPR(BASE_ADDRESS)	 			 (*((volatile GPTMTAPR_Tag*)(BASE_ADDRESS+GPTMTAPR_OFFSET)))		
#define 	RCGCADC   										 (*((volatile RCGCWD_Tag *)(CORTEXM4_SYSTEM_CONTROL_BASE_ADDRESS)))/*bit zero for ADC0 and bit 1 for ADC1(wait 3 system clocks befor accessing any register)*/
#define 	ADCACTSS(BASE_ADDRESS)	 			 (*((volatile ADCACTSS_Tag *)(BASE_ADDRESS+ADCACTSS_OFFSET)))
#define 	ADCEMUX(BASE_ADDRESS)	 			 	 (*((volatile ADCEMUX_Tag *)(BASE_ADDRESS+ADCEMUX_OFFSET)))
#define 	ADCSSMUX0(BASE_ADDRESS)	 			 (*((volatile ADCSSMUX_Tag *)(BASE_ADDRESS+ADCSSMUX0_OFFSET)))
#define 	ADCSSMUX1(BASE_ADDRESS)	 			 (*((volatile ADCSSMUX_Tag *)(BASE_ADDRESS+ADCSSMUX1_OFFSET)))
#define 	ADCSSMUX2(BASE_ADDRESS)	 			 (*((volatile ADCSSMUX_Tag *)(BASE_ADDRESS+ADCSSMUX2_OFFSET)))
#define 	ADCSSMUX3(BASE_ADDRESS)	 			 (*((volatile ADCSSMUX_Tag *)(BASE_ADDRESS+ADCSSMUX3_OFFSET)))
#define 	ADCSSCTL0(BASE_ADDRESS)	 			 (*((volatile ADCSSCTL_Tag *)(BASE_ADDRESS+ADCSSCTL0_OFFSET)))
#define 	ADCSSCTL1(BASE_ADDRESS)	 			 (*((volatile ADCSSCTL_Tag *)(BASE_ADDRESS+ADCSSCTL1_OFFSET)))
#define 	ADCSSCTL2(BASE_ADDRESS)	 			 (*((volatile ADCSSCTL_Tag *)(BASE_ADDRESS+ADCSSCTL2_OFFSET)))
#define 	ADCSSCTL3(BASE_ADDRESS)	 			 (*((volatile ADCSSCTL_Tag *)(BASE_ADDRESS+ADCSSCTL3_OFFSET)))

#define GPIOLOCK_KEY		0x4C4F434B
#define WDTLOCK_KEY			0x1ACCE551

/**************************************************

  * GLOBAL DATA PROTOTYPES
  
****************************************************/





#endif /*MCU_HW_H_*/
/**************************************************

  * END FILE Mcu_Hw.h
  
****************************************************/









