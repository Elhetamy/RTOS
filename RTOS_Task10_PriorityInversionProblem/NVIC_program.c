/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file NVIC_program.c
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "NVIC_reg.h"
#include "NVIC_prv.h"
#include "NVIC_cfg.h"
#include "NVIC_interface.h"

//static void (*Global_pvNVICNotification[84])(void) = NULL;
static void (*Global_pvNVICNotification)(void) = NULL;

void NVIC_voidInit(void)
{
#ifndef	SCB_AIRCR
#define SCB_AIRCR				*((volatile uint32 *)(SCB_BaseAddress +0x0C))
#endif

	SCB_AIRCR = NUM_OF_GRP_SUB;
}


void NVIC_voidPerInterruptEnable(uint8 PerId)
{
	if(PerId < 32)
	{
		NVIC_ISER0 = (1<<PerId);
	}
	else if(PerId < 64)
	{
		PerId -= 32;
		NVIC_ISER1 = (1<<PerId);
	}
	else if(PerId > 96)
	{
		PerId -= 64;
		NVIC_ISER2 = (1<<PerId);
	}
}


void NVIC_voidPerInterruptDisable(uint8 PerId)
{
	if(PerId < 32)
	{
		NVIC_ICER0 = (1<<PerId);
	}
	else if(PerId < 64)
	{
		PerId -= 32;
		NVIC_ICER1 = (1<<PerId);
	}
	else if(PerId > 96)
	{
		PerId -= 64;
		NVIC_ICER2 = (1<<PerId);
	}
}

void NVIC_voidSetPindingFlag(uint8 PerId)
{
	if(PerId < 32)
	{
		NVIC_ISPR0=(1<<PerId);
	}
	else if(PerId < 64)
	{
		PerId -= 32;
		NVIC_ISPR1=(1<<PerId);
	}
}

void NVIC_voidClearPindingFlag(uint8 PerId)
{
	if(PerId < 32)
	{
		NVIC_ICPR0 = (1<<PerId);
	}
	else if(PerId < 64)
	{
		PerId -= 32;
		NVIC_ICPR1=(1<<PerId);
	}
}

uint8 NVIC_u8GetActiveFlag(uint8 PerId)
{
	uint8 Local_u8FlagResult = 0xAA;
	if(PerId < 32)
	{
		Local_u8FlagResult = GET_BIT(NVIC_IABR0,PerId);
	}
	else if(PerId < 64)
	{
		PerId -= 32;
		Local_u8FlagResult = GET_BIT(NVIC_IABR1,PerId);
	}

	return Local_u8FlagResult;
}


void NVIC_voidSetPriority(uint8 PerID,uint8 PriorityNum)
{
	NVIC_IPR[PerID] = (PriorityNum << 4);
}


void NVIC_voidSetCallBackFunc(void (*Copy_pvFunc)(void))
{
	Global_pvNVICNotification = Copy_pvFunc;
}





