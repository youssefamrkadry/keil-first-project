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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

// You can perform %1000 to get the masking address and /1000 to get the PortType
typedef enum
{
    A0 = PORTA*1000 + 1, A1 = PORTA*1000 + 2, A2 = PORTA*1000 + 4, A3 = PORTA*1000 + 8, A4 = PORTA*1000 + 16, A5 = PORTA*1000 + 32, A6 = PORTA*1000 + 64, A7 = PORTA*1000 + 128,
    B0 = PORTB*1000 + 1, B1 = PORTB*1000 + 2, B2 = PORTB*1000 + 4, B3 = PORTB*1000 + 8, B4 = PORTB*1000 + 16, B5 = PORTB*1000 + 32, B6 = PORTB*1000 + 64, B7 = PORTB*1000 + 128,
    C0 = PORTC*1000 + 1, C1 = PORTC*1000 + 2, C2 = PORTC*1000 + 4, C3 = PORTC*1000 + 8, C4 = PORTC*1000 + 16, C5 = PORTC*1000 + 32, C6 = PORTC*1000 + 64, C7 = PORTC*1000 + 128,
    D0 = PORTD*1000 + 1, D1 = PORTD*1000 + 2, D2 = PORTD*1000 + 4, D3 = PORTD*1000 + 8, D4 = PORTD*1000 + 16, D5 = PORTD*1000 + 32, D6 = PORTD*1000 + 64, D7 = PORTD*1000 + 128,
    E0 = PORTE*1000 + 1, E1 = PORTE*1000 + 2, E2 = PORTE*1000 + 4, E3 = PORTE*1000 + 8, E4 = PORTE*1000 + 16, E5 = PORTE*1000 + 32,
    F0 = PORTF*1000 + 1, F1 = PORTF*1000 + 2, F2 = PORTF*1000 + 4, F3 = PORTF*1000 + 8, F4 = PORTF*1000 + 16
}Dio_ChannelType;

typedef enum
{
    LOW, HIGH
}Dio_LevelType;

typedef enum
{
    PORTA, PORTB, PORTC, PORTD, PORTE, PORTF
}Dio_PortType;

typedef uint8 Dio_PortLevelType;

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
