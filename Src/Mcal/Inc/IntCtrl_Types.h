/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

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
    GPIO_PORTA_INT,
    GPIO_PORTB_INT,
    GPIO_PORTC_INT,
    GPIO_PORTD_INT,
    GPIO_PORTE_INT,
    UART0_INT,
    UART1_INT,
    SSI0_INT,
    I2C0_INT,
    PWM0_FAULT_INT,
    PWM0_GEN0_INT,
    PWM0_GEN1_INT,
    PWM0_GEN2_INT,
    QEI0_INT,
    ADC0_SEQ0_INT,
    ADC0_SEQ1_INT,
    ADC0_SEQ2_INT,
    ADC0_SEQ3_INT,
    WATCHDOG_TIMER01_INT,
    TIMER0A_16_32_INT,
    TIMER0B_16_32_INT,
    TIMER1A_16_32_INT,
    TIMER1B_16_32_INT,
    TIMER2A_16_32_INT,
    TIMER2B_16_32_INT,
    ANALOG_COMP0_INT,
    ANALOG_COMP1_INT,
    SYS_CTRL_INT = 28,
    FLASH_EEPROM_CTRL_INT,
    GPIO_PORTF_INT,
    UART2_INT = 33,
    SSI1_INT,
    TIMER3A_16_32_INT,
    TIMER3B_16_32_INT,
    I2C1_INT,
    QEI1_INT,
    CAN0_INT,
    CAN1_INT,
    HIBERNATION_MODULE_INT = 43,
    USB_INT,
    PWM_GEN3_INT,
    uDMA_SW_INT,
    uDMA_ERROR_INT,
    ADC1_SEQ0_INT,
    ADC1_SEQ1_INT,
    ADC1_SEQ2_INT,
    ADC1_SEQ3_INT,
    SSI2_INT = 57,
    SSI3_INT,
    UART3_INT,
    UART4_INT,
    UART5_INT,
    UART6_INT,
    UART7_INT,
    I2C2_INT = 68,
    I2C3_INT,
    TIMER4A_16_32_INT,
    TIMER4B_16_32_INT,
    TIMER5A_16_32_INT = 92,
    TIMER5B_16_32_INT,
    TIMER0A_32_64_INT,
    TIMER0B_32_64_INT,
    TIMER1A_32_64_INT,
    TIMER1B_32_64_INT,
    TIMER2A_32_64_INT,
    TIMER2B_32_64_INT,
    TIMER3A_32_64_INT,
    TIMER3B_32_64_INT,
    TIMER4A_32_64_INT,
    TIMER4B_32_64_INT,
    TIMER5A_32_64_INT,
    TIMER5B_32_64_INT,
    SYS_EXEPTION_INT,
    PWM1_GEN0_INT = 134,
    PWM1_GEN1_INT,
    PWM1_GEN2_INT,
    PWM1_GEN3_INT,
    PWM1_FAULT_INT
}IntCtrl_InterruptType;

typedef enum
{
    XXX = 4,
    XXY,
    XYY,
    YYY
}Group_SubgroupType;
 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
