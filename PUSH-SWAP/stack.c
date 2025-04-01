/* stack.c */
#include "push_swap.h"

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

int *create_sorted_array(t_stack *a)
{
    int *arr;
    t_node *node;
    int i, j, temp;

    if (!a || a->size == 0)
        return (NULL);
    arr = malloc(a->size * sizeof(int));
    if (!arr)
        return (NULL);
    node = a->top;
    for (i = 0; node; i++, node = node->next)
        arr[i] = node->nbr;
    for (i = 0; i < a->size - 1; i++)
        for (j = 0; j < a->size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                temp = arr[j], arr[j] = arr[j + 1], arr[j + 1] = temp;
    return (arr);
}
