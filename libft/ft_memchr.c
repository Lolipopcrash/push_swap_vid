/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:49 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/21 14:49:39 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;
	size_t			i;

	temp_s = (unsigned char *) s;
	temp_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == temp_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
