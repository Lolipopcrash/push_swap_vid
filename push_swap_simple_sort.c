/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:19:04 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/26 15:44:38 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, b);
}

void	ft_sort_three(t_stack **a, t_stack **b)
{
	if (ft_getvalue(a, 2) < (*a)->value)
		ra(a, b);
	if (ft_getvalue(a, 2) < (*a)->value)
		ra(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a, b);
	if (ft_getvalue(a, 1) > ft_getvalue(a, 2))
	{
		ra(a, b);
		sa(a, b);
		rra(a, b);
	}
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	while (b[0] == NULL)
	{
		if ((*a)->value < ft_getvalue(a, 1)
			&& (*a)->value < ft_getvalue(a, 2)
			&& (*a)->value < ft_getvalue(a, 3))
			pb(a, b);
		else
			ra(a, b);
	}
	ft_sort_three(a, b);
	pa(a, b);
}

int	ft_smallerthanthree(t_stack **a)
{
	t_stack	*t;
	int		smaller;

	t = *a;
	smaller = 0;
	while (t->next)
	{
		t = t->next;
		if ((*a)->value < t->value)
			smaller++;
	}
	if (smaller >= 3)
		return (1);
	return (0);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*b) != 2)
	{
		if (ft_smallerthanthree(a))
			pb(a, b);
		else
			ra(a, b);
	}
	ft_sort_three(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(a, b);
	rep(pa, a, b, 2);
}
