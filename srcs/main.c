/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:34 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/11 00:09:25 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	help_norm(char **args, t_stack *a, t_stack *b)
{
	if (!check_and_fill(a, args))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		free_array(args);
		free(a);
		free(b);
		return (1);
	}
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small(a, b);
		else
			sort_large(a, b);
	}
	return (0);
}

void	last_free(char **args, t_stack *a, t_stack *b)
{
	free_array(args);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (ac < 2)
		return (0);
	if (ac >= 2)
	{
		a = init_stack();
		if (!a)
			return (1);
		b = init_stack();
		if (!b)
		{
			free(a);
			return (1);
		}
		args = parse_args(ac, av);
		if (!args)
			return (free(a), free(b), 1);
		if (help_norm(args, a, b))
			return (1);
		return (last_free(args, a, b), 0);
	}
	return (1);
}
