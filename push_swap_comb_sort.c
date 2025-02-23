/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comb_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:29:00 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/02 10:29:02 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_comb_sort(t_stack **a, t_stack **b)
{
	int		k;
	int		j;
	int		i;
	int		n;
	int		gap;

	n = ft_stacksize(*a);
	gap = n;
	while (gap >= 1 && !ft_is_sorted(*a))
	{
		//ft_printf("gap, outer loop\n");
		if (gap / 1.3 > 1)
			gap = gap / 1.3;
		j = 0;
		if (gap > 1)
		{
			while (j + gap < n)
			{
				//ft_printf("j + gap, inner loop\n");
				i = 0;
				k = 0;
				while (i + k < gap && j + i + k < n)
				{
					if (i < gap && j + i < n - gap)
					{
						pb(a, b);
						i++;
					}
					else
					{
						ra(a, b);
						k++;
					}
				}
				while (k != gap)
				{
					rrb(a, b);
					if ((*a)->value < (*b)->value)
					{
						pa(a, b);
						ra(a, b);
						pb(a, b);
					}
					else
						ra(a, b);
					k++;
				}
				while (k > 0)
				{
					rra(a, b);
					k--;
				}
				while (k < i)
				{
					pa(a, b);
					k++;
				}
				j = j + i;
				while (j != j + k && j + gap < n)
				{
					ra(a, b);
					k--;
				}
			}
			if (j + gap >= n)
				rep(ra, a, b, gap + k);
		}
		else
			ft_bubble_sort(a, b);
	}
}
