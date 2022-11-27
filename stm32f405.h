#include <stdint.h>


//incomplete
#define RCC_CR        (*(volatile uint32_t *)0x40023800)
#define RCC_PLLCFGR   (*(volatile uint32_t *)0x40023804)
#define RCC_CFGR      (*(volatile uint32_t *)0x40023808)
#define RCC_AHB1ENR   (*(volatile uint32_t *)0x40023830)
#define RCC_APB1ENR   (*(volatile uint32_t *)0x40023840)
#define RCC_APB2ENR   (*(volatile uint32_t *)0x40023844)

//incomplete
#define GPIOB_MODER   (*(volatile uint32_t *)0x40020400)
#define GPIOB_OTYPER  (*(volatile uint32_t *)0x40020404)
#define GPIOB_OSPEEDR (*(volatile uint32_t *)0x40020408)
#define GPIOB_PUPDR   (*(volatile uint32_t *)0x4002040C)
#define GPIOB_AFRL    (*(volatile uint32_t *)0x40020420)
#define GPIOB_AFRH    (*(volatile uint32_t *)0x40020424)

//incomplete
#define GPIOC_MODER   (*(volatile uint32_t *)0x40020800)
#define GPIOC_ODR     (*(volatile uint32_t *)0x40020814)
#define GPIOC_AFRL    (*(volatile uint32_t *)0x40020820)

//incomplete
#define TIM2_CR1      (*(volatile uint32_t *)0x40000000)
#define TIM2_EGR      (*(volatile uint32_t *)0x40000014)
#define TIM2_CNT      (*(volatile uint32_t *)0x40000024)
#define TIM2_PSC      (*(volatile uint32_t *)0x40000028)

//complete
#define I2C1_CR1      (*(volatile uint32_t *)0x40005400)
#define I2C1_CR2      (*(volatile uint32_t *)0x40005404)
#define I2C1_OAR1     (*(volatile uint32_t *)0x40005408)
#define I2C1_OAR2     (*(volatile uint32_t *)0x4000540C)
#define I2C1_DR       (*(volatile uint32_t *)0x40005410)
#define I2C1_SR1      (*(volatile uint32_t *)0x40005414)
#define I2C1_SR2      (*(volatile uint32_t *)0x40005418)
#define I2C1_CCR      (*(volatile uint32_t *)0x4000541C)
#define I2C1_TRISE    (*(volatile uint32_t *)0x40005420)
#define I2C1_FLTR     (*(volatile uint32_t *)0x40005424)

//complete
#define I2C2_CR1      (*(volatile uint32_t *)0x40005800)
#define I2C2_CR2      (*(volatile uint32_t *)0x40005804)
#define I2C2_OAR1     (*(volatile uint32_t *)0x40005808)
#define I2C2_OAR2     (*(volatile uint32_t *)0x4000580C)
#define I2C2_DR       (*(volatile uint32_t *)0x40005810)
#define I2C2_SR1      (*(volatile uint32_t *)0x40005814)
#define I2C2_SR2      (*(volatile uint32_t *)0x40005818)
#define I2C2_CCR      (*(volatile uint32_t *)0x4000581C)
#define I2C2_TRISE    (*(volatile uint32_t *)0x40005820)
#define I2C2_FLTR     (*(volatile uint32_t *)0x40005824)

//incomplete
#define FLASH_ACR     (*(volatile uint32_t *)0x40023C00)


//complete
#define USART6_SR       (*(volatile uint32_t *)0x40011400)
#define USART6_DR       (*(volatile uint32_t *)0x40011404)
#define USART6_BRR      (*(volatile uint32_t *)0x40011408)
#define USART6_CR1      (*(volatile uint32_t *)0x4001140C)
#define USART6_CR2      (*(volatile uint32_t *)0x40011410)
#define USART6_CR3      (*(volatile uint32_t *)0x40011414)
#define USART6_GTPR     (*(volatile uint32_t *)0x40011418)

//incomplete
#define DMA2_LISR       (*(volatile uint32_t *)0x40026400)
#define DMA2_HISR       (*(volatile uint32_t *)0x40026404)
#define DMA2_HIFCR      (*(volatile uint32_t *)0x4002640C)
#define DMA2_S7CR       (*(volatile uint32_t *)0x400264B8)
#define DMA2_S7NDTR     (*(volatile uint32_t *)0x400264BC)
#define DMA2_S7PAR      (*(volatile uint32_t *)0x400264C0)
#define DMA2_S7M0AR     (*(volatile uint32_t *)0x400264C4)

