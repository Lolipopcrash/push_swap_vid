/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:05:00 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 14:39:25 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex(unsigned long n, const char c, int *counter)
{
	if (c == 'X')
		ft_printf_base(n, "0123456789ABCDEF", counter);
	else
		ft_printf_base(n, "0123456789abcdef", counter);
}
