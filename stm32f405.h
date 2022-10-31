#include <stdint.h>


//incomplete
#define RCC_CR        (*(volatile uint32_t *)0x40023800)
#define RCC_PLLCFGR   (*(volatile uint32_t *)0x40023804)
#define RCC_CFGR      (*(volatile uint32_t *)0x40023808)
#define RCC_AHB1ENR   (*(volatile uint32_t *)0x40023830)
#define RCC_APB1ENR   (*(volatile uint32_t *)0x40023840)

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

