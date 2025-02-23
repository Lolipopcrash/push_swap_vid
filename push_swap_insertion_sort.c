/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertion_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_insertion_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	n;

	n = ft_stacksize(*a);
	rep(pb, a, b, n - 2);
	if ((*a)->value > (*a)->next->value)
		sa(a, b);
	while (b[0] != NULL)
	{
		i = 0;
		n = ft_stacksize(*a);
		while (i < n)
		{
			if ((*b)->value < (*a)->value)
			{
				pa(a, b);
				break;
			}
			else if ((*b)->value > (*a)->value && i < n - 1)
				ra(a, b);
			else
			{
				pa(a, b);
				sa(a, b);
				break;
			}
			i++;
		}
		rep(ra, a, b, n - i + 1);
	}
}
