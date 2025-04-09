/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:46 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:10:47 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//more understanding of why 

int find_target_position(t_stack *a, int value)
{
    t_node *current;
    int i ;
    int min_pos;
    int min_value;
    int closest_bigger;
    int target_pos;

    closest_bigger = INT_MAX;
    min_value = INT_MAX;
    current = a->top;
    target_pos = 0;
    min_pos = 0;
    i = 0;
    while (current)
    {
        if (current->value <= min_value)
        {
            min_value = current->value;
            min_pos = i;
        }
        if (current->value > value && current->value <= closest_bigger)
        {
            closest_bigger = current->value;
            target_pos = i;
        }
        current = current->next;
        i++;
    }
    if (closest_bigger == INT_MAX)
        return (min_pos);
    return (target_pos);
}
t_move find_best_move(t_stack *a, t_stack *b)
{
    t_node *current_b;
    t_move best_move;
    int b_pos;
    int a_pos;
    int cost;
    
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

int find_next_in_chunk(t_stack *a, int chunk_start, int chunk_end)
{
    t_node *current ;
    int pos = 0;
    int best_pos = -1;
    int best_distance = a->size;
    int distance;
    
    current = a->top;
    while (current)
    {
        if (current->value >= chunk_start && current->value <= chunk_end)
        {
            if (pos <= a->size / 2)
                distance = pos;
            else
                distance = a->size - pos;
            if (distance < best_distance)
            {
                best_distance = distance;
                best_pos = pos;
            }
        }
        current = current->next;
        pos++;
    }
    return best_pos;
}

void push_chunks_to_b(t_stack *a, t_stack *b, int chunks, int min, int max)
{
    long range ;
    int chunk_size ;
    int i;
    int pos;
    
    range = ((long)max - (long)min + 1);
    chunk_size = (range / chunks) + 1;
    i = 0;
    while (i < chunks)
    {
        int start = min + (i * chunk_size);
        int end = start + chunk_size - 1;
        
        while ((pos = find_next_in_chunk(a, start, end)) != -1)
        {
            if (pos <= a->size / 2)
                while (pos-- > 0)
                    ra(a);
            else
                while (pos++ < a->size) 
                    rra(a);
            pb(a, b);
        }
        i++;
    }
}

void sort_large(t_stack *a, t_stack *b)
{
    int min;
    min = find_min(a);
    int max;
    max = find_max(a);
    int chunks;

    if (a->size <= 100) chunks = 4;
    else if (a->size <= 500) chunks = 10;
    else chunks = 20;

    push_chunks_to_b(a, b, chunks, min, max);
    
    while (b->size > 0)
        execute_best_move(a, b);
    
    final_rotate(a);
}