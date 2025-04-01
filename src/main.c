#include "../push_swap.h"


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

int main(int argc, char **argv) {
    t_stack stack;
    t_stack stack_b;
    int *sorted_arr;

    if (argc < 2) return (0);
    init_stack(&stack);
    init_stack(&stack_b); 
    if (!parse_args(argc, argv, &stack)) {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }

    if (!is_sorted(&stack)) {
        sorted_arr = create_sorted_array(&stack);
        if (sorted_arr) {
            if (stack.size <= 3)
                sort_three(&stack);
            else if (stack.size <= 5)
                sort_five(&stack, &stack_b, sorted_arr);
            else
                radix_sort(&stack, &stack_b, sorted_arr);
            free(sorted_arr);
        }
    }
    stack_clear(&stack);
    stack_clear(&stack_b);
    return (0);
}