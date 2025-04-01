#include "../push_swap.h"


void sort_three(t_stack *a)
{
    int first, second, third;
    
    if (a->size < 2)
        return;
    if (a->size == 2)
    {
        if (a->top->nbr > a->top->next->nbr)
            sa(a);
        return;
    }
    
    first = a->top->nbr;
    second = a->top->next->nbr;
    third = a->top->next->next->nbr;
    
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

int find_position(t_stack *stack, int target)
{
    int pos;
    t_node *node;
    
    pos = 0;
    node = stack->top;
    while (node)
    {
        if (node->nbr == target)
            return (pos);
        node = node->next;
        pos++;
    }
    return (-1);
}

int find_next_in_range(t_stack *a, int *sorted, int low, int high)
{
    t_node  *node;
    int     pos;

    if (low < 0)
        low = 0;
    if (high >= a->size)
        high = a->size - 1;
    
    node = a->top;
    pos = 0;
    while (node)
    {
        if (node->nbr >= sorted[low] && node->nbr <= sorted[high])
            return (pos);
        node = node->next;
        pos++;
    }
    return (-1);
}

void rotate_to_top_a(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        pos = a->size - pos;
        while (pos > 0)
        {
            rra(a);
            pos--;
        }
    }
}

void rotate_to_top_b(t_stack *b, int pos)
{
    if (pos <= b->size / 2)
    {
        while (pos > 0)
        {
            rb(b);
            pos--;
        }
    }
    else
    {
        pos = b->size - pos;
        while (pos > 0)
        {
            rrb(b);
            pos--;
        }
    }
}

int find_max_position(t_stack *b)
{
    t_node  *node;
    int     max;
    int     max_pos;
    int     pos;
    
    if (!b->top)
        return (-1);
    
    max = b->top->nbr;
    max_pos = 0;
    pos = 0;
    node = b->top;
    
    while (node)
    {
        if (node->nbr > max)
        {
            max = node->nbr;
            max_pos = pos;
        }
        node = node->next;
        pos++;
    }
    return (max_pos);
}

void sort_five(t_stack *a, t_stack *b, int *sorted)
{
    int smallest_pos;
    int second_smallest_pos;
    
    // Push the two smallest numbers to stack B
    smallest_pos = find_position(a, sorted[0]);
    rotate_to_top_a(a, smallest_pos);
    pb(a, b);
    
    if (a->size > 3)
    {
        second_smallest_pos = find_position(a, sorted[1]);
        rotate_to_top_a(a, second_smallest_pos);
        pb(a, b);
    }
    
    // Sort the remaining 3 elements in stack A
    sort_three(a);
    
    // Push elements back from B to A
    while (b->size > 0)
        pa(a, b);
}

int calculate_chunk_size(int size)
{
    if (size <= 100)
        return (15);
    return (30);
}

void sort_large(t_stack *a, t_stack *b, int *sorted)
{
    int chunk_size;
    int total_size;
    int chunks;
    int i;
    int pos;
    int start;
    int end;
    
    chunk_size = calculate_chunk_size(a->size);
    total_size = a->size;
    chunks = (total_size + chunk_size - 1) / chunk_size;
    
    // Push elements to stack B in chunks
    i = 0;
    while (i < chunks)
    {
        start = i * chunk_size;
        end = start + chunk_size - 1;
        if (end >= total_size)
            end = total_size - 1;
        
        // Push all elements in current chunk to B
        while ((pos = find_next_in_range(a, sorted, start, end)) != -1)
        {
            rotate_to_top_a(a, pos);
            pb(a, b);
        }
        i++;
    }
    
    // Push elements back from B to A in descending order
    while (b->size > 0)
    {
        pos = find_max_position(b);
        rotate_to_top_b(b, pos);
        pa(a, b);
    }
}
