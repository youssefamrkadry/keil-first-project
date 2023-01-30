/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition  (Microcontroller Hardware)  
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
// Bit field
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R; // Register
    INTCTRL_BF B; // Bit
}INTCTRL_Tag;

typedef struct 
{
    uint32 MOSCDIS   :1;
    uint32           :3;
    uint32 OSCSRC    :2;
    uint32 XTAL      :5;
    uint32 BYPASS    :1;
    uint32           :1;
    uint32 PWRDN     :1;
    uint32           :3;
    uint32 PWMDIV    :3;
    uint32 USEPWMDIV :1;
    uint32           :1;
    uint32 USESYSDIV :1;
    uint32 SYSDIV    :4;
    uint32 ACG       :1;
    uint32           :4;
}RCC_BF;
typedef union 
{
    uint32 R; // Register
    RCC_BF B; // Bit
}RCC_Tag;

typedef struct 
{
    uint32             :4;
    uint32 OSCSRC2     :3;
    uint32             :4;
    uint32 BYPASS2     :1;
    uint32             :1;
    uint32 PWRDN2      :1;
    uint32 USBPWRDN    :1;
    uint32             :7;
    uint32 SYSDIV2LSB  :1;
    uint32 SYSDIV2     :6;
    uint32             :1;
    uint32 DIV400      :1;
    uint32 USERCC2     :1;
}RCC2_BF;
typedef union 
{
    uint32 R; // Register
    RCC2_BF B; // Bit
}RCC2_Tag;

typedef struct 
{
    uint32 MEMA        :1;
    uint32 BUSA        :1;
    uint32             :1;
    uint32 USGA        :1;
    uint32             :3;
    uint32 SVCA        :1;
    uint32 MON         :1;
    uint32             :1;
    uint32 PNDSV       :1;
    uint32 TICK        :1;
    uint32 USAGEP      :1;
    uint32 MEMP        :1;
    uint32 BUSP        :1;
    uint32 SVC         :1;
    uint32 MEM         :1;
    uint32 BUS         :1;
    uint32 USAGE       :1;
    uint32             :13;
}SYSHNDCTRL_BF;
typedef union 
{
    uint32 R; // Register
    SYSHNDCTRL_BF B; // Bit
}SYSHNDCTRL_Tag;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
#define INTCTRL                                (*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
#define SYSHNDCTRL                             (*((volatile SYSHNDCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)))
#define STCTRL                                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
#define STRELOAD                               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)))
#define STCURRENT                              (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)))
// Example: INTCTRL.R if want to access full register, INTCTRL.B.VECPEND = write 4 bits

#define GPIO_BASE_ADDRESS_APB                  0x40004000
#define GPIO_BASE_ADDRESS_AHB                  0x40058000

#define SYS_CTRL_BASE_ADDRESS                  0x400FE000
#define RCC                                    (*((volatile RCC_Tag*)(SYS_CTRL_BASE_ADDRESS+0x060)))
#define RCC2                                   (*((volatile RCC2_Tag*)(SYS_CTRL_BASE_ADDRESS+0x070)))
#define RCGCGPIO                               (*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x608)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
