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
 * @brief TASK	7
 */

void PushButton(void * pvparam);
#define PushButtonPr (1)

void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
static uint8 ButtonState = 1;

static uint8 ButtonStateFlag = 0;

#define FrogetGlobalInterrupt 0  /* 0  for Nodefect 1 for Defect **/

int main(void)
{

	/* Creation of the Task*/
	xTaskHandle PushHandle  = NULL;
	xTaskCreate(PushButton,(const char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	xTaskHandle LedHandle = NULL ;
	xTaskCreate(Led,(const char*)"Led",85,NULL,LedPr,&LedHandle);

	/*Init Function*/
	init();

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
	portTickType Freq = 250;
	portTickType Start = xTaskGetTickCount();
	uint8 Local_u8PBState;
	while (1){
		/* if the Push Button is Pressed */
		GPIO_u8GetPinValue(GPIO_C,GPIO_PIN13,&Local_u8PBState);
		if (Local_u8PBState == 0){
			/* If the Resource No One is Using so Stop Scheduling to Use it **/
			if(ButtonStateFlag == 0){
				/**Disable Global Interrupt*/
				taskDISABLE_INTERRUPTS();
				//__asm (CPSID f);


				/*Raise the Flag */
				ButtonStateFlag = 1;

#if (FrogetGlobalInterrupt == 0)
				/**Enable Global Interrupt*/
				taskENABLE_INTERRUPTS();
				//__asm (CPSIE f);
#endif

				/*Change the State **/
				ButtonState = 0;


				/**Disable Global Interrupt*/
				taskDISABLE_INTERRUPTS();
				//__asm (CPSID f);

				/*Release the Flag */
				ButtonStateFlag = 0;
#if (FrogetGlobalInterrupt == 0)
				/**Enable Global Interrupt*/
				taskENABLE_INTERRUPTS();
				//__asm (CPSIE f);
#endif
			}
			/*Else Delay 10 Tick till the Resource is Free **/
			else {
				vTaskDelay(10);
				taskENABLE_INTERRUPTS();
				//__asm (CPSIE f);
			}

		}

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}

}


void Led(void * pvparam){
	portTickType Freq = 100;
	portTickType Start = xTaskGetTickCount();
	while (1){
		/* if the Push Button is Pressed */
		/* If the Resource No One is Using so Raise a Flag to Use it **/
		if(ButtonStateFlag == 0){
			/**Disable Global Interrupt*/
			taskDISABLE_INTERRUPTS();
			//__asm (CPSID f);

			/*Raise the Flag */
			ButtonStateFlag = 1;

#if (FrogetGlobalInterrupt == 0)
			/**Enable Global Interrupt*/
			taskENABLE_INTERRUPTS();
			//__asm (CPSIE f);
			#endif

			if (ButtonState == 0){
				GPIO_u8TogPinValue(GPIO_A,GPIO_PIN5);
				ButtonState = 1;
			}

			/**Disable Global Interrupt*/
			taskDISABLE_INTERRUPTS();
			//__asm (CPSID f);

			/*Release the Flag */
			ButtonStateFlag = 0;

#if (FrogetGlobalInterrupt == 0)
			/**Enable Global Interrupt*/
			taskENABLE_INTERRUPTS();
			//__asm (CPSIE f);
			#endif
		}
		/*Else Delay 10 Tick till the Resource is Free **/
		else {
			vTaskDelay(10);
			taskENABLE_INTERRUPTS();
			//__asm (CPSIE f);
		}

		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}
}


