#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;
    
    if (!stack)
        return;
    
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->size = 0;
}

void free_array(char **array)
{
    int i;

    if (!array)
        return;
        
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
