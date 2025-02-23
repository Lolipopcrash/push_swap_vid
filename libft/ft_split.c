/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:13 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/23 16:54:23 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_wordcpy(const char *s, char c, int i)
{
	char	*result;
	int		temp_i;
	int		k;

	k = 0;
	temp_i = i;
	while (s[temp_i] != '\0' && s[temp_i] != c)
	{
		k++;
		temp_i++;
	}
	result = (char *) malloc(sizeof(char) * (k + 1));
	k = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		result[k] = s[i];
		i++;
		k++;
	}
	result[k] = '\0';
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = (char **) malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			result[j] = ft_wordcpy(s, c, i);
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	result[j] = NULL;
	return (result);
}
