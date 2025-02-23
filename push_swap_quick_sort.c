/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ipush(t_stack **a, t_stack **b, bool invert)
{
	if (!invert)
		pa(a, b);
	else
		pb(a, b);
}

static void	ft_irotate(t_stack **a, t_stack **b, bool invert)
{
	if (!invert)
		ra(a, b);
	else
		rb(a, b);
}

static void	ft_ireverse(t_stack **a, t_stack **b, bool invert)
{
	if (!invert)
		rra(a, b);
	else
		rrb(a, b);
}

static void	ft_iswap(t_stack **a, t_stack **b, bool invert)
{
	if (!invert)
		sa(a, b);
	else
		sb(a, b);
}

static void	ft_qsort(t_stack **a, t_stack **b, bool invert, int size, int start)
{
	int	value;
	int	temp;
	int	j;
	int	i;

	temp = (size / 2) + start;
	j = 0;
	i = 0;
	while (i < size)
	{
		if (!invert)
			value = (*a)->value;
		else
			value = (*b)->value;
		//ft_printf("\nWhat the flip...%d...%d...%d...", value, temp, invert);
		if ((value <= temp) != invert)
		{
			//ft_printf("push\n");
			ft_ipush(a, b, !invert);
		}
		else
		{
			//ft_printf("rotate\n");
			ft_irotate(a, b, invert);
			j++;
		}
		i++;
	}
	while (j > 0)
	{
		ft_ireverse(a, b, invert);
		j--;
	}
}

static void	ft_qsort_two(t_stack **a, t_stack **b, bool invert)
{
	if (!invert)
	{
		if ((*a)->value > (*a)->next->value)
			ft_iswap(a, b, invert);
	}
	else
	{
		if ((*b)->value < (*b)->next->value)
			ft_iswap(a, b, invert);
	}
}

void	ft_quick_sort(t_stack **a, t_stack **b, bool invert, int size, int start)
{
	int	i;
	int	j;
	//End of Splits
	if (size == 1)
		return;
	else if (size == 2)
	{
		ft_qsort_two(a, b, invert);
		return;
	}
	//Splitter
	ft_qsort(a, b, invert, size, start);
	//Sort both Splits
	i = size % 2;
	if (!invert)
	{
		ft_quick_sort(a, b, invert, (size + i) / 2, start + (size / 2));
		ft_quick_sort(a, b, !invert, size / 2, start);
	}
	else
	{
		ft_quick_sort(a, b, invert, size / 2, start);
		ft_quick_sort(a, b, !invert, (size + i) / 2, start + (size / 2));
	}
	//Merging Sorted Splits
	j = 0;
	while (j < (size + invert) / 2)
	{
		ft_ipush(a, b, invert);
		j++;
	}
}
