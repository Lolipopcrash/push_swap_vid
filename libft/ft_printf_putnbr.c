/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:57:43 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:31 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr(int n, int *counter)
{
	if (n < 0)
	{
		ft_printf_ch('-', counter);
		n = -n;
	}
	ft_printf_unsigned(n, counter);
}
