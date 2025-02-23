/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimized_bubble.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_largest(t_stack *stack, int size)
{
	t_stack	*temp;
	int		largest;
	int		i;

	temp = stack;
	i = 1;
	largest = stack->value;
	while (i < size)
	{
		temp = temp->next;
		if (temp->value > largest)
			largest = temp->value;
		i++;
	}
	return (largest);
}

void	ft_optimized_bubble_sort(t_stack **a, t_stack **b)
{
	int	largest;
	int	i;
	int	j;
	int	n;

	j = 0;
	n = ft_stacksize(*a);
	while (!ft_is_sorted(*a))
	{
		i = 0;
		largest = ft_get_largest(*a, n - j);
		while (i < n - j - 1)
		{
			if ((*a)->value > (*a)->next->value)
			{
				sa(a, b);
				ra(a, b);
			}
			else
				ra(a, b);
			i++;
			if (i == n - j - 1 && (*a)->value == largest)
				j++;
		}
		if (i < n / 2)
			rep(rra, a, b, i);
		else if (i >= n / 2)
			rep(ra, a, b, j);
	}    
}
