/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:20:40 by mokon             #+#    #+#             */
/*   Updated: 2025/02/24 15:57:55 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int size_hex(unsigned int n)
{
	int size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int printf_hex(unsigned int n, int xswitch)
{
	char *base_16;
	int size;

	size = size_hex(n);
	if (xswitch == 0)
		base_16 = "0123456789ABCDEF";
	else
		base_16 = "0123456789abcdef";

	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, xswitch) == -1)
			return (-1);
		if (printf_hex(n % 16, xswitch) == -1)
			return (-1);
	}
	return (size);
}
