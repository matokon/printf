#include "ft_printf.h"

int	printf_unbr(unsigned int n)
{
	int	digit_counter;

	digit_counter = 0;
	if (n > 9)
		digit_counter += printf_unbr((n / 10));
	digit_counter += printf_char((n % 10) + 48);
	return (digit_counter);
}
