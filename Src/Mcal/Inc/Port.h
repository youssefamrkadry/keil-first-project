/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header file for Port Module    
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    OUT, IN
}Port_PinDirectionType;

typedef enum
{
    PULL_UP, PULL_DOWN, NO_ATTACH
}Port_PinInternalAttachType;

typedef enum
{
    CURRENT_0MA, CURRENT_2MA, CURRENT_4MA, CURRENT_8MA
}Port_PinOutputCurrentType;

// Corresponds to the value written in GPIOPCTL PMCx bit field denoting the digital alternate function
typedef enum
{
    Mode_DIO       = 0,
    Mode_U0Rx      = 1,
    Mode_U0Tx      = 1,
    Mode_CAN1Rx    = 8,
    Mode_CAN1Tx    = 8,
    Mode_SSI0Clk   = 2,
    Mode_SSI0Fss   = 2,
    Mode_SSI0Rx    = 2,
    Mode_SSI0Tx    = 2,
    Mode_I2C1SCL   = 3,
    Mode_M1PWM2    = 5,
    Mode_I2C1SDA   = 3,
    Mode_M1PWM3    = 5
}Port_PinModeType;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void Port_Init(void)                                      
* \Description     : initialize GPIO pins by parsing the configuration array
*                    and editing GPIO related registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(void);
 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/