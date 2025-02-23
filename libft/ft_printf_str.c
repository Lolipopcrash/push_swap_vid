/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:33:48 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/02 13:59:15 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
		ft_printf_str("(null)", counter);
	else
		while (str[i] != '\0')
			ft_printf_ch(str[i++], counter);
}
