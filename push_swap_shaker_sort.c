/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_shaker_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shaker_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	n;

	i = 0;
	n = ft_stacksize(*a);
	while (!ft_is_sorted(*a))
	{
		while (i < n - 1)
		{
			if ((*a)->value > (*a)->next->value)
			{
				sa(a, b);
				ra(a, b);
			}
			else
				ra(a, b);
			i++;
		}
		rra(a, b);
		while (i > 0)
		{
			if ((*a)->value > (*a)->next->value && i != 1)
			{
				sa(a, b);
				rra(a, b);
			}
			else if ((*a)->value > (*a)->next->value)
				sa(a, b);
			else if (i != 1)
				rra(a, b);
			i--;
		}
	}    
}
