/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:44 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:10:45 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    if (stack->size < 2)
        return;
    first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    last = stack->top;
    while (last->next)
        last = last->next;
    last->next = first;
}
void ra(t_stack *a)
{
    if (!a)
        return;
    rotate(a);
    write(1, "ra\n", 3);
}
void rb(t_stack *b)
{
    if (!b)
        return;
    rotate(b);
    write(1, "rb\n", 3);
}
void rr(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return;
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
