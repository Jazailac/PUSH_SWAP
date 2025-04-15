/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:47:15 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/10 22:42:29 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../LIBFT/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	struct s_node	*next;
	int				value;
}t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
}t_stack;

typedef struct s_move
{
	int	a_pos;
	int	b_pos;
	int	cost;
}t_move;

void	push(t_stack *stack, int value);
int		find_next_in_chunk(t_stack *a, int chunk_start, int chunk_end);
int		calculate_distance(int pos, int size);
void	free_array(char **array);
int		is_nbr(char *str);
int		find_min_pos(t_stack *stack);
t_stack	*init_stack(void);
int		has_dups(t_stack *stack, int num);
void	free_stack(t_stack *stack);
long	ft_atoi(char *str);
char	**parse_args(int ac, char **av);
int		check_and_fill(t_stack *stack, char **args);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	swap(t_stack *stack);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_large(t_stack *a, t_stack *b);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		calculate_cost_a(t_stack *a, int pos);
int		help_norm(char **args, t_stack *a, t_stack *b);
int		calculate_cost_b(t_stack *b, int pos);
t_move	find_best_move(t_stack *a, t_stack *b);
void	execute_best_move(t_stack *a, t_stack *b);
t_move	find_best_move_b_to_a(t_stack *a, t_stack *b);
void	execute_best_move_b_to_a(t_stack *a, t_stack *b);
void	final_rotate(t_stack *a);
void	last_free(char **args, t_stack *a, t_stack *b);
int		find_smallest_pos(t_stack *stack);

#endif