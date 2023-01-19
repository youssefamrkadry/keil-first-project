/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
#define PRIx(i) (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+((0x400)+((i/4)*4)))))
#define ENx(i)  (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+((0x100)+((i/32)*32)))))
#define DISx(i) (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+((0x180)+((i/32)*32)))))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
// User configurations container
// extern interrupt_table_cfg;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void SetPriorityGrouping(Group_SubgroupType PriorityGrouping);
static void IntCtrl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriority);
static void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntrNum);
static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntrNum);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void SetPriorityGrouping(void)                                      
* \Description     : Configure Grouping\SubGrouping System in APINT register in SCB                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : priority_grouping                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SetPriorityGrouping(Group_SubgroupType priority_grouping)
{
    // Reset APINT with VECTKEY before setting the PRIGROUP bits
    switch (priority_grouping)
    {
    case XXY: 
        APINT = 0xFA050000|(5<<(8));
        break;
    case XYY:
        APINT = 0xFA050000|(6<<(8));
        break;
    case YYY:
        APINT = 0xFA050000|(7<<(8));
        break;
    default:
        APINT = 0xFA050000|(4<<(8));
        break;
    }
}

/******************************************************************************
* \Syntax          : void SetPriorityGrouping(void)                                      
* \Description     : Assign Group\Subgroup priority in NVIC_PRIx Nvic Register                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : priority_grouping                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriority)
{
    PRIx(IntrNum) &= ~(7<<((8*((IntrNum%4)+1))-3));
    PRIx(IntrNum) |= (u8_IntPriority<<((8*((IntrNum%4)+1))-3));
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

    /*Configure Grouping\SubGrouping System in APINT register in SCB*/
    SetPriorityGrouping(GROUP_SUBGROUP_CONFIG);
    
    for (uint8 u8_idx = 0; u8_idx < CFG_INT_NUM; u8_idx++)
    {
        uint8 IntrPriority = 0;
        
        uint8 GroupPriority = interrupt_table_cfg[u8_idx].group_priority;
        uint8 SubgroupPriority = interrupt_table_cfg[u8_idx].subgroup_priority;

        uint8 IntNum = interrupt_table_cfg[u8_idx].type;

        switch (GROUP_SUBGROUP_CONFIG)
        {
        case XXY: 
            IntrPriority = ((GroupPriority & 0x03)<<1) | (SubgroupPriority & 0x01);
            break;
        case XYY:
            IntrPriority = ((GroupPriority & 0x01)<<2) | (SubgroupPriority & 0x03);
            break;
        case YYY:
            IntrPriority = SubgroupPriority & 0x07;
            break;
        default:
            IntrPriority = GroupPriority & 0x07;
            break;
        }

        /*Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
        IntCtrl_SetPriority(IntNum, IntrPriority);

        /*Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        IntCtrl_EnableInterrupt(IntNum);

    }

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
