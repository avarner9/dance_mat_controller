#include "i2c.h"
#include "stm32f405.h"
#include "clock.h"


void initialize_i2c(void)
{
    //Enable GPIOB
    RCC_AHB1ENR |= 0x00000002;
    //Enable I2C 1 and 2
    RCC_APB1ENR |= 0x00600000;

    //PB6, PB7 as AF
    GPIOB_MODER |= 0x0000A000;
    //PB6 AF as AF4 (I2C1_SCL)
    GPIOB_AFRL |= 0x04000000;
    //PB7 AF as AF4 (I2C1_SDA)
    GPIOB_AFRL |= 0x40000000;
    //PB6 and PB7 as open-drain outputs
    GPIOB_OTYPER |= 0x000000C0;
    //PB6 and PB7 enable pull up resistors
    GPIOB_PUPDR |= 0x00005000;
    //PB6 and PB7 set output speed to medium
    GPIOB_OSPEEDR |= 0x00005000;

    //PB10, PB11 as AF
    GPIOB_MODER |= 0x00A00000;
    //PB10 AF as AF4 (I2C2_SCL)
    GPIOB_AFRH |= 0x00000400;
    //PB11 AF as AF4 (I2C2_SDA)
    GPIOB_AFRH |= 0x00004000;
    //PB10 and PB11 as open-drain outputs
    GPIOB_OTYPER |= 0x00000C00;
    //PB10 and PB11 enable pull up resistors
    GPIOB_PUPDR |= 0x00500000;
    //PB10 and PB11 set output speed to medium
    GPIOB_OSPEEDR |= 0x00500000;

    delay1s();
    //Clock rate: 9MHz (APB1 -- see clock.c)
    I2C1_CR2 = 0x00000009;
    //Enable Fm. Set frequency to 375kHz
    I2C1_CCR = 0x00008008;
    //TRISE = ciel(300ns/111.111ns)+1. 300ns is from the I2C Fm standard.
    I2C1_TRISE = 4;
    //enable the peripheral
    I2C1_CR1 |= 0x00000001;

    //Do a Start
    I2C1_CR1 |= 0x00000100;
    //wait for start condition to complete
    while ((I2C1_SR1 & 0x00000001) == 0)
        ;
/*
    //send slave address
    I2C1_DR = 0x55; //transmit mode
    //wait for slave address to finish transmitting
    while ((I2C1_SR1 & 0x00000002) == 0)
        ;

    //TODO: check for acknowledge error, using ((I2C1_SR & 0x00000400) != 0)

    //send data byte
    I2C1_DR = 0xAA;
    //wait for data to finish transmitting
    while ((I2C1_SR1 & 0x00000080) == 0)
        ;

    //send stop bit
    I2C1_CR1 |= 0x00000200;
    //wait for stop bit to finish transmitting
    while ((I2C1_SR2 & 0x00000001) != 0)
        ;
*/

/*

TODO: read from page 849 starting at "Master Receiver"

*/



    I2C2_SR1;
    I2C2_SR2;
}
