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
 * TASK 9		(DEADLOCK)
 */


void PushButton(void * pvparam);
#define PushButtonPr (1)

void PushButton2(void * pvparam);
#define PushButton2Pr (2)


void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
static uint8 ButtonState = 1;
static uint8 ButtonState2 = 1;


xSemaphoreHandle ButtonSemaphore = NULL;

xSemaphoreHandle Button2Semaphore = NULL;

int main(void)
{

	/* Creation of the Task*/
	xTaskHandle PushHandle  = NULL;
	xTaskCreate(PushButton,(const char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	/* Creation of the Task*/
	xTaskHandle PushHandle2  = NULL;
	xTaskCreate(PushButton2,(const char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);


	xTaskHandle LedHandle = NULL ;
	xTaskCreate(Led,(const char*)"Led ",85,NULL,LedPr,&LedHandle);

	/*Init Function*/
	init();

	/*Create Semaphore for the Button */
	vSemaphoreCreateBinary(ButtonSemaphore);

	/*Create Semaphore for the Button */
	vSemaphoreCreateBinary(Button2Semaphore);

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

	/*initialize GPIO_Button_PIN Direction*/
	GPIO_u8SetPinDirection(GPIO_A,GPIO_PIN0,GPIO_INPUT_PU);

}
void PushButton(void * pvparam){

	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	uint8 Local_u8PBState;
	while (1){
		/* if the Push Button is Pressed */
		GPIO_u8GetPinValue(GPIO_C,GPIO_PIN13,&Local_u8PBState);
		if (Local_u8PBState == 0){

			/* If the Resource No One is Using so Take the Semaphore  **/
			if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){

				vTaskDelay(1000);

				while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));

				/*Change the State **/
				ButtonState = 0;

				/**Give the Semaphore */

				xSemaphoreGive(Button2Semaphore);

				xSemaphoreGive(ButtonSemaphore);


			}

		}

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}

}


void PushButton2(void * pvparam){
	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	uint8 Local_u8PBState;
	while (1){
		/* if the Push Button is Pressed */
		GPIO_u8GetPinValue(GPIO_A,GPIO_PIN0,&Local_u8PBState);
		if (Local_u8PBState == 0){

			/* If the Resource No One is Using so Take the Semaphore  **/
			if(pdTRUE == xSemaphoreTake(Button2Semaphore,100)){

				vTaskDelay(1000);

				while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));

				/*Change the State **/
				ButtonState2 = 0;

				/**Give the Semaphore */

				xSemaphoreGive(ButtonSemaphore);

				xSemaphoreGive(Button2Semaphore);


			}

			/*Make the Task Periodic with Period 50 Tick */
			vTaskDelayUntil(&Start,Freq);
		}

	}
}


void Led(void * pvparam){
	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	while (1){
		/* if the Push Button is Pressed */

		/* If the Resource No One is Using so Take the Semaphore  **/
		if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){

			vTaskDelay(1000);

			while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));

			if (ButtonState == 0 && ButtonState2 == 0){
				GPIO_u8TogPinValue(GPIO_A,GPIO_PIN5);
				ButtonState = 1;
				ButtonState2 = 1;
			}

			/**Give the Semaphore */
			xSemaphoreGive(Button2Semaphore);
			xSemaphoreGive(ButtonSemaphore);

			/*Make the Task Periodic with Period 50 Tick */
			vTaskDelayUntil(&Start,Freq);
		}
	}
}