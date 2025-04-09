#include "push_swap.h"

void sort_two(t_stack *stack)
{
    if (stack->size < 2)
        return;
    if (stack->top->value > stack->top->next->value)
        sa(stack);
}

void sort_three(t_stack *stack)
{
    int a;
    int b;
    int c;
    
    if (stack->size < 3)
        return;
    a = stack->top->value;
    b = stack->top->next->value;
    c = stack->top->next->next->value;
    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}
int find_smallest_pos(t_stack *stack)
{
    int smallest_pos;
    int i;
    t_node *current;
    int smallest;

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

void sort_four(t_stack *a, t_stack *b)
{
    int smallest_pos;
    
    smallest_pos = find_smallest_pos(a);
    if (smallest_pos == 1)
        sa(a);
    else if (smallest_pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (smallest_pos == 3)
        rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_stack *a, t_stack *b)
{
    int smallest_pos;

    smallest_pos = find_smallest_pos(a);
    if (smallest_pos == 1)
        sa(a);
    else if (smallest_pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (smallest_pos == 3)
    {
        rra(a);
        rra(a);
    }
    else if (smallest_pos == 4)
        rra(a);
    pb(a, b);
    sort_four(a, b);
    pa(a, b);
}

void sort_small(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sort_two(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size == 4)
        sort_four(a, b);
    else if (a->size == 5)
        sort_five(a, b);
    else
        return ;
}