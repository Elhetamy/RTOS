/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file RCC_program.c
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "RCC_interface.h"
#include "RCC_reg.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"





void RCC_voidSysClkInt(void)
{

	/*Configure AHB Prescaler*/
#if AHB_PRESCALER == Divided_by_2
	CLR_BIT(RCC_CFGR,HPRE0);
	CLR_BIT(RCC_CFGR,HPRE1);
	CLR_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_4
	SET_BIT(RCC_CFGR,HPRE0);
	CLR_BIT(RCC_CFGR,HPRE1);
	CLR_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_8
	CLR_BIT(RCC_CFGR,HPRE0);
	SET_BIT(RCC_CFGR,HPRE1);
	CLR_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_16
	SET_BIT(RCC_CFGR,HPRE0);
	SET_BIT(RCC_CFGR,HPRE1);
	CLR_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);

#elif AHB_PRESCALER == Divided_by_64
	CLR_BIT(RCC_CFGR,HPRE0);
	CLR_BIT(RCC_CFGR,HPRE1);
	SET_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_128
	SET_BIT(RCC_CFGR,HPRE0);
	CLR_BIT(RCC_CFGR,HPRE1);
	SET_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_256
	CLR_BIT(RCC_CFGR,HPRE0);
	SET_BIT(RCC_CFGR,HPRE1);
	SET_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#elif AHB_PRESCALER == Divided_by_512
	SET_BIT(RCC_CFGR,HPRE0);
	SET_BIT(RCC_CFGR,HPRE1);
	SET_BIT(RCC_CFGR,HPRE2);
	SET_BIT(RCC_CFGR,HPRE3);
#endif

	/**
	 * Setup APB1 Configuration
	 */
#if APB1_PRESCALER == Divided_by_2
	CLR_BIT(RCC_CFGR,PPRE1_0);
	CLR_BIT(RCC_CFGR,PPRE1_1);
	SET_BIT(RCC_CFGR,PPRE1_2);
#elif APB1_PRESCALER == Divided_by_4
	SET_BIT(RCC_CFGR,PPRE1_0);
	CLR_BIT(RCC_CFGR,PPRE1_1);
	SET_BIT(RCC_CFGR,PPRE1_2);
#elif APB1_PRESCALER == Divided_by_8
	CLR_BIT(RCC_CFGR,PPRE1_0);
	SET_BIT(RCC_CFGR,PPRE1_1);
	SET_BIT(RCC_CFGR,PPRE1_2);
#elif APB1_PRESCALER == Divided_by_16
	SET_BIT(RCC_CFGR,PPRE1_0);
	SET_BIT(RCC_CFGR,PPRE1_1);
	SET_BIT(RCC_CFGR,PPRE1_2);
#endif


	/**
	 * Setup APB2 Configuration
	 */
#if APB2_PRESCALER == Divided_by_2
	CLR_BIT(RCC_CFGR,PPRE2_0);
	CLR_BIT(RCC_CFGR,PPRE2_1);
	SET_BIT(RCC_CFGR,PPRE2_2);
#elif APB2_PRESCALER == Divided_by_4
	SET_BIT(RCC_CFGR,PPRE2_0);
	CLR_BIT(RCC_CFGR,PPRE2_1);
	SET_BIT(RCC_CFGR,PPRE2_2);
#elif APB2_PRESCALER == Divided_by_8
	CLR_BIT(RCC_CFGR,PPRE2_0);
	SET_BIT(RCC_CFGR,PPRE2_1);
	SET_BIT(RCC_CFGR,PPRE2_2);
#elif APB2_PRESCALER == Divided_by_16
	SET_BIT(RCC_CFGR,PPRE2_0);
	SET_BIT(RCC_CFGR,PPRE2_1);
	SET_BIT(RCC_CFGR,PPRE2_2);
#endif
#if RCC_SYS_CLK == RCC_HSI
	/*Choose HSI as a clock source*/
	CLR_BIT(RCC_CFGR,SW0);
	CLR_BIT(RCC_CFGR,SW1);


	/*Turn the HSI ON and looping till ready flag is raised*/
	SET_BIT(RCC_CR,HSI_ON);
	//while(GET_BIT(RCC_CR,HSI_RDY) == 0);


#elif RCC_SYS_CLK == RCC_HSE

	/*Init HSE*/
	/*Choose HSE as a clock source*/
	SET_BIT(RCC_CFGR,SW0);
	CLR_BIT(RCC_CFGR,SW1);

	/*Turn the HSE ON and looping till ready flag is raised*/
	SET_BIT(RCC_CR,HSE_ON);
	while(GET_BIT(RCC_CR,HSE_RDY) == 0);

#elif RCC_SYS_CLK == RCC_PLL

	/*Init PLL*/
	/*Choose PLL as a clock source*/
	SET_BIT(RCC_CFGR,SW0);
	SET_BIT(RCC_CFGR,SW1);

#if PLL_SOURCE == RCC_HSI

	SET_BIT(RCC_CFGR,PLL_SRC0);
	CLR_BIT(RCC_CFGR,PLL_SRC1);
#elif PLL_SOURCE == RCC_HSE
	CLR_BIT(RCC_CFGR,PLL_SRC0);
	SET_BIT(RCC_CFGR,PLL_SRC1);
#elif PLL_SOURCE == RCC_HSI/2
	CLR_BIT(RCC_CFGR,PLL_SRC0);
	CLR_BIT(RCC_CFGR,PLL_SRC1);
#endif

	RCC_CFGR &= PULL_MULTIPLAY_MASKING
	RCC_CFGR |= PLL_MULTIPLY


	/*Turn the HSE ON and looping till ready flag is raised*/
	SET_BIT(RCC_CR,PLL_ON);
	while(GET_BIT(RCC_CR,PLL_RDY) == 0);

#endif


}


void RCC_EnablePeripheralClk(uint8 Copy_u8BusID,uint8 Copy_u8PerID)
{
	switch(Copy_u8BusID)
	{
	case RCC_AHB :
		SET_BIT(RCC_AHBENR,Copy_u8PerID);
		break;
	case RCC_APB1:
		SET_BIT(RCC_APB1ENR,Copy_u8PerID);
		break;
	case RCC_APB2:
		SET_BIT(RCC_APB2ENR,Copy_u8PerID);
		break;
	}
}

void RCC_DisablePeripheralClk(uint8 Copy_u8BusID,uint8 Copy_u8PerID)
{
	switch(Copy_u8BusID)
	{
	case RCC_AHB :
		CLR_BIT(RCC_AHBENR,Copy_u8PerID);
		break;
	case RCC_APB1:
		CLR_BIT(RCC_APB1ENR,Copy_u8PerID);
		break;
	case RCC_APB2:
		CLR_BIT(RCC_APB2ENR,Copy_u8PerID);
		break;
	}
}
