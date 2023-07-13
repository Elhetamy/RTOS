/**
 * @file           : main.c
 * @author         : Abdelrahman Elhetamy
 * @date 		   : 08	June 2023
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"

/**
 * @brief TASK 4		(PushToRun)
 */

/*Define Tasks Priorities*/
#define 	DCMotor_Priority	(3)
#define  	ButtonOn_PRIORITY 	(2)

void DCOn_code (void * pvParamter);
void ButtonIntro_code (void * pvParamter) ;

/*Create Task Handles Create */
xTaskHandle Task1Hand = NULL;
xTaskHandle Task2Hand = NULL;

static uint8 Global_u8Flag = 0;




int main(void)
{

	RCC_voidSysClkInt();
	RCC_EnablePeripheralClk(RCC_AHB,IOPA_EN);
	RCC_EnablePeripheralClk(RCC_AHB,IOPC_EN);

	xTaskCreate(DCOn_code,(const char *)"Task1",85,NULL,DCMotor_Priority,&Task1Hand);
	xTaskCreate(ButtonIntro_code,(const char *)"Task2",85,NULL,ButtonOn_PRIORITY,&Task2Hand);

	/*initialize GPIO_LED_PIN Direction*/
	GPIO_u8SetPinDirection(GPIO_A,GPIO_PIN0,GPIO_OUTPUT_PP);

	/*initialize GPIO_Button_PIN Direction*/
	GPIO_u8SetPinDirection(GPIO_C,GPIO_PIN13,GPIO_INPUT_PU);

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}


void DCOn_code (void * pvParamter)
{
	while(1){
		vTaskDelay(200);
		if (Global_u8Flag == 1)
		{

			GPIO_u8TogPinValue(GPIO_A,GPIO_PIN0);
			/*Send Task in Blocked Queue for 200 Ticks */
			Global_u8Flag = 0;

		}
	}
}
void ButtonIntro_code (void * pvParamter)
{
	uint8 Local_u8Result;
	while(1)
	{

		vTaskDelay(100);
		GPIO_u8GetPinValue(GPIO_C,GPIO_PIN13,&Local_u8Result);
		if (Local_u8Result == 0 )
		{
			Global_u8Flag = 1;

		}

	}
}
