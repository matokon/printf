#include "ft_printf.h"

int printf_char(int c)
{
	ft_putchar_fd(c, 1);
	return 1;
}