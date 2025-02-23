/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_binary_radix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bilen(t_stack *a)
{
	int	max;
	int	i;

	max = a->value;
	while (a->next)
	{
		if (a->value < 0)
			return (32);
		a = a->next;
		if (a->value > max)
			max = a->value;
	}
	i = 1;
	while (max > 1)
	{
		max = max / 2;
		i++;
	}
	return (i);
}

int	ft_valid_pb(int n, int k)
{
	if (k == 31 && n < 0)
		return (1);
	else if (k != 31 && ((n >> k) & 1) == 0)
		return (1);
	else
		return (0);
}

void	ft_binary_radix(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	k;
	int	n;

	i = 0;
	k = ft_bilen(*a);
	n = ft_stacksize(*a);
	while (i < k)
	{
		j = 0;
		while (j < n)
		{
			if (ft_valid_pb((*a)->value, i))
				pb(a, b);
			else
				ra(a, b);
			j++;
		}
		rep(pa, a, b, j);
		i++;
	}
}
