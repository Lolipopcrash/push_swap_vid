/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_p_instructions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:56 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:57 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*top_to;
	t_stack	*top_from;

	if (ft_stacksize(*stack_from) == 0)
		return (-1);
	top_to = *stack_to;
	top_from = *stack_from;
	tmp = top_from;
	top_from = top_from->next;
	*stack_from = top_from;
	if (!top_to)
	{
		top_to = tmp;
		top_to->next = NULL;
		*stack_to = top_to;
	}
	else
	{
		tmp->next = top_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	if (ft_push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (ft_push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
