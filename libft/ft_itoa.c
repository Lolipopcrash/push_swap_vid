/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:45 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/26 15:13:40 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitcount(int n)
{
	size_t	i;

	if (n == -2147483648)
		return (11);
	i = 1;
	if (n < 0)
	{
		n = -n;
		i = 2;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_fill(char *result, long n, size_t count)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		result[0] = 45;
		n = -n;
	}
	while (i < count)
	{
		result[count - i] = 48 + (n % 10);
		n = n / 10;
		i++;
	}
	if (result[0] != 45)
		result[count - i] = 48 + n;
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	temp_n;
	char	*result;

	temp_n = n;
	i = ft_digitcount(n);
	result = ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_fill(result, temp_n, i - 1);
	result[i] = '\0';
	return (result);
}
