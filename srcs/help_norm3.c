/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_norm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:11:25 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/10 21:11:31 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_position(t_stack *a)
{
	t_node	*current;
	int		i;
	int		min_pos;
	int		min_value;

	min_value = INT_MAX;
	current = a->top;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value <= min_value)
		{
			min_value = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

static int	get_closest_bigger_position(t_stack *a, int value)
{
	t_node	*current;
	int		i;
	int		closest_pos;
	int		closest_value;

	closest_value = INT_MAX;
	current = a->top;
	closest_pos = -1;
	i = 0;
	while (current)
	{
		if (current->value > value && current->value <= closest_value)
		{
			closest_value = current->value;
			closest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (closest_pos);
}

int	find_target_position(t_stack *a, int value)
{
	int	min_pos;
	int	target_pos;

	target_pos = get_closest_bigger_position(a, value);
	min_pos = get_min_position(a);
	if (target_pos == -1)
		return (min_pos);
	return (target_pos);
}

t_move	find_best_move(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_move	best_move;
	int		b_pos;
	int		a_pos;
	int		cost;

	best_move.cost = INT_MAX;
	current_b = b->top;
	b_pos = 0;
	while (current_b)
	{
		a_pos = find_target_position(a, current_b->value);
		cost = calculate_cost_a(a, a_pos) + calculate_cost_b(b, b_pos);
		if (cost <= best_move.cost)
		{
			best_move.a_pos = a_pos;
			best_move.b_pos = b_pos;
			best_move.cost = cost;
		}
		current_b = current_b->next;
		b_pos++;
	}
	return (best_move);
}

int	find_next_in_chunk(t_stack *a, int chunk_start, int chunk_end)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		best_distance;
	int		distance;

	pos = 0;
	best_pos = -1;
	best_distance = a->size;
	current = a->top;
	while (current)
	{
		if (current->value >= chunk_start && current->value <= chunk_end)
		{
			distance = calculate_distance(pos, a->size);
			if (distance < best_distance)
			{
				best_distance = distance;
				best_pos = pos;
			}
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}
