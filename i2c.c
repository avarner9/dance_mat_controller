#include "i2c.h"
#include "stm32f405.h"
#include "clock.h"

#include "uart_dma.h"


#define MAX_I2C_DURATION_US (10000)


static void send_start(void);
static void send_stop(void);


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

    //Clock rate: 9MHz (APB1 -- see clock.c)
    I2C1_CR2 = 0x0000009;
I2C1_CR2 = 0x00000012;
    //Enable Fm. Set frequency to 375kHz
//    I2C1_CCR = 0x00008008;
    //disable Fm, actually. The ATTINY402 sucks.
    I2C1_CCR = 0x00000008;
I2C1_CCR = 0x00000080;
    //TRISE = ciel(300ns/111.111ns)+1. 300ns is from the I2C Fm standard.
    I2C1_TRISE = 4;
I2C1_TRISE = 17;
    //enable the peripheral
    I2C1_CR1 |= 0x00000001;


print_str("i2c status 1\n");
print_str("I2C1_SR1=0x");
print_hex_register(I2C1_SR1);
print_str("\n");
print_str("I2C1_conf: ");
print_hex_register(I2C1_CR1);
print_str("\n");
print_str("I2C1_conf: ");
print_hex_register(I2C1_CR2);
print_str("\n");
print_str("I2C1_conf: ");
print_hex_register(I2C1_CCR);
print_str("\n");
print_str("I2C1_conf: ");
print_hex_register(I2C1_TRISE);
print_str("\n");
}

bool i2c_write(uint8_t addr, uint8_t data)
{
    uint32_t end_time = get_time_us() + MAX_I2C_DURATION_US;

    send_start();
    //send slave address
    I2C1_DR = (addr & 0xFE); //LSB indicates read/write mode. 0 is write, 1 is read.

    //wait for slave address to finish transmitting
    while ((I2C1_SR1 & 0x00000002) == 0)
    {
        if ((I2C1_SR1 & 0x00000400) != 0)
        {
            print_str("i2c: got NACK on address.\n");
            send_stop();
            return false;
        }
        if (((int32_t)(get_time_us() - end_time)) >= 0)
        {
            print_str("i2c: timeout on address.\n");
            send_stop();
            return false;
        }        
    }

    //The following read sequence is required to clear the ADDR bit in SR1. This must be completed before writing the data byte.
    I2C1_SR1;
    I2C1_SR2;

    //while loop start here, for multiple data
    {
        //send data byte
        I2C1_DR = data;

        //wait for data to finish transmitting
        while ((I2C1_SR1 & 0x00000080) == 0)
        {
            if ((I2C1_SR1 & 0x00000400) != 0)
            {
                print_str("i2c: got NACK on data.\n");
                send_stop();
                return false;
            }
            if (((int32_t)(get_time_us() - end_time)) >= 0)
            {
                print_str("i2c: timeout on data.\n");
                send_stop();
                return false;
            }     
        }
    }
    send_stop();
    //TODO: read from page 849 starting at "Master Receiver"
    return true;
}

static void send_start(void)
{
    //Do a Start
    I2C1_CR1 |= 0x00000100;
    //wait for start condition to complete
    while ((I2C1_SR1 & 0x00000001) == 0)
        ;
}

static void send_stop(void)
{
    //Do a stop
    I2C1_CR1 |= 0x00000200;
    //wait for stop bit to finish transmitting
    while ((I2C1_SR2 & 0x00000001) != 0)
        ;
}

