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

int		ft_skip_for_larger(t_stack *a, int n, int min)
{
	t_stack	*t1;
	t_stack	*t2;
	int		largest;
	int		large;
	int		temp;
	int		tmin;
	int		k;
	int		j;
	int		i;

	j = 0;
	t1 = a;
	largest = 0;
	while (j < n - 1)
	{
		i = 0;
		large = 0;
		t2 = t1;
		tmin = min;
		while (j + i < n - 1)
		{
			temp = t2->value;
			t2 = t2->next;
			if (t2->value >= tmin)
			{
				large++;
				tmin = t2->value;
			}
			i++;
		}
		if (large > largest)
		{
			ft_printf("larger\n");
			largest = large;
			k = j;
		}
		t1 = t1->next;
		j++;
	}
	ft_printf("Help%d, %d, %d\n", k, large, largest);
	return (k);
}

void	ft_largest_stalin_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	i;
	int	n;

	n = ft_stacksize(*a);
	i = ft_skip_for_larger(*a, n, ft_get_smallest(*a, n));
	rep(pb, a, b, i + 1);
	min = ft_get_smallest(*a, n - i - 1);
	while (i < n)
	{
		if ((*a)->value <= min)
			pb(a, b);
		else
        {
            min = (*a)->value;
			ra(a, b);
        }
		i++;
	}
}
