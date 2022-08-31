/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   Dio.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef DIO_H_
#define DIO_H_


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



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/******************CHANNEL TYPE******************/
typedef enum {
 Dio_Channel_0,
 Dio_Channel_1,
 Dio_Channel_2,
 Dio_Channel_3,
 Dio_Channel_4,
 Dio_Channel_5,
 Dio_Channel_6,
 Dio_Channel_7
}Dio_ChannelType;



/********************PORT TYPE********************/
typedef enum{
 Dio_Port_A,
 Dio_Port_B,
 Dio_Port_C,
 Dio_Port_D,
 Dio_Port_E,
 Dio_Port_F
}Dio_PortType;


/*****************LEVEL TYPE***************/

typedef enum
{
    Dio_Low = 0,
    Dio_High = 1
    
}Dio_LevelType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);




#endif /*DIO_H_*/

/**************************************************

  * END FILE Dio.h
  
****************************************************/






