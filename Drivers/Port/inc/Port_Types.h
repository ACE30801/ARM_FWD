/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Port_Types.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7


#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
#define PORTE   4
#define PORTF   5

/****************PIN MODE**************/
#define PORT_PINMODE_DIO				 					(-1)

/***************PORT A******************/

#define PORT_PINMODE_PA0_U0RX		 					1 /*default*/
#define PORT_PINMODE_PA0_CAN1Rx	 					8
																					
#define PORT_PINMODE_PA1_U0TX		 					1 /*default*/
#define PORT_PINMODE_PA1_CAN1Tx	 					8
																					
#define PORT_PINMODE_PA2_SSI0Clk 					2 /*default*/
																					
#define PORT_PINMODE_PA3_SSI0Fss 					2 /*default*/
																					
#define PORT_PINMODE_PA4_SSI0Rx	 					2 /*default*/
																					 
#define PORT_PINMODE_PA5_SSI0Tx	 					2 /*default*/
																					
#define PORT_PINMODE_PA6_I2C1SCL 					3
#define PORT_PINMODE_PA6_M1PWM2	 					5
																					
#define PORT_PINMODE_PA7_I2C1SDA 					3
#define PORT_PINMODE_PA7_M1PWM3	 					5

/***************PORT B******************/

#define PORT_PINMODE_PB0_ANALOG_USB0ID		0
#define PORT_PINMODE_PB0_U1Rx		 					1
#define PORT_PINMODE_PB0_T2CCP0	 					7

#define PORT_PINMODE_PB1_ANALOG_USB0VBUS	0
#define PORT_PINMODE_PB1_U1Tx		 					1
#define PORT_PINMODE_PB1_T2CCP1	 					7

#define PORT_PINMODE_PB2_I2C0SCL 					3 /*default*/
#define PORT_PINMODE_PB2_T3CCP0	 					7

#define PORT_PINMODE_PB3_I2C0SDA 					3 /*default*/
#define PORT_PINMODE_PB3_T3CCP1	 					7

#define PORT_PINMODE_PB4_ANALOG_AIN10			0
#define PORT_PINMODE_PB4_SSI2Clk 					2
#define PORT_PINMODE_PB4_M0PWM2	 					4
#define PORT_PINMODE_PB4_T1CCP0	 					7
#define PORT_PINMODE_PB4_CAN0Rx	 					8

#define PORT_PINMODE_PB5_ANALOG_AIN11			0
#define PORT_PINMODE_PB5_SSI2Fss 					2
#define PORT_PINMODE_PB5_M0PWM3	 					4
#define PORT_PINMODE_PB5_T1CCP1	 					7
#define PORT_PINMODE_PB5_CAN0Tx	 					8

#define PORT_PINMODE_PB6_SSI2Rx	 					2
#define PORT_PINMODE_PB6_M0PWM0	 					4
#define PORT_PINMODE_PB6_T0CCP0	 					7

#define PORT_PINMODE_PB7_SSI2Tx	 					2
#define PORT_PINMODE_PB7_M0PWM1	 					4
#define PORT_PINMODE_PB7_T0CCP1	 					7

/***************PORT C******************/

#define PORT_PINMODE_PC0_TCK_SWCLK				1 /*default*/
#define PORT_PINMODE_PC0_T4CCP0						7

#define PORT_PINMODE_PC1_TMS_SWDIO				1 /*default*/
#define PORT_PINMODE_PC1_T4CCP1						7

#define PORT_PINMODE_PC2_TDI							1 /*default*/
#define PORT_PINMODE_PC2_T5CCP0						7

#define PORT_PINMODE_PC3_TDO_SWO					1	/*default*/
#define PORT_PINMODE_PC3_T5CCP1						7	

#define PORT_PINMODE_PC4_ANALOG_C1_MINUS	0
#define PORT_PINMODE_PC4_U4Rx							1
#define PORT_PINMODE_PC4_U1Rx							2
#define PORT_PINMODE_PC4_M0PWM6						4
#define PORT_PINMODE_PC4_IDX1							6
#define PORT_PINMODE_PC4_WT0CCP0					7
#define PORT_PINMODE_PC4_U1RTS						8

