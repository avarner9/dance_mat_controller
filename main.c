#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#include "stm32f405.h"

#include "clock.h"
#include "uart_dma.h"
#include "i2c.h"


/*
void blink_indicate(size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        set_led_g(true);
        delay();
        set_led_g(false);
        delay();
    }
}
*/


int main(void)
{
    initialize_clock();
    initialize_dma_uart();

    RCC_AHB1ENR |= 0x00000004;
    GPIOC_MODER |= 0x00000050;
    GPIOC_ODR |= 0x0000000C;


    GPIOC_MODER |= 0x00000004;
    GPIOC_ODR = 0x00000002;

    initialize_i2c();

    GPIOC_ODR = 0x00000000;


    uint32_t t_next_led = get_time_us();
    bool led_on = false;

    while (true)
    {
        process_dma_uart();
        if (((int32_t)(get_time_us() - t_next_led)) >= 0)
        {
            led_on = !led_on;
            t_next_led += 500000;
            if (led_on)
            {
                GPIOC_ODR = 0x00000002;
                i2c_write(0xA6, 0x04);
            }
            else
            {
                GPIOC_ODR = 0x00000000;
                i2c_write(0xA6, 0x00);
            }
        }
    }
}








void * memset(void * ptr1, int c, size_t length)
{
    uint8_t * ptr2 = ptr1;
    for (size_t i = 0; i < length; i++)
        ptr2[i] = c;
    return ptr1;
}

void * memcpy(void * dst, const void * src, size_t length)
{
    uint8_t * dst2 = dst;
    const uint8_t * src2 = src;
    for (size_t i = 0; i < length; i++)
        dst2[i] = src2[i];
    return dst;
}


