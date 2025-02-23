/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_rr_instructions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:56 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:57 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bot;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	top = *stack;
	bot = ft_stacklast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bot->next = *stack;
	*stack = bot;
	return (0);
}

int	rra(t_stack **a, t_stack **b)
{
	(void) b;
	if (ft_reverse(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void) a;
	if (ft_reverse(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	if ((ft_stacksize(*a) < 2) || (ft_stacksize(*b) < 2))
		return (-1);
	ft_reverse(a);
	ft_reverse(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
