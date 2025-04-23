/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <emgumus@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:14:00 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/21 13:40:00 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char const *s, char c);

static int	is_digit_str(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (i > 0);
}

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

static int	add_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*tmp;

	node = new_node(value);
	if (!node)
		return (0);
	if (!*stack)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}

static int	parse_token_list(char *arg, t_stack **a)
{
	char	**tokens;
	int		j;
	long	val;
	int		ok;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	j = 0;
	ok = 1;
	while (tokens[j] && ok)
	{
		if (!is_digit_str(tokens[j])
			|| !ft_atol(tokens[j], &val)
			|| is_duplicate(*a, (int)val)
			|| !add_node(a, (int)val))
			ok = 0;
		free(tokens[j]);
		j++;
	}
	while (tokens[j])
		free(tokens[j++]);
	free(tokens);
	return (ok);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_token_list(argv[i], &a))
			return (free_stack(a), NULL);
		i++;
	}
	return (a);
}
