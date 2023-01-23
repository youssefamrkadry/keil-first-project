/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : read a certain DIO channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)                                      
* \Description     : write to a certain DIO channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId, Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/******************************************************************************
* \Syntax          : void Dio_ToggleChannel(Dio_ChannelType ChannelId)                                      
* \Description     : toggle a certain DIO channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                  
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_ToggleChannel(Dio_ChannelType ChannelId);


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannelMasked(Dio_ChannelType ChannelId)                                      
* \Description     : read a certain DIO channel using address masking                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_ReadChannelMasked(Dio_ChannelType ChannelId);

/******************************************************************************
* \Syntax          : void Dio_WriteChannelMasked(Dio_ChannelType ChannelId, Dio_LevelType Level)                                      
* \Description     : write to a certain DIO channel using address masking                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId, Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannelMasked(Dio_ChannelType ChannelId, Dio_LevelType Level);

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)                                      
* \Description     : read a certain Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)                                      
* \Description     : write to a certain Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId, Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)                                      
* \Description     : toggle a certain DIO channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId                     
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
 
#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
