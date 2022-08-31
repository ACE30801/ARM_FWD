/**************************************************

  * FILE DESCRIPTION
  
****************************************************/
/**
*    \file    IntCtrl_Types.h
*
*   \brief    
*
*   \details
*
*
*
*****************************************************/

#ifndef INTCTRL_TYPES_H_
#define INTCTRL_TYPES_H_




/**************************************************

  * INCLUDES
  
****************************************************/

#include "STD_Types.h"



/**************************************************

  * CONSTANT MACROS
  
****************************************************/

#define RESET_TYPE -3
#define NMI_CONST -2
#define HARDFAULT -1
#define MEMORY_MANAGEMENT_FAULT 0
#define BUS_FAULT 1
#define USAGE_FAULT 2
#define PENDSV_INTERRUPT 3
#define SYSTICK 4
#define INTERRUPTS 6
#define DEBUG_MONITOR 7


#define GPIOPortA   IRQ0  
#define GPIOPortB   IRQ1
#define GPIOPortC   IRQ2  
#define GPIOPortD   IRQ3
#define GPIOPortE   IRQ4  
#define UART0       IRQ5    
#define UART1       IRQ6  
#define SSI0        IRQ7    
#define I2C0        IRQ8  
#define PWM0Fault   IRQ9    

#define PWM0Generator0    IRQ10  
#define PWM0Generator1    IRQ11
#define PWM0Generator2    IRQ12  
#define QEI0              IRQ13
#define ADC0Sequence0     IRQ14  
#define ADC0Sequence1     IRQ15    
#define ADC0Sequence2     IRQ16  
#define ADC0Sequence3     IRQ17    
#define WatchdogTimers0_1 IRQ18  
#define _16_32_BitTimer0A  IRQ19    

#define _16_32_BitTimer0B   IRQ20  
#define _16_32_BitTimer1A   IRQ21
#define _16_32_BitTimer1B   IRQ22  
#define _16_32_BitTimer2A   IRQ23
#define _16_32_BitTimer2B   IRQ24  
#define AnalogComparator0  IRQ25    
#define AnalogComparator1  IRQ26  
#define RESERVED6          IRQ27    
#define SystemControl      IRQ28  
#define FlashMemoryControlAndEEPROMControl      IRQ29    

#define GPIOPortF              IRQ30  
#define RESERVED7              IRQ31
#define RESERVED8              IRQ32  
#define UART2                  IRQ33
#define SSI1                   IRQ34  
#define _16_32_BitTimer3A       IRQ35    
#define _16_32_BitTimer3B       IRQ36  
#define I2C1                   IRQ37    
#define QEI1                   IRQ38  
#define CAN0                   IRQ39    

#define CAN1                  IRQ40  
#define RESERVED9             IRQ41
#define RESERVED10            IRQ42  
#define HibernationModule     IRQ43
#define USB                   IRQ44  
#define PWMGenerator3         IRQ45    
#define uDMASoftware          IRQ46  
#define uDMAError             IRQ47    
#define ADC1Sequence0         IRQ48  
#define ADC1Sequence1         IRQ49    
        
#define ADC1Sequence2   IRQ50  
#define ADC1Sequence3   IRQ51
#define RESERVED11      IRQ52  
#define RESERVED12      IRQ53
#define RESERVED13      IRQ54  
#define RESERVED14      IRQ55    
#define RESERVED15      IRQ56  
#define SSI2            IRQ57    
#define SSI3            IRQ58  
#define UART3           IRQ59    

#define UART4       IRQ60  
#define UART5       IRQ61
#define UART6       IRQ62  
#define UART7       IRQ63
#define RESERVED16  IRQ64  
#define RESERVED17  IRQ65    
#define RESERVED18  IRQ66  
#define RESERVED19  IRQ67    
#define I2C2        IRQ68  
#define I2C3        IRQ69    

