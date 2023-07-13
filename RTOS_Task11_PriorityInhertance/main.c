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
 * @brief TASK11		(Priority Inheritance)
 */
#if TASKS == 	11

#define MAX_USINGSEMAPHORE 3
void Led2(void * pvparam);
#define Led2Pr (3)

void PushButton2(void * pvparam);
#define PushButton2Pr (2)


void Led(void * pvparam);
#define LedPr (1)

void init(void);

xSemaphoreHandle ButtonSemaphore = NULL;
/* Creation of the Task*/
xTaskHandle Led2Handle  = NULL;

xTaskHandle LedHandle = NULL ;
xTaskHandle PushHandle2  = NULL;

int main(void)
{


	xTaskCreate(Led2,(const char*)"Led 2",85,NULL,Led2Pr,&Led2Handle);

	/* Creation of the Task*/

	xTaskCreate(PushButton2,(const char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);


	xTaskCreate(Led,(const char*)"Led ",85,NULL,LedPr,&LedHandle);

	/*Init Function*/
	init();

	/*Create Semaphore for the Button */
	vSemaphoreCreateBinary(ButtonSemaphore);


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
	GPIO_u8SetPinDirection(GPIO_A,GPIO_PIN0,GPIO_OUTPUT_PP);

}
void Led2(void * pvparam){

	portTickType Freq = 1000;
	portTickType Start = xTaskGetTickCount();
	vTaskDelay(20);
	while (1){

		/* If the Resource No One is Using so Take the Semaphore  **/
		while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100)){
			vTaskDelay(100);
			GPIO_u8TogPinValue(GPIO_A,GPIO_PIN0);
		}
		vTaskPrioritySet(Led2Handle,MAX_USINGSEMAPHORE);

		vTaskDelay(1000);

		xSemaphoreGive(ButtonSemaphore);
		vTaskPrioritySet(Led2Handle,Led2Pr);

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}

}


void PushButton2(void * pvparam){
	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	while (1){

		while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));
		vTaskPrioritySet(PushHandle2,MAX_USINGSEMAPHORE);

		/*Change the State **/
		GPIO_u8TogPinValue(GPIO_A,GPIO_PIN0);

		vTaskDelay(1000);

		/**Give the Semaphore */
		xSemaphoreGive(ButtonSemaphore);
		vTaskPrioritySet(PushHandle2,PushButton2Pr);

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}

}



void Led(void * pvparam){
	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	vTaskDelay(30);
	while (1){

		GPIO_u8TogPinValue(GPIO_A,GPIO_PIN0);

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}


}
