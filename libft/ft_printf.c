/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:53:34 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/08 12:47:53 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char c, int *counter)
{
	if (c == 'c')
		ft_printf_ch(va_arg(args, int), counter);
	else if (c == 's')
		ft_printf_str(va_arg(args, char *), counter);
	else if (c == 'p')
		ft_printf_ptr(va_arg(args, void *), counter);
	else if (c == 'd' || c == 'i')
		ft_printf_putnbr(va_arg(args, int), counter);
	else if (c == 'u')
		ft_printf_unsigned(va_arg(args, unsigned int), counter);
	else if (c == 'x' || c == 'X')
		ft_printf_hex(va_arg(args, unsigned int), c, counter);
	else if (c == '%')
		ft_printf_ch('%', counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_format(args, str[i + 1], &counter);
			i++;
		}
		else
			ft_printf_ch(str[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
