#include "../push_swap.h"

void    sa(t_stack *stack)
{
    int temp;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    temp = stack->top->nbr;
    stack->top->nbr = stack->top->next->nbr;
    stack->top->next->nbr = temp;
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack *stack)
{
    int temp;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    temp = stack->top->nbr;
    stack->top->nbr = stack->top->next->nbr;
    stack->top->next->nbr = temp;
    ft_putstr_fd("sb\n", 1);
}

void    ra(t_stack *stack)
{
    t_node  *first;
    t_node  *last;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last = stack->top;
    while (last->next)
        last = last->next;    
    first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack *stack)
{
    t_node  *first;
    t_node  *last;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last = stack->top;
    while (last->next)
        last = last->next;
    first = stack->top;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    ft_putstr_fd("rb\n", 1);
}
void    ss(t_stack *stack_a, t_stack *stack_b)
{
    int temp;
    if (stack_a && stack_a->top && stack_a->top->next)
    {
        temp = stack_a->top->nbr;
        stack_a->top->nbr = stack_a->top->next->nbr;
        stack_a->top->next->nbr = temp;
    }
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        temp = stack_b->top->nbr;
        stack_b->top->nbr = stack_b->top->next->nbr;
        stack_b->top->next->nbr = temp;
    }
    ft_putstr_fd("ss\n", 1);
}
void    rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *first_a;
    t_node  *last_a;
    t_node  *first_b;
    t_node  *last_b;
    if (stack_a && stack_a->top && stack_a->top->next)
    {
        last_a = stack_a->top;
        while (last_a->next)
            last_a = last_a->next;
        
        first_a = stack_a->top;
        stack_a->top = first_a->next;
        first_a->next = NULL;
        last_a->next = first_a;
    }
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        last_b = stack_b->top;
        while (last_b->next)
            last_b = last_b->next;
        
        first_b = stack_b->top;
        stack_b->top = first_b->next;
        first_b->next = NULL;
        last_b->next = first_b;
    }
    
    ft_putstr_fd("rr\n", 1);
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *top_b;
    
    if (!stack_a || !stack_b || !stack_b->top)
        return;
    top_b = stack_b->top;
    stack_b->top = top_b->next;
    stack_b->size--;
    top_b->next = stack_a->top;
    stack_a->top = top_b;
    stack_a->size++;
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *top_a;
    
    if (!stack_a || !stack_b || !stack_a->top)
        return;
    
    // Remove top element from stack a
    top_a = stack_a->top;
    stack_a->top = top_a->next;
    stack_a->size--;
    
    // Add element to top of stack b
    top_a->next = stack_b->top;
    stack_b->top = top_a;
    stack_b->size++;
    
    ft_putstr_fd("pb\n", 1);
}