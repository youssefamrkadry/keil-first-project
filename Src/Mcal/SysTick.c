/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief  SysTick timer driver
 *
 *      \details  The criver configures the systick timer and utilizes its functions during runtime
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/SysTick.h"
#include "../Common/Mcu_Hw.h"
#include "../Config/Clk_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
cb_type callback_ptr = NULL_PTR;
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
* \Syntax          : void SysTick_Start(void)                                      
* \Description     : initialize SysTick Timer                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Start(void)
{
    STCTRL |= (1<<2); // select system clock for clock source
    STCTRL |= (1<<1); // enable SysTick interrupt
    STCTRL |= (1<<0); // enable timer in multi-shot mode

}

/******************************************************************************
* \Syntax          : void SysTick_InterruptCountdown(uint32 countdown_ms)
* \Description     : load value and start countdown untill counter
*                    reaches zero and interrupt is called
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_InterruptCountdown(uint32 countdown_ms)
{
    uint32 reload_value;

    switch (CLK_XTAL)
    {
    case XTAL_5:
        reload_value = ((5000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    case XTAL_6:
        reload_value = ((6000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    case XTAL_8:
        reload_value = ((8000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    case XTAL_10:
        reload_value = ((10000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    case XTAL_12:
        reload_value = ((12000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    case XTAL_16:
        reload_value = ((16000/CLK_SYSDIV)*countdown_ms) - 1;
        break;
    default:
        reload_value = 0;
        break;
    }

    STRELOAD &= ~(0x00FFFFFF);
    if (reload_value <= 0x00FFFFFF)
    {
        STRELOAD |= reload_value;
    }
    STCURRENT &= ~(0x00FFFFFF);

}

/******************************************************************************
* \Syntax          : void SysTick_RegisterInterruptCallback(cb_type ptr)
* \Description     : assign callback function to the timer
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_RegisterInterruptCallback(cb_type ptr)
{
    if (ptr != NULL_PTR)
    {
        callback_ptr = ptr;
    }
}

/******************************************************************************
* \Syntax          : void SysTick_Handler()
* \Description     : ISR for SysTick Timer
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Handler()
{
    if (callback_ptr != NULL_PTR)
    {
        callback_ptr();
    }
}

/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
