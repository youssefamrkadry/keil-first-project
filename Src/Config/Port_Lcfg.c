/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

// {Dio_ChannelType channel, Port_PinDirectionType direction, Port_PinInternalAttachType internal_attach, Port_PinOutputCurrentType output_current}
// Default direction is IN
// Default attatchment is TRISTATE
// Default current is CURRENT_2MA
Port_ConfigType port_configs[] = {
    {F3, Mode_DIO, OUT, TRISTATE, CURRENT_2MA},
    {F0, Mode_DIO, IN, PULL_UP, CURRENT_2MA},
    {F4, Mode_DIO, IN, PULL_UP, CURRENT_2MA}
    };

uint8 pins_number = sizeof(port_configs) / sizeof(Port_ConfigType);

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
