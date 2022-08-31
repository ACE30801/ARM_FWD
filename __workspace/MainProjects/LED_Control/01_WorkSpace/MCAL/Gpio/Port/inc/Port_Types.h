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






