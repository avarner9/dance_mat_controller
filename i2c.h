#include <stdint.h>
#include <stdbool.h>


void initialize_i2c(void);

bool i2c_write(uint8_t addr, uint8_t reg_addr, uint8_t data);
bool i2c_read(uint8_t addr, uint8_t * data);

