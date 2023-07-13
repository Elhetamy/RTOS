/**
 * @author Abdelrahman Elhetamy
 * @date 24	Jun 2023
 * @file RCC_interface.h
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef enum
{
	HSI_ON=0,
	HSI_RDY,
	HSI_TRIM0=3,
	HSI_TRIM1,
	HSI_TRIM2,
	HSI_TRIM3,
	HSI_TRIM4,
	HSI_CAL0,
	HSI_CAL1,
	HSI_CAL2,
	HSI_CAL3,
	HSI_CAL4,
	HSI_CAL5,
	HSI_CAL6,
	HSI_CAL7,
	HSE_ON,
	HSE_RDY,
	HSE_BYP,
	CSS_ON,
	PLL_ON=24,
	PLL_RDY
}CR_BITS;


typedef enum
{
	SW0=0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE1_0,
	PPRE1_1,
	PPRE1_2,
	PPRE2_0,
	PPRE2_1,
	PPRE2_2,
	PLL_SRC0=15,
	PLL_SRC1,
	PLL_XTPRE,
	PLLMUL_0,
	PLLMUL_1,
	PLLMUL_2,
	PLLMUL_3,
	USB_PRE,
	I2SSRC,
	MCO_0,
	MCO_1,
	MCO_2,
	MCOPRE_0=28,
	MCOPRE_1,
	MCOPRE_2,
	PLL_NODIV
}CFGR_BITS;

typedef enum
{
	LSI_RDYF=0,
	LSE_RDYF,
	HSI_RDYF,
	HSE_RDYF,
	PLL_RDYF,
	CSSF=7,
	LSI_RDYIE,
	LSE_RDYIE,
	HSI_RDYIE,
	HSE_RDYIE,
	PLL_RDYIE,
	LSI_RDYC=16,
	LSE_RDYC,
	HSI_RDYC,
	HSE_RDYC,
	PLL_RDYC,
	CSSC=23
}CIR_BITS;

typedef enum
{
	SYS_CFGRST=0,
	TIM1_RST=11,
	SPI1_RST,
	TIM8_RST,
	USART1_RST,
	SPI4_RST,
	TIM15_RST,
	TIM16_RST,
	TIM17_RST,
	TIM20_RST=20
}APB2RSTR_BITS;

typedef enum
{
	TIM2_RST=0,
	TIM3_RST,
	TIM6_RST=4,
	TIM7_RST,
	WWDG_RST=11,
	SPI2_RST=14,
	SPI3_RST,
	USART2_RST=17,
	USART3_RST,
	UART4_RST,
	UART5_RST,
	I2C1_RST,
	I2C2_RST,
	USB_RST,
	CAN_RST=25,
	PWR_RST=28,
	DAC1_RST,
	I2C3_RST
}APB1RSTR_BITS;

typedef enum
{
	DMA1_EN=0,
	DMA2_EN,
	SRAM_EN,
	FLITF_EN=4,
	CRCE_EN=6,
	IOPH_EN=16,
	IOPA_EN,
	IOPB_EN,
	IOPC_EN,
	IOPD_EN,
	IOPE_EN,
	IOPF_EN,
	IOPG_EN,
	TSC_EN,
	ADC12_EN=28
}AHBENR_BITS;
/*
typedef enum
{
	AFIO_EN=0,
	IOPA_EN=2,
	IOPB_EN,
	IOPC_EN,
	IOPD_EN,
	IOPE_EN,
	IOPF_EN,
	IOPG_EN,
	ADC1_EN,
	ADC2_EN,
	TIM1_EN,
	SPI1_EN,
	TIM8_EN,
	USART1_EN,
	ADC3_EN,
	TIM9_EN=19,
	TIM10_EN,
	TIM11_EN
}APB2ENR_BITS;

 */
typedef enum
{
	SYSCFG_EN=0,
	TIM1_EN=11,
	SPI1_EN,
	TIM8_EN
}APB1ENR_BITS;


typedef enum
{
	LSI_ON=0,
	LSI_RDY,
	RMVF=24,
	PIN_RSTF=26,
	POR_RSTF,
	SFT_RSTF,
	IWDG_RSTF,
	WWDG_RSTF,
	LPWR_RSTF
}CSR_BITS;

/********************* PRESCALERS	*********************/

#define Divided_by_2		0u
#define Divided_by_4		1u
#define Divided_by_8		2u
#define Divided_by_16		3u
#define Divided_by_64		4u
#define Divided_by_128		5u
#define Divided_by_256		6u
#define Divided_by_512		7u

/********************* PLL_MUL		*********************/

#define		Mul_by2			0u
#define     Mul_by3         1u
#define     Mul_by4         2u
#define     Mul_by5         3u
#define     Mul_by6         4u
#define     Mul_by7         5u
#define     Mul_by8         6u
#define     Mul_by9         7u
#define     Mul_by10		8u
#define     Mul_by11		9u
#define     Mul_by12		10u
#define     Mul_by13		11u
#define     Mul_by14		12u
#define     Mul_by15		13u
#define     Mul_by16		14u


/********************* 		BUSES	*********************/

#define		RCC_AHB			0u
#define     RCC_APB1		1u
#define     RCC_APB2		2u


/********************* CLK_SOURCES 	*********************/

#define		RCC_HSI		0u
#define     RCC_HSE		1u
#define     RCC_PLL		2u

/*********************PLL_CLK_SOURCES*********************/


#define		RCC_HSI_PLL  		0u
#define     RCC_HSE_PLL  		1u
#define     RCC_HSI_DIV_2 		2u


void RCC_voidSysClkInt(void);
void RCC_EnablePeripheralClk(uint8 Copy_u8BusID,uint8 Copy_u8PerID);
void RCC_DisablePeripheralClk(uint8 Copy_u8BusID,uint8 Copy_u8PerID);
#endif
