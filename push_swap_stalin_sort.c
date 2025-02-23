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

void	ft_stalin_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	i;
	int	n;

	n = ft_stacksize(*a);
	min = ft_get_smallest(*a, n) - 1;
	i = 0;
	while (i < n)
	{
		if ((*a)->value < min)
			pb(a, b);
		else
        {
            min = (*a)->value;
			ra(a, b);
        }
		i++;
	}
}
