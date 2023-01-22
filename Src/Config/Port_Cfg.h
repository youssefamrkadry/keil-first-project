/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  Header file for GPIO port configurations     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Mcal/Inc/Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    Dio_ChannelType channel;
    Port_PinModeType mode;
    Port_PinDirectionType direction;
    Port_PinInternalAttachType internal_attach;
    Port_PinOutputCurrentType output_current;
}Port_ConfigType;

extern Port_ConfigType port_configs[];
extern uint8 pins_number;

#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
