/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:14:03 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/12 23:14:03 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
