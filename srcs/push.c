/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazailac <jazailac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:10:39 by jazailac          #+#    #+#             */
/*   Updated: 2025/04/09 21:10:40 by jazailac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void add_to_stack_end(t_stack *stack, int value)
{
    t_node *new_node;
    t_node *current;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = NULL;
    if (stack->top == NULL)
    {
        stack->top = new_node;
    }
    else
    {
        current = stack->top;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    stack->size++;
}

void pa(t_stack *a, t_stack *b)
{
    t_node *tmp;

    if (!a || !b || b->size == 0)
        return;
    push(a, b->top->value);
    tmp = b->top;
    b->top = b->top->next;
    free(tmp);
    b->size--;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    t_node *tmp;

    if (!a || !b || a->size == 0)
        return;
    push(b, a->top->value);
    tmp = a->top;
    a->top = a->top->next;
    free(tmp);
    a->size--;
    write(1, "pb\n", 3);
}