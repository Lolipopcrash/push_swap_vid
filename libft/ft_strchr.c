/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:30:18 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/21 15:11:05 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			ch_c;

	i = 0;
	ch_c = (char) c;
	while (s[i])
	{
		if (s[i] == ch_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch_c)
		return ((char *) &s[i]);
	return (NULL);
}
