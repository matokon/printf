
#include "ft_printf.h"

static int input_processing(const char* input, unsigned int* i, va_list* args)
{
	unsigned int counter;
	counter = 0;
	if (input[*i] == 'c')
		counter += printf_char(va_arg(*args, int));
	else if (input[*i] == 's')
		counter += printf_string(va_arg(*args, char*))///
	else if (input[*i] == 'p')
		counter += printf_ptr(va_arg(*args, void*));///
	else if (input[*i] == 'd' || input[*i] == 'i')
		counter += printf_nbr(va_arg(*args, int));//
	else if (input[*i] == 'u')
		counter += printf_unbr(va_arg(*args, int));//

	else if(input[*i] == '%')
	{
		printf_char('%');
		return 1;
	}
	return counter
}



int	ft_printf(const char* input, ...)
{
	va_list args;
	unsigned int i;
	unsigned int total_length;
	i = 0;
	total_length = 0;

	va_start(args, input);
	
	while(input[i])
	{
	
		if (input[i] == "%")
		{
			i++;
			total_length += input_processing(input, &i, &args);
		}
		else
		{
			total_length += printf_char(input[i]);
		}
		i++;
	}
	va_end(args);
	return(total_length);

}