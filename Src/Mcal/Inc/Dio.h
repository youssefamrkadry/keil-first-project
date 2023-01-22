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

typedef enum
{
    PORTA, PORTB, PORTC, PORTD, PORTE, PORTF
}Dio_PortType;

typedef uint8 Dio_PortLevelType;

// You can perform %10 to get the bit and /10 to get the PortType
typedef enum
{
    A0 = PORTA*10 + 0, A1 = PORTA*10 + 1, A2 = PORTA*10 + 2, A3 = PORTA*10 + 3, A4 = PORTA*10 + 4, A5 = PORTA*10 + 5, A6 = PORTA*10 + 6, A7 = PORTA*10 + 7,
    B0 = PORTB*10 + 0, B1 = PORTB*10 + 1, B2 = PORTB*10 + 2, B3 = PORTB*10 + 3, B4 = PORTB*10 + 4, B5 = PORTB*10 + 5, B6 = PORTB*10 + 6, B7 = PORTB*10 + 7,
    C0 = PORTC*10 + 0, C1 = PORTC*10 + 1, C2 = PORTC*10 + 2, C3 = PORTC*10 + 3, C4 = PORTC*10 + 4, C5 = PORTC*10 + 5, C6 = PORTC*10 + 6, C7 = PORTC*10 + 7,
    D0 = PORTD*10 + 0, D1 = PORTD*10 + 1, D2 = PORTD*10 + 2, D3 = PORTD*10 + 3, D4 = PORTD*10 + 4, D5 = PORTD*10 + 5, D6 = PORTD*10 + 6, D7 = PORTD*10 + 7,
    E0 = PORTE*10 + 0, E1 = PORTE*10 + 1, E2 = PORTE*10 + 2, E3 = PORTE*10 + 3, E4 = PORTE*10 + 4, E5 = PORTE*10 + 5,
    F0 = PORTF*10 + 0, F1 = PORTF*10 + 1, F2 = PORTF*10 + 2, F3 = PORTF*10 + 3, F4 = PORTF*10 + 4
}Dio_ChannelType;

typedef enum
{
    LOW, HIGH
}Dio_LevelType;

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
