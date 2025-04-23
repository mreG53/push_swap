/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <emgumus@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:03:55 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/21 12:30:00 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	move_min_to_top(t_stack **a)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	tmp = *a;
	pos = 0;
	size = stack_size(*a);
	while (tmp && tmp->index != find_min_index(*a))
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while (pos--)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

static void	sort_large(t_stack **a, t_stack **b, int size)
{
	if (size <= 100)
	{
		index_stack(*a);
		sort_hundred(a, b);
	}
	else if (size <= 500)
	{
		index_stack(*a);
		sort_five_hundred(a, b);
	}
	else
	{
		index_stack(*a);
		radix_sort(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size == 6)
		sort_six(a, b);
	else
		sort_large(a, b, size);
}
