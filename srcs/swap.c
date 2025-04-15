/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:50 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:54:25 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
