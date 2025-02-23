/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:13:01 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/28 17:15:57 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	size_t	j;
	size_t	k;

	j = 0;
	k = ft_strlen(s1);
	while (j < k && ft_strchr(set, s1[j]) != 0)
		j++;
	while (k > j && ft_strchr(set, s1[k - 1]) != 0)
		k--;
	k = k - j;
	result = ft_calloc(sizeof(char), k + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + j, k + 1);
	return (result);
}
