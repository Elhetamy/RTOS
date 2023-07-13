/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file RCC_reg.h
 */

#ifndef RCC_REG_H_
#define RCC_REG_H_

#define RCC_BaseAddress		(0x40021000)

#define RCC_CR			*((volatile uint32 *)(RCC_BaseAddress +0x00))
#define RCC_CFGR		*((volatile uint32 *)(RCC_BaseAddress +0x04))
#define RCC_CIR			*((volatile uint32 *)(RCC_BaseAddress +0x08))
#define RCC_APB2RSTR	*((volatile uint32 *)(RCC_BaseAddress +0x0C))
#define RCC_APB1RSTR	*((volatile uint32 *)(RCC_BaseAddress +0x10))
#define RCC_AHBENR		*((volatile uint32 *)(RCC_BaseAddress +0x14))
#define RCC_APB2ENR		*((volatile uint32 *)(RCC_BaseAddress +0x18))
#define RCC_APB1ENR		*((volatile uint32 *)(RCC_BaseAddress +0x1C))
#define RCC_BDCR		*((volatile uint32 *)(RCC_BaseAddress +0x20))
#define RCC_CSR			*((volatile uint32 *)(RCC_BaseAddress +0x04))
#define RCC_AHBRSTR		*((volatile uint32 *)(RCC_BaseAddress +0x28))
#define RCC_CFGR2		*((volatile uint32 *)(RCC_BaseAddress +0x2C))
#define RCC_CFGR3		*((volatile uint32 *)(RCC_BaseAddress +0x30))


#endif /* RCC_REG_H_ */
