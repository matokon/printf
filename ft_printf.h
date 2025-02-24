/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokon <mokon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:18:35 by mokon             #+#    #+#             */
/*   Updated: 2025/02/24 15:57:49 by mokon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	printf_char(int c);
int	printf_string(char *s);
int	printf_ptr(void *ptr);
int	ft_printf(const char *s, ...);
int	printf_nbr(int n);
int	printf_hex(unsigned int n, int xswitch);
int	printf_unbr(unsigned int n);

#endif
