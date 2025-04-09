#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int is_sorted(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}