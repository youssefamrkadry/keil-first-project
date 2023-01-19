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
extern 
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
* \Description     : Initialize APINT with the configured group-subgroup priority                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : priority_grouping                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SetPriorityGrouping(uint8 priority_grouping)
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

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    SetPriorityGrouping(GROUP_SUBGROUP_CONFIG);
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */


	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
