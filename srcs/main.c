#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

t_stack *init_stack(void)
{
    t_stack *stack;
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void ll(void)
{
    system("leaks push_swap");
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    char **args;

    // atexit(ll);
    if (ac < 2)
        return (0);
    a = init_stack();
    if (!a)
        return (1);
    b = init_stack();
    if (!b)
    {
        free(a);
        return (1);
    }
    args = parse_args(ac, av);
    if (!args)
    {
        free(a);
        free(b);
        return (1);
    }
    if (!check_and_fill(a, args))
    {
        ft_putstr_fd("Error\n", 2);
        free_stack(a);
        free_stack(b);
        free_array(args);
        free(a);
        free(b);
        return (1);
    }
    if (!is_sorted(a))
    {
        if (a->size <= 5)
            sort_small(a, b);
        else
            sort_large(a, b);
    }
    free_array(args);
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    return (0);
}