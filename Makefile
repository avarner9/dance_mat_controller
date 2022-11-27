C_OBJECTS=start.o main.o clock.o i2c.o uart.o newlib_helpers.o uart_dma.o
AS_OBJECTS=

CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -Wall -Wextra --std=gnu99 -nostartfiles
LD=arm-none-eabi-ld
LDFLAGS=-T stm32f405.ld -nostartfiles
AS=arm-none-eabi-as
ASFLAGS=-mthumb




ddrcontroller.bin : ddrcontroller.hex
	arm-none-eabi-objcopy -I ihex ddrcontroller.hex --only-section='*' -O binary ddrcontroller.bin

install : ddrcontroller.bin
	dfu-util -d 0483:df11 -a 0 -s 0x08000000 -S 207F366D5753 -D ./ddrcontroller.bin

ddrcontroller.hex : ddrcontroller.elf
	arm-none-eabi-objcopy ddrcontroller.elf -O ihex ddrcontroller.hex

ddrcontroller.elf : $(C_OBJECTS) $(AS_OBJECTS)
#	$(LD) $(LDFLAGS) $(C_OBJECTS) $(AS_OBJECTS) -o ddrcontroller.elf
	$(CC) $(CFLAGS) $(LDFLAGS) $(C_OBJECTS) $(AS_OBJECTS) -o ddrcontroller.elf




clean :
	@touch dummy.o dummy.elf dummy.hex dummy.bin
	rm *.o *.elf *.hex *.bin

install-clean :
	dfu-util -d 0483:df11 -a 0 -S 207F366D5753 -D /dev/null

