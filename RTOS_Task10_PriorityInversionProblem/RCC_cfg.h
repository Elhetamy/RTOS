/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file RCC_cfg.h
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

#define RCC_SYS_CLK		RCC_HSI				//Options 1-RCC_HSI		2-RCC_HSE		3-RCC_PLL
#define RCC_CSS			CSS_ENABLED			//Options 1-CSS_ON		2-CSS_OFF

#define PLL_SOURCE		RCC_HSI				//Options 1-RCC_HSI		2-RCC_HSE		3-RCC_HSI/2

#define PLL_MULTIPLY	Mul_by2

#define AHB_PRESCALER	Divided_by_2		//Options 1-Divided_by_2 2-Divided_by_4 3-Divided_by_8 4-Divided_by_16 5-Divided_by_64 6-Divided_by_128 7-Divided_by_256 8-Divided_by_512

#define APB1_PRESCALER	Divided_by_2		//Options 1-Divided_by_2 2-Divided_by_4 3-Divided_by_8 4-Divided_by_16

#define APB2_PRESCALER	Divided_by_2		//Options 1-Divided_by_2 2-Divided_by_4 3-Divided_by_8 4-Divided_by_16

#endif
