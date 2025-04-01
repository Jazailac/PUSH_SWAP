
#include "push_swap.h"

void sa(t_stack *stack)
{
    int temp;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    temp = stack->top->nbr;
    stack->top->nbr = stack->top->next->nbr;
    stack->top->next->nbr = temp;
    ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *stack)
{
    int temp;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    temp = stack->top->nbr;
    stack->top->nbr = stack->top->next->nbr;
    stack->top->next->nbr = temp;
    ft_putstr_fd("sb\n", 1);
}

void ss(t_stack *stack_a, t_stack *stack_b)
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

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *top_b;
    
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

void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node *top_a;
    
    if (!stack_a || !stack_b || !stack_a->top)
        return;
    
    top_a = stack_a->top;
    stack_a->top = top_a->next;
    stack_a->size--;
    
    top_a->next = stack_b->top;
    stack_b->top = top_a;
    stack_b->size++;
    
    ft_putstr_fd("pb\n", 1);
}

void ra(t_stack *stack)
{
    t_node *first;
    t_node *last;
    
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

void rb(t_stack *stack)
{
    t_node *first;
    t_node *last;
    
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

void rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *first;
    t_node *last;
    
    if (stack_a && stack_a->top && stack_a->top->next)
    {
        last = stack_a->top;
        while (last->next)
            last = last->next;
        
        first = stack_a->top;
        stack_a->top = first->next;
        first->next = NULL;
        last->next = first;
    }
    
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        last = stack_b->top;
        while (last->next)
            last = last->next;
        
        first = stack_b->top;
        stack_b->top = first->next;
        first->next = NULL;
        last->next = first;
    }
    
    ft_putstr_fd("rr\n", 1);
}

void rra(t_stack *stack)
{
    t_node *last;
    t_node *prev;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    
    last = stack->top;
    prev = NULL;
    
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
    
    ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack *stack)
{
    t_node *last;
    t_node *prev;
    
    if (!stack || !stack->top || !stack->top->next)
        return;
    
    last = stack->top;
    prev = NULL;
    
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
    
    ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *last;
    t_node *prev;
    
    if (stack_a && stack_a->top && stack_a->top->next)
    {
        last = stack_a->top;
        prev = NULL;
        
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        
        prev->next = NULL;
        last->next = stack_a->top;
        stack_a->top = last;
    }
    
    if (stack_b && stack_b->top && stack_b->top->next)
    {
        last = stack_b->top;
        prev = NULL;
        
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        
        prev->next = NULL;
        last->next = stack_b->top;
        stack_b->top = last;
    }
    
    ft_putstr_fd("rrr\n", 1);
}