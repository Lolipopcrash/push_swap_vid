/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:37:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:53 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_base(unsigned long n, char *base, int *counter)
{
	unsigned long long	size;

	size = ft_strlen(base);
	if (n > size - 1)
		ft_printf_base(n / size, base, counter);
	ft_printf_ch(base[n % size], counter);
}
