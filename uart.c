#include <stdbool.h>

#include "uart.h"
#include "stm32f405.h"


void initialize_uart(void)
{
    //enable GPIOC
    RCC_AHB1ENR |= 0x00000004;
    //set PC6 and PC7 as AF
    GPIOC_MODER |= 0x0000A000;
    //set PC6 and PC7 as AF8 (UART6 TX and RX respectively)
    GPIOC_AFRL |= 0x88000000;

    //enable UART6
    RCC_APB2ENR |= 0x00000020;
    //set baud rate to 115200 (9MHz/16/115200=5)
    USART6_BRR = (5 << 4);
    //enable UART
    USART6_CR1 = 0x0000200C;
}


/*
void print_char(const char c)
{
    while ((USART6_SR & 0x0080) == 0)
        ;
    USART6_DR = c;
}

void print_str(const char * str)
{
    for (; str[0] != 0; str++)
    {
        print_char(str[0]);
    }
}

void print_hex_register(uint32_t a)
{
    static const char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (uint8_t i = 0; i < 8; i++)
    {
        print_char(hex_chars[(a >> ((7 - i) * 4)) & 0xF]);
    }
}
*/

