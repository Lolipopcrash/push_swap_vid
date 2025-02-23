/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_r_instructions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:56 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:57 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bot;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	top = *stack;
	bot = ft_stacklast(top);
	*stack = top->next;
	top->next = NULL;
	bot->next = top;
	return (0);
}

int	ra(t_stack **a, t_stack **b)
{
	(void) b;
	if (ft_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **a, t_stack **b)
{
	(void) a;
	if (ft_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	if ((ft_stacksize(*a) < 2) || (ft_stacksize(*b) < 2))
		return (-1);
	ft_rotate(a);
	ft_rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}
