#include <stdint.h>
#include <stdbool.h>

void initialize_dma_uart(void);
void process_dma_uart(void);

void dma_uart_flush(void);
bool dma_uart_try_flush(void);

void print_char(const char c);
void print_str(const char * str);
void print_hex_register(uint32_t a);
