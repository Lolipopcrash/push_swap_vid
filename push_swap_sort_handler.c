/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <kelevequ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:29:00 by kelevequ          #+#    #+#             */
/*   Updated: 2025/01/10 08:14:45 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_arrayalloc(t_array *arr, t_stack **a)
{
	t_stack	*t;
	int		i;

	arr->value = ft_calloc(arr->size, sizeof(int));
	arr->t_idx = ft_calloc(arr->size, sizeof(int));
	t = *a;
	i = 0;
	while (i < arr->size)
	{
		arr->value[i] = t->value;
		arr->t_idx[i] = i;
		if (t->next)
			t = t->next;
		i++;
	}
}

void	ft_simple_presort(t_array *arr)
{
	int		temp;
	int		i;
	int		j;

	i = 0;
	while (i < arr->size)
	{
		j = 0;
		while (j + i < arr->size)
		{
			if (arr->value[i + j] < arr->value[i])
			{
				temp = arr->value[i];
				arr->value[i] = arr->value[i + j];
				arr->value[i + j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_stack_idx(t_stack **a, t_array *arr)
{
	t_stack	*t;
	int		i;
	int		j;

	t = *a;
	i = 0;
	while (i < arr->size)
	{
		j = 0;
		while (j < arr->size)
		{
			if (arr->value[j] == t->value)
			{
				t->t_idx = arr->t_idx[j];
				break ;
			}
			j++;
		}
		if (t->next)
			t = t->next;
		i++;
	}
}

void	ft_sorting_handler(t_stack **a, t_stack **b)
{
	//ft_sort_three(a, b);
	//ft_sort_four(a, b);
	//ft_sort_five(a, b);
	//ft_bubble_sort(a, b);
	//ft_optimized_bubble_sort(a, b);
	//ft_insertion_sort(a, b);
	//ft_optimized_insertion_sort(a, b);
	//ft_selection_sort(a, b);
	//ft_shaker_sort(a, b);
	//ft_optimized_shaker_sort(a, b);
	//ft_double_bubble_sort(a, b);
	ft_double_shaker_sort(a, b);
	//ft_optimized_double_shaker_sort(a, b);
	//ft_comb_sort(a, b);
	//ft_binary_radix(a, b);
	//ft_quick_sort(a, b, 0, ft_stacksize(*a), 0);
	//ft_optimized_quick_sort(a, b, 0, ft_stacksize(*a), 0);

	//ft_bogo_sort(a, b);
	//ft_stalin_sort(a, b);
	//ft_largest_stalin_sort(a, b);
	//ft_recursive_stalin_sort(a, b, ft_stacksize(*a), 0);
}
