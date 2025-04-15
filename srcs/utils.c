/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:53 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:55:35 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_pos(t_stack *stack)
{
	int		smallest_pos;
	int		i;
	t_node	*current;
	int		smallest;

	smallest_pos = 0;
	i = 0;
	current = stack->top;
	smallest = current->value;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			smallest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (smallest_pos);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
