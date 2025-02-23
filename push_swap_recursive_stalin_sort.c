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

int	ft_valid_stalin_push(t_stack **a, t_stack **b, int *min, bool stack)
{
	int	size;

	size = 0;
	if (!stack)
	{
		if ((*a)->value <= (*min))
		{
			pb(a, b);
			size++;
		}
		else
		{
			(*min) = (*a)->value;
			ra(a, b);
		}
	}
	else
	{
		if ((*b)->value <= (*min))
		{
			pa(a, b);
			size++;
		}
		else
		{
			(*min) = (*b)->value;
			rb(a, b);
		}
	}
	return (size);
}

int	ft_stack_smallest(t_stack **a, t_stack **b, int n, bool stack)
{
	if (!stack)
		return (ft_get_smallest(*a, n));
	else
		return (ft_get_smallest(*b, n));
}

void	ft_reset_stalin(t_stack **a, t_stack **b, int n, int size, bool stack)
{
	if (!stack)
		rep(rra, a, b, n - size);
	else
		rep(rrb, a, b, n - size);
}

void	ft_valid_stalin_merge(t_stack **a, t_stack **b, int n, int size, bool stack)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (!stack)
	{
		while (j < size)
		{
			if ((*b)->value < (*a)->value)
			{
				pa(a, b);
				ra(a, b);
				j++;
			}
			else if ((*b)->value > (*a)->value && n - i > 0)
			{
				ra(a, b);
				i++;
			}
			else
			{
				pa(a, b);
				ra(a, b);
				j++;
			}
		}
		rep(rra, a, b, i + j);
	}
	else
	{
		while (j < size)
		{
			if ((*a)->value < (*b)->value)
			{
				pb(a, b);
				rb(a, b);
				j++;
			}
			else if ((*a)->value > (*b)->value && n - i > 0)
			{
				rb(a, b);
				i++;
			}
			else
			{
				pb(a, b);
				rb(a, b);
				j++;
			}
		}
		rep(rrb, a, b, i + j);
	}
}

void	ft_swap_stalin(t_stack **a, t_stack **b, bool stack)
{
	if (!stack)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, b);
	}
	else
	{
		if ((*b)->value > (*b)->next->value)
			sb(a, b);
	}
}

void	ft_recursive_stalin_sort(t_stack **a, t_stack **b, int n, bool stack)
{
	int	size;
	int	min;
	int	i;

	if (n == 1)
		return;
	if (n == 2)
	{
		ft_swap_stalin(a, b, stack);
		return;
	}
	min = ft_stack_smallest(a, b, n, stack) - 1;
	size = 0;
	i = 0;
	while (i < n)
	{
		size += ft_valid_stalin_push(a, b, &min, stack);
		i++;
	}

	ft_recursive_stalin_sort(a, b, size, !stack);

	ft_reset_stalin(a, b, n, size, stack);

	ft_valid_stalin_merge(a, b, n, size, stack);
}
