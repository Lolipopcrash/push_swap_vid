/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:51:51 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 14:39:55 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ptr(void *ptr, int *counter)
{
	if (ptr == 0)
		ft_printf_str("(nil)", counter);
	else
	{
		ft_printf_str("0x", counter);
		ft_printf_base((unsigned long) ptr, "0123456789abcdef", counter);
	}
}
