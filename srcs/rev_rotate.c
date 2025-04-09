#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
    t_node *last;
    t_node *second_last;

    if (stack->size < 2)
        return;
    last = stack->top;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    if (!second_last)
        return;
    second_last->next = NULL;
    last->next = stack->top;
    stack->top = last;
}

void rra(t_stack *a)
{
    if (!a || a->size < 2)
        return;
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    if (!b || b->size < 2)
        return;
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    if (a && a->size >= 2)
        reverse_rotate(a);
    if (b && b->size >= 2)
        reverse_rotate(b);
    if ((a && a->size >= 2) || (b && b->size >= 2))
        write(1, "rrr\n", 4);
}