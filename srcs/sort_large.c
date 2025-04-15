/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:46 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/13 01:45:26 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_position(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
}

static void	process_chunk(t_stack *a, t_stack *b, int start, int end)
{
	int	pos;

	pos = 0;
	while (pos != -1)
	{
		pos = find_next_in_chunk(a, start, end);
		move_to_position(a, pos);
		pb(a, b);
	}
}

static int	determine_chunks_count(int size)
{
	if (size <= 100)
		return (4);
	else if (size <= 500)
		return (11);
	return (20);
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int min, int max)
{
	long	range;
	int		chunk_size;
	int		chunks;
	int		i;
	int		start;

	chunks = determine_chunks_count(a->size);
	range = ((long)max - (long)min + 1);
	chunk_size = (range / chunks) + 1;
	i = 0;
	while (i < chunks)
	{
		start = min + (i * chunk_size);
		process_chunk(a, b, start, start + chunk_size - 1);
		i++;
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = find_min(a);
	max = find_max(a);
	push_chunks_to_b(a, b, min, max);
	while (b->size > 0)
		execute_best_move(a, b);
	final_rotate(a);
}
