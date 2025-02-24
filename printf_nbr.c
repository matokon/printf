#include "ft_printf.h"

int	printf_nbr(int number)
{
	int	digit_counter;

	digit_counter = 0;
	if (number == INT_MIN)
		return (printf_string("-2147483648"));
	else if (number < 0)
	{
		digit_counter += printf_char('-');
		number *= -1;
	}
	if (number > 9)
		digit_counter += printf_nbr(number / 10);
	digit_counter += printf_char((number % 10) + 48);
	return (digit_counter);
}
