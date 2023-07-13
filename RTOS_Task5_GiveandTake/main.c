/**
 * @file           : main.c
 * @author         : Abdelrahman Elhetamy
 * @date 		   : 09	June 2023
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
 * @brief TASK 5
 */
void PushButton(void * pvparam);
#define PushButtonPr (1)

void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
static uint8 ButtonState = 1;

int main(void)
{

	/*Init Function*/
	init();

	/* Creation of the Task*/
	xTaskHandle PushHandle  = NULL;
	xTaskCreate(PushButton,(const char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	xTaskHandle LedHandle = NULL ;
	xTaskCreate(Led,(const char*)"Led ",85,NULL,LedPr,&LedHandle);



	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){
	RCC_voidSysClkInt();
	RCC_EnablePeripheralClk(RCC_AHB,IOPA_EN);
	RCC_EnablePeripheralClk(RCC_AHB,IOPC_EN);

	/*initialize GPIO_LED_PIN Direction*/
	GPIO_u8SetPinDirection(GPIO_A,GPIO_PIN5,GPIO_OUTPUT_PP);

	/*initialize GPIO_Button_PIN Direction*/
	GPIO_u8SetPinDirection(GPIO_C,GPIO_PIN13,GPIO_INPUT_PU);

}
void PushButton(void * pvparam){
	portTickType Freq = 50;
	portTickType Start = xTaskGetTickCount();

	uint8 Local_u8PBState;
	while (1){
		/* if the Push Button is Pressed */
		vTaskDelay(100);
		GPIO_u8GetPinValue(GPIO_C,GPIO_PIN13,&Local_u8PBState);
		if (Local_u8PBState == 0){
			ButtonState = 0;
		}

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}

}


void Led(void * pvparam){
	portTickType Freq = 50;
	portTickType Start = xTaskGetTickCount();
	while (1){
		/* if the Push Button is Pressed */

		if (ButtonState == 0){
			GPIO_u8TogPinValue(GPIO_A,GPIO_PIN5);
			ButtonState = 1;
		}
		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}
}

