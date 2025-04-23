/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:13:55 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/12 23:13:55 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_six(t_stack **a, t_stack **b);
void	bubble_sort(int *arr, int size);
void	sort_stack(t_stack **a, t_stack **b);
void	index_stack(t_stack *stack);
void	sort_hundred(t_stack **a, t_stack **b);
void	sort_five_hundred(t_stack **a, t_stack **b);
void	move_min_to_top(t_stack **a);
void	radix_sort(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	free_stack(t_stack *stack);

t_stack	*parse_args(int argc, char **argv);

int		is_duplicate(t_stack *stack, int value);
int		ft_atol(const char *str, long *result);

#endif