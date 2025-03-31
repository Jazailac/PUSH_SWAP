#include "../push_swap.h"

int find_next_in_range(t_stack *a, int *sorted, int low, int high)
{
    t_node  *node = a->top;
    int     pos = 0;

    while (node != NULL) {
        if (node->nbr >= sorted[low] && node->nbr <= sorted[high])
            return (pos);
        node = node->next;
        pos++;
    }
    return (-1);
}




int parse_single_arg(char *arg, t_stack *stack)
{
    t_node *new_node;
    char **split;
    int i;
    int num;
    
    split = split_arg(arg);
    if (!split)
        return (0);
    i = 0;
    while (split[i])
    {
        if (!parse_number(split[i], &num))
        {
            free_split(split);
            return (0);
        }
        if (check_dup(stack, num))
        {
            free_split(split);
            return (0);
        }
        new_node = create_node(num);
        if (!new_node)
        {
            free_split(split);
            return (0);
        }
        stack_append(stack, new_node);
        i++;
    }
    free_split(split);
    return (1);
}



int parse_args(int argc, char **argv, t_stack *stack)
{
    int i;
    
    init_stack(stack);
    i = 1;
    while (i < argc)
    {
        if (!parse_single_arg(argv[i], stack))
            return (stack_clear(stack), 0);
        i++;
    }
    return (1);
}

void    stack_print(t_stack *stack)
{
    t_node  *current;

    if (!stack)
    {
        printf("(null stack)\n");
        return ;
    }
    current = stack->top;
    printf("Stack [%d elements]: ", stack->size);
    while (current)
    {
        printf("%d", current->nbr);
        current = current->next;
        if (current)
            printf(" -> ");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack stack;
    t_stack stack_b;

    if (argc < 2) return (0);
    if (!parse_args(argc, argv, &stack)) {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    stack_print(&stack);
    return (0);
}