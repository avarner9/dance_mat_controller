#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#include "stm32f405.h"

#include "clock.h"
#include "uart.h"
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
    //initialize_uart();

    RCC_AHB1ENR |= 0x00000004;
    GPIOC_MODER |= 0x00000050;
    GPIOC_ODR |= 0x0000000C;


    GPIOC_MODER |= 0x00000004;
    GPIOC_ODR = 0x00000002;

    initialize_i2c();

    GPIOC_ODR = 0x00000000;

    while (true)
    {
        GPIOC_ODR = 0x00000002;
        delay1s();
        GPIOC_ODR = 0x00000000;
        delay1s();
        //GPIOC_ODR |= 0x00000008;
        //GPIOC_ODR |= 0x00000004;
        
        /*
        process_ir_input();
        if (get_time_from_last_capture() > 400000)
        {
            set_led_g(true);
            finish_message();
            if (get_overrun())
            {
                set_led_y(true);
            }

            struct nec_message m;
            decode_nec_message(&m);
            
            print_msg("msg: ", m.type, "");
            print_msg(", ", m.address, "");
            print_msg(", ", m.command, "\n");
            if (m.num_errors > 0)
                print_msg("(errors: ", m.num_errors, ")\n");
            
            bitbang2((uint8_t *)&m, sizeof(m));

            set_led_g(false);
        }*/
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


