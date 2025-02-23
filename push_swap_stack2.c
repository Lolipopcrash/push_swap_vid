/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:19:04 by kelevequ          #+#    #+#             */
/*   Updated: 2024/10/26 15:44:38 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getvalue(t_stack **stack, int pos)
{
	t_stack	*t;
	int		i;

	i = 0;
	t = *stack;
	while (i < pos)
	{
		t = t->next;
		i++;
	}
	return (t->value);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*byebye;

	temp = *stack;
	while (temp)
	{
		byebye = temp;
		temp = temp->next;
		free(byebye);
	}
	free(stack);
}
