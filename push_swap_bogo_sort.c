/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bogo_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	n;

	n = ft_stacksize(*a);
	while (!ft_is_sorted(*a))
	{
		i = 0;
		while (i < n)
		{
			if (rand() % 2 == 1)
				pb(a, b);
			else
				ra(a, b);
			i++;
		}
		while (b[0] != NULL)
			pa(a, b);
	}
}