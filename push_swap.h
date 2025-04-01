# ifndef PUSH_SWAP
#define PUSH_SWAP

#include "LIBFT/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
	int		nbr;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int		size;
}t_stack;


int is_valid_int(const char *str);
int parse_number(const char *str, int *num);
int check_dup(t_stack *stack, int num);
void stack_clear(t_stack *stack);
void stack_append(t_stack *stack, t_node *node);
void stack_push(t_stack *stack, t_node *node);
void init_stack(t_stack *stack);
t_node *create_node(int num);
char **split_arg(const char *str);
void radix_sort(t_stack *stack_a, t_stack *stack_b, int *sorted_arr);
void free_split(char **split);
int find_next_in_range(t_stack *a, int *sorted, int low, int high);
int parse_single_arg(char *arg, t_stack *stack);


void    sa(t_stack *stack);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rra(t_stack *stack);
void    rrb(t_stack *stack);

int *create_sorted_array(t_stack *a);
int is_sorted(t_stack *a) ;
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b, int *sorted);
void sort_large(t_stack *a, t_stack *b, int *sorted);
int find_max_position(t_stack *b);
int find_position(t_stack *stack, int target);
void rotate_to_top_a(t_stack *a, int pos);
void rotate_to_top_b(t_stack *b, int pos);
int calculate_chunk_size(int size);


#endif