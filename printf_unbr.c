/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:21:26 by mokon             #+#    #+#             */
/*   Updated: 2025/02/24 15:58:02 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
