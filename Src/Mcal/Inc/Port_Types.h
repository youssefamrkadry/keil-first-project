/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  Header files that contains datatypes and structures
 *                that will be used in port and DIO drivers     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

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

typedef enum
{
    OUT, IN
}Port_PinDirectionType;

typedef enum
{
    PULL_UP, PULL_DOWN, TRISTATE
}Port_PinInternalAttachType;

typedef enum
{
    CURRENT_2MA, CURRENT_4MA, CURRENT_8MA
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
 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
