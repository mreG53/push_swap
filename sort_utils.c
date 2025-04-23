/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:47:02 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/13 01:47:02 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack-> value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int	*copy_to_array(t_stack *stack, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (array);
}

void	index_stack(t_stack *stack)
{
	int		*array;
	int		size;
	int		i;
	t_stack	*tmp;

	size = stack_size(stack);
	array = copy_to_array(stack, size);
	if (!array)
		return ;
	bubble_sort(array, size);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size && tmp->value != array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(array);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!arr || size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
