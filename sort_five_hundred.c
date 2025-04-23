/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:57:14 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/21 21:57:14 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos_max(t_stack *stack)
{
	int		pos;
	int		max;
	t_stack	*tmp;

	pos = 0;
	max = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp->index != max)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

static void	partition_chunks(t_stack **a, t_stack **b,
			int chunk_size, int chunks)
{
	int	size;
	int	count;
	int	chunk;

	size = stack_size(*a);
	count = 0;
	chunk = 1;
	while (count < size)
	{
		if ((*a)->index < chunk_size * chunk)
		{
			pb(a, b);
			if ((*b)->index < (chunk_size * (chunk - 1) \
				+ chunk_size / 2))
				rb(b);
			count++;
		}
		else
			ra(a);
		if (count == chunk_size * chunk && chunk < chunks)
			chunk++;
	}
}

static void	pop_back(t_stack **a, t_stack **b)
{
	int	pos;

	while (*b)
	{
		pos = get_pos_max(*b);
		if (pos <= stack_size(*b) / 2)
			while (pos--)
				rb(b);
		else
			while (pos++ < stack_size(*b))
				rrb(b);
		pa(a, b);
	}
}

void	sort_five_hundred(t_stack **a, t_stack **b)
{
	int	size;
	int	chunks;
	int	chunk_size;

	size = stack_size(*a);
	chunks = 11;
	chunk_size = size / chunks + (size % chunks != 0);
	partition_chunks(a, b, chunk_size, chunks);
	pop_back(a, b);
}
