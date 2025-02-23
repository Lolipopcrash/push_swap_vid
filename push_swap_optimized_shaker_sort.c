/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimized_shaker_sort.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_nrevsorted(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack && stack->next && i < n)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	ft_is_nsorted(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack && stack->next && i < n)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	ft_optimized_shaker_sort(t_stack **a, t_stack **b)
{
	bool	swap;
	int		i;
	int		j;
	int		n;

	swap = 1;
	i = 0;
	j = 0;
	n = ft_stacksize(*a);
	while (j < n / 2 && swap)
	{
		swap = 0;
		while (i < n - j - 1)
		{
			if ((*a)->value > (*a)->next->value)
			{
				swap = 1;
				sa(a, b);
				ra(a, b);
			}
			else
				ra(a, b);
			i++;
		}
		if (!swap)
			break;
		rra(a, b);
		j++;
		while (i - j + 1 > 0)
		{
			if ((*a)->value > (*a)->next->value && i - j + 1 != 1)
			{
				sa(a, b);
				rra(a, b);
			}
			else if ((*a)->value > (*a)->next->value)
				sa(a, b);
			else if (i - j + 1 != 1)
				rra(a, b);
			i--;
		}
	}
	if (i > n / 2)
		rep(ra, a, b, n - i);
	else
		rep(rra, a, b, i);
}
