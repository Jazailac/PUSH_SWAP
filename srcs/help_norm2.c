/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_norm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalalzailachi <jalalzailachi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:30 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/10 20:34:04 by jalalzailac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_a(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		return (pos);
	return (a->size - pos);
}

int	calculate_cost_b(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
		return (pos);
	return (b->size - pos);
}

int	find_min(t_stack *stack)
{
	t_node	*curr;
	int		min;

	min = INT_MAX;
	curr = stack->top;
	while (curr)
	{
		if (curr->value < min)
			min = curr->value;
		curr = curr->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->top;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}