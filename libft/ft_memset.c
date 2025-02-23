/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:36:41 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/22 11:51:44 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	i = 0;
	temp_s = (unsigned char *) s;
	while (i < n)
	{
		temp_s[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
