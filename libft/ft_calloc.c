/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:28:03 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/29 11:32:47 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			total;

	total = nmemb * size;
	if (total != 0 && total / size != nmemb)
		return (NULL);
	result = malloc(total);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total);
	return (result);
}
