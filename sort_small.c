/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:38:34 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/19 15:38:34 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_six(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		index_stack(*a);
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	if (*b && (*b)->next && (*b)->index > (*b)->next->index)
		sb(b);
	while (*b)
		pa(a, b);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	index_stack(*a);
	move_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	index_stack(*a);
	move_min_to_top(a);
	pb(a, b);
	index_stack(*a);
	move_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
