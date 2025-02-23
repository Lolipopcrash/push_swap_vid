/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_selection_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_smallest(t_stack *stack, int size)
{
	t_stack	*temp;
	int		smallest;
	int		i;

	temp = stack;
	i = 1;
	smallest = stack->value;
	while (i < size)
	{
		temp = temp->next;
		if (temp->value < smallest)
			smallest = temp->value;
		i++;
	}
	return (smallest);
}

void	ft_selection_sort(t_stack **a, t_stack **b)
{
	int	smallest;
	int	i;
	int	j;
	int	n;

	j = 0;
	n = ft_stacksize(*a);
	while (j < n - 1)
	{
		i = 0;
		smallest = ft_get_smallest(*a, n - j);
		while (i < n - j)
		{
			if ((*a)->value == smallest)
			{
				pb(a, b);
				break;
			}
			else
				ra(a, b);
			i++;
		}
		j++;
	}
	rep(pa, a, b, n - 1);
}
