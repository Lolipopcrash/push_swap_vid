/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:56 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:57 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*next;
	int		tmp_val;
	int		tmp_idx;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	tmp_val = top->value;
	tmp_idx = top->t_idx;
	top->value = next->value;
	top->t_idx = next->t_idx;
	next->value = tmp_val;
	next->t_idx = tmp_idx;
	return (0);
}

int	sa(t_stack **a, t_stack **b)
{
	(void) b;
	if (ft_swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **a, t_stack **b)
{
	(void) a;
	if (ft_swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **a, t_stack **b)
{
	if ((ft_stacksize(*a) < 2) || (ft_stacksize(*b) < 2))
		return (-1);
	ft_swap(a);
	ft_swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rep(int (f)(t_stack **, t_stack **), t_stack **a, t_stack **b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (f(a, b) == -1)
			return (-1);
		i++;
	}
	return (1);
}
