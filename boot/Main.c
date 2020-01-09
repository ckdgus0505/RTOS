#include "stdint.h"
#include "HalUart.h"
#include "stdio.h"

static void Hw_init(void);
static void Print_test(void);
void main(void)
{
	Hw_init();

	putstr("Hello World\n");
	uint32_t i = 100;

	Print_test();
	while(i--)
	{
		uint8_t ch = Hal_uart_get_char();
		Hal_uart_put_char(ch);
	}
}

static void Hw_init(void)
{
	Hal_uart_init();
}

static void Print_test(void)
{
	char* str = "printf pointer test";
	char* nullptr = 0;
	uint32_t i = 5;

	debug_printf("%s\n", "Hello printf");
	debug_printf("output string pointer: %s\n", str);
	debug_printf("%s is null pointer, %u number\n", nullptr, 10);
	debug_printf("%u = 5\n", i);
	debug_printf("dec=%u hex=%x%x\n", 1234567890, 0x12345678, 0x90ABCDEF);
	debug_printf("printf zero %u\n", 0);
}

