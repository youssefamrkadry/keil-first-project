/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital Input / Output Driver
 *
 *      \details  The Driver reads, writes and toggles channels as well as read and write into entire ports
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/Dio.h"
#include "../Common/Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
#define GPIO_BASE_ADDRESS_AHB_PORT(port)          ((GPIO_BASE_ADDRESS_AHB)+((0x1000)*(port)))
#define GPIODATA_PORT(port)                       (*((volatile uint32*)(GPIO_BASE_ADDRESS_AHB_PORT(port))))
#define GPIODATA_MSK_PORT(port, bit)              (*((volatile uint32*)((GPIO_BASE_ADDRESS_AHB_PORT(port)) + ((1<<bit)<<2))))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 bit = ChannelId % 10;
    uint8 port = ChannelId / 10;

    return (((GPIODATA_PORT(port))&(1<<bit))>>bit);
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 bit = ChannelId % 10;
    uint8 port = ChannelId / 10;

    if (Level == HIGH)
    {
        GPIODATA_PORT(port) |= (1<<bit);
    }
    else if (Level == LOW)
    {
        GPIODATA_PORT(port) &= ~(1<<bit);
    }
}

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
Dio_LevelType Dio_ReadChannelMasked(Dio_ChannelType ChannelId)
{
    uint8 bit = ChannelId % 10;
    uint8 port = ChannelId / 10;

    return ((GPIODATA_MSK_PORT(port,bit)) >> bit);
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)                                      
* \Description     : write to a certain DIO channel using address masking                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId, Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannelMasked(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 bit = ChannelId % 10;
    uint8 port = ChannelId / 10;

    GPIODATA_MSK_PORT(port,bit) = (Level<<bit);
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