#define PORT_PINMODE_PC5_ANALOG_C1_PLUS 	0
#define PORT_PINMODE_PC5_U4Tx							1
#define PORT_PINMODE_PC5_M0PWM7						4
#define PORT_PINMODE_PC5_PhA1							6
#define PORT_PINMODE_PC5_WT0CCP1					7
#define PORT_PINMODE_PC5_U1CTS						8

#define PORT_PINMODE_PC6_ANALOG_C0_PLUS 	0
#define PORT_PINMODE_PC6_U3Rx							1
#define PORT_PINMODE_PC6_PhB1							6
#define PORT_PINMODE_PC6_WT1CCP0					7
#define PORT_PINMODE_PC6_USB0EPEN					8

#define PORT_PINMODE_PC7_ANALOG_C0_MINUS	0
#define PORT_PINMODE_PC7_U3Tx							1
#define PORT_PINMODE_PC7_WT1CCP1					7
#define PORT_PINMODE_PC7_USB0PFLT					8

/***************PORT D******************/
#define PORT_PINMODE_PD0_ANALOG_AIN7		0
#define PORT_PINMODE_PD0_SSI3Clk				1
#define PORT_PINMODE_PD0_SSI1Clk				2
#define PORT_PINMODE_PD0_I2C3SCL				3
#define PORT_PINMODE_PD0_M0PWM6					4
#define PORT_PINMODE_PD0_M1PWM0					5
#define PORT_PINMODE_PD0_WT2CCP0				7

#define PORT_PINMODE_PD1_ANALOG_AIN6		0
#define PORT_PINMODE_PD1_SSI3Fss				1
#define PORT_PINMODE_PD1_SSI1Fss				2
#define PORT_PINMODE_PD1_I2C3SDA				3
#define PORT_PINMODE_PD1_M0PWM7					4
#define PORT_PINMODE_PD1_M1PWM1					5
#define PORT_PINMODE_PD1_WT2CCP1				7

#define PORT_PINMODE_PD2_ANALOG_AIN5		0
#define PORT_PINMODE_PD2_SSI3Rx					1
#define PORT_PINMODE_PD2_SSI1Rx					2
#define PORT_PINMODE_PD2_M0FAULT0				4
#define PORT_PINMODE_PD2_WT3CCP0				7
#define PORT_PINMODE_PD2_USB0EPEN				8

#define PORT_PINMODE_PD3_ANALOG_AIN4		0
#define PORT_PINMODE_PD3_SSI3Tx					1
#define PORT_PINMODE_PD3_SSI1Tx					2
#define PORT_PINMODE_PD3_IDX0						6
#define PORT_PINMODE_PD3_WT3CCP1				7
#define PORT_PINMODE_PD3_USB0PFLT				8

#define PORT_PINMODE_PD4_ANALOG_USB0DM	0
#define PORT_PINMODE_PD4_U6Rx						1
#define PORT_PINMODE_PD4_WT4CCP0				7

#define PORT_PINMODE_PD5_ANALOG_USB0DP	0
#define PORT_PINMODE_PD5_U6Tx						1
#define PORT_PINMODE_PD5_WT4CCP1				7

#define PORT_PINMODE_PD6_U2Rx						1
#define PORT_PINMODE_PD6_M0FAULT0				4
#define PORT_PINMODE_PD6_PhA0 					6
#define PORT_PINMODE_PD6_WT5CCP0				7

#define PORT_PINMODE_PD7_U2Tx						1
#define PORT_PINMODE_PD7_PhB0						6
#define PORT_PINMODE_PD7_WT5CCP1				7
#define PORT_PINMODE_PD7_NMI 						8

/***************PORT E******************/

#define PORT_PINMODE_PE0_ANALOG_AIN3		0
#define PORT_PINMODE_PE0_U7Rx						1

#define PORT_PINMODE_PE1_ANALOG_AIN2		0
#define PORT_PINMODE_PE1_U7Tx						1

#define PORT_PINMODE_PE2_ANALOG_AIN1		0

#define PORT_PINMODE_PE3_ANALOG_AIN0		0

