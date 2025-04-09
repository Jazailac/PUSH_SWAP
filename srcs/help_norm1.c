/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_norm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:27 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:14:37 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotate_a(t_stack *a, int pos)
{
	int	i;

	if (pos <= a->size / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < a->size - pos)
		{
			rra(a);
			i++;
		}
	}
}

void	execute_rotate_b(t_stack *b, int pos)
{
	int	i;

	if (pos <= b->size / 2)
	{
		i = 0;
		while (i < pos)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < b->size - pos)
		{
			rrb(b);
			i++;
		}
	}
}

void	execute_best_move(t_stack *a, t_stack *b)
{
	t_move	best_move;

	best_move = find_best_move(a, b);
	execute_rotate_a(a, best_move.a_pos);
	execute_rotate_b(b, best_move.b_pos);
	pa(a, b);
}

int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_index;
	int		i;

	current = stack->top;
	min_value = INT_MAX;
	min_index = -1;
	i = 0;
	while (current)
	{
		if (current->value <= min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

//why do we need to final rotate
void	final_rotate(t_stack *a)
{
	int	min_index;

	min_index = get_min_index(a);
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		while (min_index < a->size)
		{
			rra(a);
			min_index++;
		}
	}
}
