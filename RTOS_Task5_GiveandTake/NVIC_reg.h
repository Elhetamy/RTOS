/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file NVIC_reg.h
 */

#ifndef NVIC_REG_H_
#define NVIC_REG_H_


#define NVIC_BaseAddress		(0xE000E100)
#define SCB_BaseAddress			(0xE000ED00)

#define NVIC_ISER0				*((volatile uint32 *)(NVIC_BaseAddress +0x100))
#define NVIC_ISER1				*((volatile uint32 *)(NVIC_BaseAddress +0x104))
#define NVIC_ISER2				*((volatile uint32 *)(NVIC_BaseAddress +0x108))

#define NVIC_ICER0				*((volatile uint32 *)(NVIC_BaseAddress +0x180))
#define NVIC_ICER1				*((volatile uint32 *)(NVIC_BaseAddress +0x184))
#define NVIC_ICER2				*((volatile uint32 *)(NVIC_BaseAddress +0x188))

#define NVIC_ISPR0				*((volatile uint32 *)(NVIC_BaseAddress +0x200))
#define NVIC_ISPR1				*((volatile uint32 *)(NVIC_BaseAddress +0x204))
#define NVIC_ISPR2				*((volatile uint32 *)(NVIC_BaseAddress +0x208))

#define NVIC_ICPR0				*((volatile uint32 *)(NVIC_BaseAddress +0x280))
#define NVIC_ICPR1				*((volatile uint32 *)(NVIC_BaseAddress +0x284))

#define NVIC_IABR0				*((volatile uint32 *)(NVIC_BaseAddress +0x300))
#define NVIC_IABR1				*((volatile uint32 *)(NVIC_BaseAddress +0x304))

#define NVIC_IPR				((volatile uint8 *)(NVIC_BaseAddress + 0x400))



#endif /* NVIC_REG_H_ */
