/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file PulseMeter_Core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PulseMeter_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern volatile uint32 Capture_Flag_g;
extern volatile uint32 Capture_Readings_1_g;
extern volatile uint32 Capture_Readings_2_g;
extern volatile uint32 Capture_Readings_3_g;
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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void App_Init (void)
{
	 PORT_Init();
	 LCD_Init();
	 IRQH_SetGlobalInterrupts(INTERRUPT_ENABLE);
	 GPT_Init();
	 PWM_Init();
	 ICU_Init();
}
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PulseMeterCaptureWave (void)
{
	uint32 Duty_Cycle = 0;
	uint32 Frequency = 0;
	uint32 ON_Time=0;
	uint32 Total_Time=0;
	if (Capture_Flag_g == 3)
	{
		ON_Time = Capture_Readings_2_g - Capture_Readings_1_g;
		Total_Time = Capture_Readings_3_g - Capture_Readings_1_g;
		Duty_Cycle = (ON_Time* 100) / Total_Time;
		Frequency = F_CPU / (Total_Time * 1024);
		
		LCD_GoTo(0 , 0);
		LCD_WriteString("Duty_Cycle = ");
		LCD_WriteInteger(Duty_Cycle);
		LCD_WriteChar('%');
		
		LCD_GoTo(1 , 0);
		LCD_WriteString("Frequency = ");
		LCD_WriteInteger(Frequency);
		LCD_WriteString("Hz");
		
		_delay_ms(50);
		Capture_Flag_g =0;
		//Enable ICU INTERRUPT
		SET_BIT(TIMSK , 5);
		
	}
}
/**********************************************************************************************************************
 *  END OF FILE: PulseMeter_Core.c
 *********************************************************************************************************************/