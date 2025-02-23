/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:34:31 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/26 14:29:07 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*temp_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	temp_s = ft_calloc(len + 1, sizeof(char));
	if (!temp_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp_s[i] = s[start + i];
		i++;
	}
	temp_s[i] = '\0';
	return (temp_s);
}