#define PORT_PINMODE_PE4_ANALOG_AIN9		0
#define PORT_PINMODE_PE4_U5Rx						1
#define PORT_PINMODE_PE4_I2C2SCL				3
#define PORT_PINMODE_PE4_M0PWM4					4
#define PORT_PINMODE_PE4_M1PWM2					5
#define PORT_PINMODE_PE4_CAN0Rx					8

#define PORT_PINMODE_PE5_ANALOG_AIN8		0
#define PORT_PINMODE_PE5_U5Tx						1
#define PORT_PINMODE_PE5_I2C2SDA				3
#define PORT_PINMODE_PE5_M0PWM5					4
#define PORT_PINMODE_PE5_M1PWM3					5
#define PORT_PINMODE_PE5_CAN0Tx					8

/***************PORT F******************/

#define PORT_PINMODE_PF0_U1RTS		1
#define PORT_PINMODE_PF0_SSI1Rx		2
#define PORT_PINMODE_PF0_CAN0Rx		3
#define PORT_PINMODE_PF0_M1PWM4		5
#define PORT_PINMODE_PF0_PhA0			6
#define PORT_PINMODE_PF0_T0CCP0		7
#define PORT_PINMODE_PF0_NMI			8
#define PORT_PINMODE_PF0_C0O			9

#define PORT_PINMODE_PF1_U1CTS		1
#define PORT_PINMODE_PF1_SSI1Tx		2
#define PORT_PINMODE_PF1_M1PWM5		5
#define PORT_PINMODE_PF1_PhB0			6
#define PORT_PINMODE_PF1_T0CCP1		7
#define PORT_PINMODE_PF1_C1O			9
#define PORT_PINMODE_PF1_TRD1			14

#define PORT_PINMODE_PF2_SSI1Clk	2
#define PORT_PINMODE_PF2_M0FAULT0	4
#define PORT_PINMODE_PF2_M1PWM6		5
#define PORT_PINMODE_PF2_T1CCP0		7
#define PORT_PINMODE_PF2_TRD0			14

#define PORT_PINMODE_PF3_SSI1Fss	2
#define PORT_PINMODE_PF3_CAN0Tx		3
#define PORT_PINMODE_PF3_M1PWM7		5
#define PORT_PINMODE_PF3_T1CCP1		7
#define PORT_PINMODE_PF3_TRCLK		14
				
#define PORT_PINMODE_PF4_M1FAULT0	5
#define PORT_PINMODE_PF4_IDX0			6
#define PORT_PINMODE_PF4_T2CCP0		7
#define PORT_PINMODE_PF4_USB0EPEN	8


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/******************CHANNEL TYPE******************/

typedef enum {
 Channel_0=0,
 Channel_1,
 Channel_2,
 Channel_3,
 Channel_4,
 Channel_5,
 Channel_6,
 Channel_7
}Port_ChannelNum;



/********************PORT TYPE********************/
typedef enum{
 Port_A=0,
 Port_B,
 Port_C,
 Port_D,
 Port_E,
 Port_F
}Port_PortType;

/*******************PORT TYPE************************/



/*****************LEVEL TYPE***************/

typedef enum
{
		NoLevel,
		Port_Low,
    Port_High
    
}Port_LevelType;

/***************PIN MODE*****************/

typedef enum
{
    Input,
    Output
    
}Port_PinDirectionType;

/***************ATTACH TYPE****************/
typedef enum
{
    NoPinAttachType,
		PullUp,
    PullDown ,
		OpenDrain	
    
}Port_PinAttachType;

/***************OUTPUT CURRENT****************/
typedef enum
{
    NoOutputCurrent,
		R2R ,
    R4R ,
		R8R 
    
}Port_OutputCurrent;




/************PIN CONFIGURATION**************/
typedef struct
{
	Port_PortType PortId;
	Port_ChannelNum ChannelId;	
	s8	PortPinMode;
	Port_LevelType PortPinLevelValue;
	Port_PinDirectionType PortPinDirection;
	Port_PinAttachType	PortPinInternalAttach;
	Port_OutputCurrent PortPinOutputCurrent;
}Port_ConfigType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /*PORT_TYPES_H_*/

/**************************************************

  * END FILE Port_Types.h
  
****************************************************/






