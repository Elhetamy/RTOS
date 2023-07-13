/*
 * GPIO_reg.h
 *
 *  Created on: Jun 24, 2023
 *      Author: user
 */

#ifndef GPIO_REG_H_
#define GPIO_REG_H_

/***********GPIO ADDRESSES*************/
/**********GPIOA************/
#define GPIOA_BASE_ADD		((uint32)0x48000000)

#define GPIOA_MODER		*((volatile uint32*)(0x00+GPIOA_BASE_ADD))
#define GPIOA_OTYPER    *((volatile uint32*)(0x04+GPIOA_BASE_ADD))
#define GPIOA_OSPEEDR   *((volatile uint32*)(0x08+GPIOA_BASE_ADD))
#define GPIOA_PUPDR	    *((volatile uint32*)(0x0C+GPIOA_BASE_ADD))
#define GPIOA_IDR		*((volatile uint32*)(0x10+GPIOA_BASE_ADD))
#define GPIOA_ODR		*((volatile uint32*)(0x14+GPIOA_BASE_ADD))
#define GPIOA_BSRR		*((volatile uint32*)(GPIOA_BASE_ADD+0x18))
#define GPIOA_AFRL 		*((volatile uint32*)(GPIOA_BASE_ADD+0x20))
#define GPIOA_AFRH		*((volatile uint32*)(GPIOA_BASE_ADD+0x24))

/**********************/
/**********GPIOB************/
#define GPIOB_BASE			((uint32)0x48000400)


#define GPIOB_MODER			*((volatile uint32*)(GPIOB_BASE+0x00))
#define GPIOB_OTYPER		*((volatile uint32*)(GPIOB_BASE+0x04))
#define GPIOB_OSPEEDR		*((volatile uint32*)(GPIOB_BASE+0x08))
#define GPIOB_PUPDR			*((volatile uint32*)(GPIOB_BASE+0x0c))
#define GPIOB_IDR			*((volatile uint32*)(GPIOB_BASE+0x10))
#define GPIOB_ODR			*((volatile uint32*)(GPIOB_BASE+0x14))
#define GPIOB_BSRR			*((volatile uint32*)(GPIOB_BASE+0x18))
#define GPIOB_AFRL 			*((volatile uint32*)(GPIOB_BASE+0x20))
#define GPIOB_AFRH 			*((volatile uint32*)(GPIOB_BASE+0x24))

/**********************/
/**********GPIOC************/
#define GPIOC_BASE			((uint32)0x48000800)

#define GPIOC_MODER			*((volatile uint32*)(GPIOC_BASE+0x00))
#define GPIOC_OTYPER		*((volatile uint32*)(GPIOC_BASE+0x04))
#define GPIOC_OSPEEDR		*((volatile uint32*)(GPIOC_BASE+0x08))
#define GPIOC_PUPDR			*((volatile uint32*)(GPIOC_BASE+0x0c))
#define GPIOC_IDR			*((volatile uint32*)(GPIOC_BASE+0x10))
#define GPIOC_ODR			*((volatile uint32*)(GPIOC_BASE+0x14))
#define GPIOC_BSRR			*((volatile uint32*)(GPIOC_BASE+0x18))
#define GPIOC_AFRL 			*((volatile uint32*)(GPIOC_BASE+0x20))
#define GPIOC_AFRH 			*((volatile uint32*)(GPIOC_BASE+0x24))

/**********************/
/**********GPIOD************/
#define GPIOD_BASE			((uint32)0x48000C00)

#define GPIOD_MODER			*((volatile uint32*)(GPIOD_BASE+0x00))
#define GPIOD_OTYPER		*((volatile uint32*)(GPIOD_BASE+0x04))
#define GPIOD_OSPEEDR		*((volatile uint32*)(GPIOD_BASE+0x08))
#define GPIOD_PUPDR			*((volatile uint32*)(GPIOD_BASE+0x0c))
#define GPIOD_IDR			*((volatile uint32*)(GPIOD_BASE+0x10))
#define GPIOD_ODR			*((volatile uint32*)(GPIOD_BASE+0x14))
#define GPIOD_BSRR			*((volatile uint32*)(GPIOD_BASE+0x18))
#define GPIOD_AFRL 			*((volatile uint32*)(GPIOD_BASE+0x20))
#define GPIOD_AFRH 			*((volatile uint32*)(GPIOD_BASE+0x24))

/**********************/
/***********************************/

#endif /* GPIO_REG_H_ */
