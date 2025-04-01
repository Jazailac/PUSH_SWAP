#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **nbrs;

    if (ac < 2)
        return (0);
    
    nbrs = join_split_args(av, ac);
    if (!nbrs)
        return (ft_putstr_fd("Error\n", 2), 1);
    
    init_stack(&stack_a);
    init_stack(&stack_b);
    
    if (!parse_args(&stack_a, nbrs))
    {
        stack_clear(&stack_a);
        free_strs(nbrs);
        return (ft_putstr_fd("Error\n", 2), 1);
    }
    
    free_strs(nbrs);
    
    if (!is_sorted(&stack_a))
    {
        if (stack_a.size <= 3)
            sort_three(&stack_a);
        else if (stack_a.size <= 5)
            sort_five(&stack_a, &stack_b);
        else
            radix_sort(&stack_a, &stack_b);
    }
    
    stack_clear(&stack_a);
    stack_clear(&stack_b);
    return (0);
}