/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  GPIO Port Driver
 *
 *      \details  The Driver Configure All GPIO pins, determine direction,
 *                function, internal attatchment and output current
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/Port.h"
#include "../Common/Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
// #define GPIO_BASE_ADDRESS_PORT(port)          ((GPIO_BASE_ADDRESS_AHB)+((0x1000)*port))
#define GPIO_BASE_ADDRESS_PORT(port)          (port<4? ((GPIO_BASE_ADDRESS_APB)+((0x1000)*(port))) : ((GPIO_BASE_ADDRESS_APB+0x20000)+((0x1000)*(port-4))))
// Comment one of them to choose between AHB and APB

#define GPIOLOCK_PORT(port)                       (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x520)))
#define GPIOCR_PORT(port)                         (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x524)))
#define GPIODEN_PORT(port)                        (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x51C)))
#define GPIOAFSEL_PORT(port)                      (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x420)))
#define GPIOPCTL_PORT(port)                       (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x52C)))
#define GPIODIR_PORT(port)                        (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x400)))
#define GPIOPUR_PORT(port)                        (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x510)))
#define GPIOPDR_PORT(port)                        (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x514)))
#define GPIODR2R_PORT(port)                       (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x500)))
#define GPIODR4R_PORT(port)                       (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x504)))
#define GPIODR8R_PORT(port)                       (*((volatile uint32*)((GPIO_BASE_ADDRESS_PORT(port))+0x508)))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void CommitRegisterChange(uint8 port);
static void InitPortClock(Dio_ChannelType channel);
static void EnableDigitalPin(Dio_ChannelType channel);
static void DisableDigitalPin(Dio_ChannelType channel);
static void SetPinMode(Dio_ChannelType channel, Port_PinModeType mode);
static void SetPinDirection(Dio_ChannelType channel, Port_PinDirectionType direction);
static void SetInternalAttatch(Dio_ChannelType channel, Port_PinInternalAttachType attatchType);
static void SetOutputCurrent(Dio_ChannelType channel, Port_PinOutputCurrentType current);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void InitPortClock(Dio_ChannelType channel)                                      
* \Description     : enable and provide a clock to GPIO Ports in Run mode                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void InitPortClock(Dio_ChannelType channel)
{
    uint8 port = channel / 10;
    RCGCGPIO |= (1<<port);
}

/******************************************************************************
* \Syntax          : void CommitRegisterChange(uint8 port)                                      
* \Description     : commit changes in GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN registers                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void CommitRegisterChange(uint8 port)
{
    GPIOLOCK_PORT(port) = 0x4C4F434B;
    GPIOCR_PORT(port) |= 0xFF;
}

/******************************************************************************
* \Syntax          : void SetPinMode(Dio_ChannelType channel, Port_PinModeType mode)                                      
* \Description     : set GPIO pin to DIO or alternate function using GPIOAFSEL then if it's
*                    an alternative function determine the alternative function using GPIOCTL                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel, mode                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void SetPinMode(Dio_ChannelType channel, Port_PinModeType mode)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    CommitRegisterChange(port);

    if(mode == Mode_DIO)
    {
        GPIOAFSEL_PORT(port) &= ~(1<<pin);
    }
    else
    {
        GPIOAFSEL_PORT(port) |= (1<<pin);

        GPIOPCTL_PORT(port) &= ~(0xF<<(pin*4));
        GPIOPCTL_PORT(port) |= (mode<<(pin*4));
    }
}

/******************************************************************************
* \Syntax          : void SetPinDirection(Dio_ChannelType channel, Port_PinDirectionType direction)
* \Description     : set pin direction using GPIODIR                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel, direction                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void SetPinDirection(Dio_ChannelType channel, Port_PinDirectionType direction)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    if (direction == IN)
    {
        GPIODIR_PORT(port) &= ~(1<<pin);
    }
    else if (direction == OUT)
    {
        GPIODIR_PORT(port) |= (1<<pin);
    }
}

/******************************************************************************
* \Syntax          : void EnableDigitalPin(Dio_ChannelType channel)
* \Description     : enable digital pin in GPIODEN register                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void EnableDigitalPin(Dio_ChannelType channel)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    CommitRegisterChange(port);

    GPIODEN_PORT(port) |= (1<<pin);
}

/******************************************************************************
* \Syntax          : void DisableDigitalPin(Dio_ChannelType channel)
* \Description     : disable digital pin in GPIODEN register                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void DisableDigitalPin(Dio_ChannelType channel)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    CommitRegisterChange(port);

    GPIODEN_PORT(port) &= ~(1<<pin);
}

/******************************************************************************
* \Syntax          : void SetInternalAttatch(Dio_ChannelType channel, Port_PinInternalAttachType attatchType)
* \Description     : pull up using GPIOPUR or pull down using GPIOPDR or tristate buffer                         
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel, attatchType                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void SetInternalAttatch(Dio_ChannelType channel, Port_PinInternalAttachType attatchType)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    CommitRegisterChange(port);

    switch (attatchType)
    {
    case PULL_UP:
        GPIOPUR_PORT(port) |= (1<<pin);
        break;
    case PULL_DOWN:
        GPIOPDR_PORT(port) |= (1<<pin);
        break;
    case TRISTATE:
        GPIOPUR_PORT(port) &= ~(1<<pin);
        GPIOPDR_PORT(port) &= ~(1<<pin);
        break;
    default:
        break;
    }
}

/******************************************************************************
* \Syntax          : void SetInternalAttatch(Dio_ChannelType channel, Port_PinInternalAttachType attatchType)
* \Description     : select pad drive current using GPIODR2R, GPIODR4R, GPIODR8R registers                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : channel, attatchType                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
static void SetOutputCurrent(Dio_ChannelType channel, Port_PinOutputCurrentType current)
{
    uint8 port = channel / 10;
    uint8 pin = channel % 10;

    switch (current)
    {
    case CURRENT_2MA:
        GPIODR2R_PORT(port) |= (1<<pin);
        break;
    case CURRENT_4MA:
        GPIODR4R_PORT(port) |= (1<<pin);
        break;
    case CURRENT_8MA:
        GPIODR8R_PORT(port) |= (1<<pin);
        break;
    default:
        break;
    }
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Port_Init(void)
{
    uint8 u8_idx;
    
    for (u8_idx = 0; u8_idx < pins_number; u8_idx++)
    {
        InitPortClock(port_configs[u8_idx].channel);
        SetPinDirection(port_configs[u8_idx].channel, port_configs[u8_idx].direction);
        SetPinMode(port_configs[u8_idx].channel, port_configs[u8_idx].mode);
        SetInternalAttatch(port_configs[u8_idx].channel, port_configs[u8_idx].internal_attach);
        SetOutputCurrent(port_configs[u8_idx].channel, port_configs[u8_idx].output_current);
        EnableDigitalPin(port_configs[u8_idx].channel);
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
