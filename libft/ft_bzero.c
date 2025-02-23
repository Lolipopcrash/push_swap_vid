/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:26:24 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/23 16:28:52 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp_ptr;
	size_t			i;

	i = 0;
	temp_ptr = (unsigned char *) s;
	while (i < n)
	{
		temp_ptr[i] = 0;
		i++;
	}
}
