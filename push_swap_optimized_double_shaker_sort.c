/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_double_bubble_sort.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimized_double_shaker_sort(t_stack **a, t_stack **b)
{
	bool	swap;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	swap = 1;
	n = ft_stacksize(*a);
	rep(pb, a, b, n / 2);
	while (j < n / 2 && swap)
	{
		swap = 0;
		while (i < (n / 2) - j - (1 - (n % 2)) - (j != 0))
		{
			if ((*a)->value > (*a)->next->value && (*b)->value > (*b)->next->value && i < (n / 2) - (n % 2 == 1 && j == 0))
			{
				swap = 1;
				ss(a, b);
				rr(a, b);
			}
			else if ((*b)->value > (*b)->next->value && i < (n / 2) - (n % 2 == 1 && j == 0))
			{
				swap = 1;
				sb(a, b);
				rr(a, b);
			}
			else if ((*a)->value > (*a)->next->value)
			{
				swap = 1;
				sa(a, b);
				rr(a, b);
			}
			else
				rr(a, b);
			i++;
		}
		if (!swap)
			break;
		if (n % 2 == 0 || j != 0)
			rrr(a, b);
		else
			rra(a, b);
		while (i - j > 0)
		{
			if ((*a)->value > (*a)->next->value && (*b)->value > (*b)->next->value && i < (n / 2) - 1)
				ss(a, b);
			else if ((*b)->value > (*b)->next->value && i < (n / 2) - 1)
				sb(a, b);
			else if ((*a)->value > (*a)->next->value)
				sa(a, b);
			if (i - j != 1)
				rrr(a, b);
			i--;
		}
		j++;
	}

	rep(rr, a, b, (n / 2) - i - 1);
	if (n % 2 == 1)
		ra(a, b);
	else
		rr(a, b);

	i = ft_stacksize(*b);
	while (b[0] != NULL)
	{
		if ((*b)->value < (*a)->value)
		{
			pa(a, b);
			ra(a, b);
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
		}
	}
	rep(ra, a, b, n - i);
}
