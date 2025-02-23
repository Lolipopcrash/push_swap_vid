/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:46:12 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/21 14:45:02 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*temp_s;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	temp_s = (char *) malloc(sizeof(char) * size);
	i = 0;
	while (s1[i] != '\0')
	{
		temp_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		temp_s[i + j] = s2[j];
		j++;
	}
	temp_s[i + j] = '\0';
	return (temp_s);
}