#define _16_32_BitTimer4A   IRQ70  
#define _16_32_BitTimer4B   IRQ71
/*72-91 reserved*/
#define _16_32_BitTimer5A   IRQ92  
#define _16_32_BitTimer5B   IRQ93
#define _32_64_BitTimer0A   IRQ94  
#define _32_64_BitTimer0B   IRQ95    
#define _32_64_BitTimer1A   IRQ96  
#define _32_64_BitTimer1B   IRQ97    
#define _32_64_BitTimer2A   IRQ98  
#define _32_64_BitTimer2B   IRQ99    

#define _32_64_BitTimer3A   IRQ100  
#define _32_64_BitTimer3B   IRQ101
#define _32_64_BitTimer4A   IRQ102  
#define _32_64_BitTimer4B   IRQ103
#define _32_64_BitTimer5A   IRQ104  
#define _32_64_BitTimer5B   IRQ105    
#define SystemException    IRQ106  
/*107-133 reserved*/
#define PWM1Generator0   IRQ134  
#define PWM1Generator1   IRQ135    
#define PWM1Generator2   IRQ136  
#define PWM1Generator3   IRQ137    
#define PWM1Fault        IRQ138    
  



/**************************************************

  * GLOBAL DATA TYPES AND STRACTURES
  
****************************************************/

typedef enum { RESET = 1, NMI , HardFault, MemoryManagementFault,\
BusFault, UsageFault,\
 Reserved1, Reserved2, Reserved3, Reserved4,\
 SVCall, DebugMonitor, Reserved5, PendSV,\
 Systick,\
 IRQ0 , IRQ1, IRQ2, IRQ3, IRQ4, IRQ5, IRQ6, IRQ7, IRQ8, IRQ9,\
IRQ10, IRQ11, IRQ12, IRQ13, IRQ14, IRQ15, IRQ16, IRQ17, IRQ18, IRQ19,\
IRQ20, IRQ21, IRQ22, IRQ23, IRQ24, IRQ25, IRQ26, IRQ27, IRQ28, IRQ29,\
IRQ30, IRQ31, IRQ32, IRQ33, IRQ34, IRQ35, IRQ36, IRQ37, IRQ38, IRQ39,\
IRQ40, IRQ41, IRQ42, IRQ43, IRQ44, IRQ45, IRQ46, IRQ47, IRQ48, IRQ49,\
IRQ50, IRQ51, IRQ52, IRQ53, IRQ54, IRQ55, IRQ56, IRQ57, IRQ58, IRQ59,\
IRQ60, IRQ61, IRQ62, IRQ63, IRQ64, IRQ65, IRQ66, IRQ67, IRQ68, IRQ69,\
IRQ70, IRQ71, IRQ72, IRQ73, IRQ74, IRQ75, IRQ76, IRQ77, IRQ78, IRQ79,\
IRQ80, IRQ81, IRQ82, IRQ83, IRQ84, IRQ85, IRQ86, IRQ87, IRQ88, IRQ89,\
 IRQ90, IRQ91, IRQ92, IRQ93, IRQ94, IRQ95, IRQ96, IRQ97, IRQ98, IRQ99,\
  IRQ100, IRQ101, IRQ102, IRQ103, IRQ104, IRQ105, IRQ106, IRQ107, IRQ108, IRQ109,\
  IRQ110, IRQ111, IRQ112, IRQ113, IRQ114, IRQ115, IRQ116, IRQ117, IRQ118, IRQ119,\
  IRQ120, IRQ121, IRQ122, IRQ123, IRQ124, IRQ125, IRQ126, IRQ127, IRQ128, IRQ129,\
  IRQ130, IRQ131, IRQ132, IRQ133, IRQ134, IRQ135, IRQ136, IRQ137, IRQ138
}IntCtrl_InterruptType;


#endif /*INTCTRL_CFG_H_*/
/**************************************************

  * END FILE IntCtrl_Cfg.h
  
****************************************************/










