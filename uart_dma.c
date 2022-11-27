#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "stm32f405.h"
#include "uart_dma.h"
#include "uart.h"


#define DMA_BUFFER_SIZE (500)


struct dma_buffer;
struct dma_buffer
{
    size_t used;
    char buffer[DMA_BUFFER_SIZE];
    struct dma_buffer * next;
};


static struct dma_buffer buf1;
static struct dma_buffer buf2;
static struct dma_buffer * buf_i = NULL;
static struct dma_buffer * buf_o = NULL;
static bool overflowed = false;


static void dma_uart_queue_data(const void * d, size_t n);
static void dma_uart_transmit(const void * d, size_t n);
static bool dma_is_complete(void);


void initialize_dma_uart(void)
{
    buf1.used = 0;
    buf2.used = 0;
    buf1.next = &buf2;
    buf2.next = &buf1;
    memset(buf1.buffer, DMA_BUFFER_SIZE, '7');
    memset(buf2.buffer, DMA_BUFFER_SIZE, '7');
    buf_i = &buf1;
    initialize_uart();

    print_str("===============================================================================\n");
    print_str("UART initialized\n");
    print_str("ddrcontroller v0.0\n");
}

void process_dma_uart(void)
{
    if (buf_o != NULL)
    {
        if (dma_is_complete())
        {
            buf_o->used = 0;
            buf_o = NULL;
        }
    }
    if (buf_o == NULL)
    {
        if (buf_i->used > 0)
        {
            buf_o = buf_i;
            dma_uart_transmit(buf_o->buffer, buf_o->used);
            buf_i = buf_i->next;
            buf_i->used = 0;
        }
        if (overflowed)
        {
            overflowed = false;
            print_str("UART DMA buffer overflow -- some data lost\n");
        }
    }
}

void dma_uart_flush(void)
{
    process_dma_uart();
    while (buf_o != NULL)
        process_dma_uart();
}
bool dma_uart_try_flush(void)
{
    process_dma_uart();
    return buf_o == NULL;
}

static void dma_uart_queue_data(const void * d, size_t n)
{
    if (overflowed)
    {
        process_dma_uart();
        if (overflowed)
            return;
    }
    size_t max_copy_size = DMA_BUFFER_SIZE - buf_i->used;
    size_t copy_size = n;
    if (copy_size > max_copy_size)
    {
        copy_size = max_copy_size;
        overflowed = true;
    }
    memcpy(buf_i->buffer + buf_i->used, d, copy_size);
    buf_i->used += copy_size;
    process_dma_uart();
}

static void dma_uart_transmit(const void * d, size_t n)
{
    if (n <= 0)
        return;

    //enable DMA power up
    RCC_AHB1ENR |= 0x00400000;

    //disable DMA
    DMA2_S7CR &= 0xFFFFFFFE;
    //DMA2, stream 7, channel 5, configure as USART6_TX
    DMA2_S7CR = 0x0A000440;
    //enable Peripheral Flow Control:
    //DMA2_S7CR |= 0x00000010;
    //enable transmission complete interrupt:
    //DMA2_S7CR |= 0x00000020;

    //set dst pointer
    DMA2_S7PAR = (uint32_t)&USART6_DR;
    //set src pointer
    DMA2_S7M0AR = (uint32_t)d;
    DMA2_S7NDTR = n;

    //enable DMA TX
    USART6_CR3 |= 0x00000080;

    //enable DMA
    DMA2_S7CR |= 0x00000001;
}

static bool dma_is_complete(void)
{
    bool retval = ((DMA2_HISR & 0x08000000) != 0);

    //clear transfer complete flag
    DMA2_HIFCR |= 0x08000000;

    return retval;
}



void print_char(const char c)
{
    dma_uart_queue_data(&c, 1);
}

void print_str(const char * str)
{
    size_t length = 0;
    for (; str[length] != 0; length++)
        ;
    dma_uart_queue_data(str, length);
}

void print_hex_register(uint32_t a)
{
    static const char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (uint8_t i = 0; i < 8; i++)
    {
        print_char(hex_chars[(a >> ((7 - i) * 4)) & 0xF]);
    }
}


