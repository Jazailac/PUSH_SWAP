#include "push_swap.h"

int calculate_cost_a(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
        return (pos);
    return (a->size - pos);
}

int calculate_cost_b(t_stack *b, int pos)
{
    if (pos <= b->size / 2)
        return (pos);
    return (b->size - pos);
}

int find_min(t_stack *stack)
{
    t_node *current = stack->top;
    int min = INT_MAX;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

int find_max(t_stack *stack)
{
    t_node *current = stack->top;
    int max = INT_MIN;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}