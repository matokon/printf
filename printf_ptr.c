/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:21:07 by mokon             #+#    #+#             */
/*   Updated: 2025/02/24 18:12:33 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = size_hex_address(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_address(n / 16);
		ft_hex_address(n % 16);
	}
	return (size);
}

int	printf_ptr(void *ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (printf_string("0x") == -1)
		return (-1);
	n = ft_hex_address((unsigned long long)ptr);
	if (n != 0)
		return (n + 2);
	else
		return (3);
}
