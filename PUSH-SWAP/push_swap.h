/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
    int             nbr;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

/* Stack operations */
void    init_stack(t_stack *stack);
t_node  *create_node(int num);
void    stack_push(t_stack *stack, t_node *node);
void    stack_append(t_stack *stack, t_node *node);
void    stack_clear(t_stack *stack);
int     *create_sorted_array(t_stack *a);

/* Parsing functions */
int     is_valid_nbr(char *str);
char    **join_split_args(char **av, int ac);
void    free_strs(char **strs);
int     parse_args(t_stack *stack_a, char **nbrs);
long    ft_atol(const char *str);
int     check_dup(t_stack *stack, int num);

/* Operations */
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void    rrr(t_stack *stack_a, t_stack *stack_b);

/* Sorting algorithms */
int     is_sorted(t_stack *a);
void    sort_three(t_stack *stack);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void    radix_sort(t_stack *stack_a, t_stack *stack_b);

/* Utility functions */
void    stack_print(t_stack *stack); // For debugging

#endif





