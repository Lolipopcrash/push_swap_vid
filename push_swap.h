/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:33:48 by kelevequ          #+#    #+#             */
/*   Updated: 2024/12/01 13:33:50 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# include <stdbool.h>
# include <limits.h>

// Stack
typedef struct s_stack
{
	int				value;
	int				t_idx;
	struct s_stack	*next;
}	t_stack;

// Simulation
typedef struct s_array
{
	int	*value;
	int	*t_idx;
	int	size;
}	t_array;

// Push Swap Operations
int		sa(t_stack **a, t_stack **b);
int		sb(t_stack **a, t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		ra(t_stack **a, t_stack **b);
int		rb(t_stack **a, t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a, t_stack **b);
int		rrb(t_stack **a, t_stack **b);
int		rrr(t_stack **a, t_stack **b);
// Repeatable Operation Function
int		rep(int (f)(t_stack **, t_stack **), t_stack **a, t_stack **b, int n);

// Translated lst to stack functions
t_stack	*ft_stacknew(int value);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
// Free stack
int		ft_getvalue(t_stack **stack, int depth);
void	free_stack(t_stack **stack);

// Sort Handler
int		ft_is_sorted(t_stack *stack);
int		ft_is_revsorted(t_stack *stack);
int		ft_is_nsorted(t_stack *stack, int n);
int		ft_is_nrevsorted(t_stack *stack, int n);
int		ft_get_smallest(t_stack *stack, int size);
void	ft_sorting_handler(t_stack **a, t_stack **b);

// Simple Presort
void	ft_simple_presort(t_array *arr);

// Real-ish Sorts
void	ft_bubble_sort(t_stack **a, t_stack **b);
void	ft_optimized_bubble_sort(t_stack **a, t_stack **b);
void	ft_insertion_sort(t_stack **a, t_stack **b);
void	ft_optimized_insertion_sort(t_stack **a, t_stack **b);
void	ft_shaker_sort(t_stack **a, t_stack **b);
void	ft_optimized_shaker_sort(t_stack **a, t_stack **b);
void	ft_double_bubble_sort(t_stack **a, t_stack **b);
void	ft_double_shaker_sort(t_stack **a, t_stack **b);
void	ft_optimized_double_shaker_sort(t_stack **a, t_stack **b);
void	ft_selection_sort(t_stack **a, t_stack **b);
void	ft_quick_sort(t_stack **a, t_stack **b, bool invert, int size, int start);
void	ft_optimized_quick_sort(t_stack **a, t_stack **b, bool invert, int size, int start);
void	ft_binary_radix(t_stack **a, t_stack **b);
void	ft_comb_sort(t_stack **a, t_stack **b);

// Funny Sorts
void	ft_bogo_sort(t_stack **a, t_stack **b);
void	ft_stalin_sort(t_stack **a, t_stack **b);
void	ft_largest_stalin_sort(t_stack **a, t_stack **b);
void	ft_recursive_stalin_sort(t_stack **a, t_stack **b, int n, bool stack);

// Simple Sorts
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a, t_stack **b);
void	ft_sort_two(t_stack **a, t_stack **b);

#endif
