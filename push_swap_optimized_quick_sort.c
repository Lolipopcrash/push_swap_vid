/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimized_quick_sort.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:29 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:42 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_endrevsorted(t_stack *stack, int n)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack && stack->next && i < n)
	{
		if (stack->value < stack->next->value)
			j++;
		else
			j = 1;
		stack = stack->next;
		i++;
	}
	return (j);
}

int	ft_is_endsorted(t_stack *stack, int n)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack && stack->next && i < n)
	{
		if (stack->value > stack->next->value)
			j++;
		else
			j = 1;
		stack = stack->next;
		i++;
	}
	return (j);
}

static void	ft_ibubble_sort(t_stack **a, t_stack **b, bool invert, int size)
{
	int	i;

	if (!invert)
	{
		while (!ft_is_nsorted(*a, size))
		{
			i = 0;
			while (i < size - 1)
			{
				if ((*a)->value > (*a)->next->value)
				{
					sa(a, b);
					ra(a, b);
				}
				else
					ra(a, b);
				i++;
			}
			while (i > 0)
			{
				rra(a, b);
				if ((*a)->value > (*a)->next->value)
					sa(a, b);
				i--;
			}
			size = size - ft_is_endsorted(*a, size);
		}
	}
	else if (invert)
	{
		while (!ft_is_nrevsorted(*b, size))
		{
			i = 0;
			while (i < size - 1)
			{
				if ((*b)->value < (*b)->next->value)
				{
					sb(a, b);
					rb(a, b);
				}
				else
					rb(a, b);
				i++;
			}
			while (i > 0)
			{
				rrb(a, b);
				if ((*b)->value < (*b)->next->value)
					sb(a, b);
				i--;
			}
			size = size - ft_is_endrevsorted(*b, size);
		}
	}
}

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
	//ft_printf("j: %d, stacksize a: %d, stacksize b: %d\n", j, ft_stacksize(*a), ft_stacksize(*b));
	if (!invert && j != ft_stacksize(*a))
	{
		while (j > 0)
		{
			ft_ireverse(a, b, invert);
			j--;
		}
	}
	else if (invert && j != ft_stacksize(*b))
	{
		while (j > 0)
		{
			ft_ireverse(a, b, invert);
			j--;
		}
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

void	ft_optimized_quick_sort(t_stack **a, t_stack **b, bool invert, int size, int start)
{
	int	i;
	int	j;

	if (size == 1)
	{
		//ft_printf("size 1 return\n");
		return;
	}
	else if (size == 2)
	{
		//ft_printf("size 2 sort and return\n");
		ft_qsort_two(a, b, invert);
		return;
	}
	else if (size <= 20)
	{
		ft_ibubble_sort(a, b, invert, size);
		return;
	}
	//ft_printf("sorting %d\n", size);
	ft_qsort(a, b, invert, size, start);

	i = size % 2;
	//ft_printf("splitting size: %d, %d; start: %d, %d invert: %d\n", (size + i) / 2, size / 2, start + (size / 2), start, invert);
	if (!invert)
	{
		ft_optimized_quick_sort(a, b, invert, (size + i) / 2, start + (size / 2));
		ft_optimized_quick_sort(a, b, !invert, size / 2, start);
	}
	else
	{
		ft_optimized_quick_sort(a, b, invert, size / 2, start);
		ft_optimized_quick_sort(a, b, !invert, (size + i) / 2, start + (size / 2));
	}

	//ft_printf("merging %d\n", size);
	/*if (!invert)
		ft_printf("stacksize: %d size / 2: %d\n", ft_stacksize(*b), size / 2);
	else
		ft_printf("stacksize: %d size / 2: %d\n", ft_stacksize(*a), size / 2);*/
	j = 0;
	while (j < (size + invert) / 2)
	{
		ft_ipush(a, b, invert);
		j++;
	}
}
