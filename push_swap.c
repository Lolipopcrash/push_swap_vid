/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:29:00 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/02 10:29:02 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_revsorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_norepeat(long num, t_stack **a, int n, int i)
{
	t_stack	*t;

	t = *a;
	while (i < n)
	{
		if (t->value == num)
			return (0);
		t = t->next;
		i++;
	}
	return (1);
}

int	ft_valid_input(t_stack **a, char *args[], int j)
{
	t_stack	*new;
	long	temp;
	int		i;

	i = j;
	while (args[i])
	{
		temp = ft_atol(args[i]);
		if (temp < -2147483648 || 2147483647 < temp)
			return (0);
		if (!ft_isnum(args[i]))
			return (0);
		if (!ft_norepeat(ft_atoi(args[i]), a, i, j))
			return (0);
		new = ft_stacknew(temp);
		ft_stackadd_back(a, new);
		i++;
	}
	return (1);
}

static int	ft_stackalloc(t_stack **a, int argc, char *argv[])
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (!ft_valid_input(a, args, i))
	{
		if (argc == 2)
			ft_free(args);
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (argc == 2)
		ft_free(args);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_stack **) malloc(sizeof(t_stack));
	stack_b = (t_stack **) malloc(sizeof(t_stack));
	stack_a[0] = NULL;
	stack_b[0] = NULL;
	if (ft_stackalloc(stack_a, argc, argv) && !ft_is_sorted(*stack_a))
		ft_sorting_handler(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}
