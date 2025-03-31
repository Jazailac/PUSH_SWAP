#include "../push_swap.h"

void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

t_node *create_node(int num)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->nbr = num;
    new_node->next = NULL;
    return (new_node);
}

void stack_push(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void stack_append(t_stack *stack, t_node *node)
{
    t_node *current;

    if (!stack || !node)
        return;
    if (!stack->top) {
        stack->top = node;
    } else {
        current = stack->top;
        while (current->next) 
            current = current->next;
        current->next = node;
    }
    stack->size++;
}

void stack_clear(t_stack *stack)
{
    t_node *current;
    t_node *tmp;

    if (!stack) return;
    current = stack->top;
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    stack->top = NULL;
    stack->size = 0;
}