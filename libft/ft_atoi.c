/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:34:57 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/23 18:21:32 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (!((9 <= c && c <= 13) || c == 32))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45)
		&& !(nptr[i + 1] == 43 || nptr[i + 1] == 45))
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10;
		result = result + (nptr[i] - 48);
		i++;
	}
	if ((sign % 2) == 1)
		result = -result;
	return (result);
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] == 43 || nptr[i] == 45)
		&& !(nptr[i + 1] == 43 || nptr[i + 1] == 45))
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10;
		result = result + (nptr[i] - 48);
		i++;
	}
	if ((sign % 2) == 1)
		result = -result;
	return (result);
}
