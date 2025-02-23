/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:34:15 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/17 13:37:35 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			ch_c;

	i = ft_strlen(s);
	ch_c = (char) c;
	while (i > 0)
	{
		if (s[i] == ch_c)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == ch_c)
		return ((char *) &s[i]);
	return (NULL);
}
