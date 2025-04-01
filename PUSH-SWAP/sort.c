#include "push_swap.h"

int is_sorted(t_stack *a)
{
    t_node *node;
    
    node = a->top;
    while (node && node->next)
    {
        if (node->nbr > node->next->nbr)
            return (0);
        node = node->next;
    }
    return (1);
}

void sort_three(t_stack *stack)
{
    int a;
    int b;
    int c;
    
    if (stack->size < 2)
        return;
    
    if (stack->size == 2)
    {
        if (stack->top->nbr > stack->top->next->nbr)
            sa(stack);
        return;
    }
    
    a = stack->top->nbr;
    b = stack->top->next->nbr;
    c = stack->top->next->next->nbr;
    
    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int *sorted;
    int median;
    int i;
    
    if (stack_a->size <= 3)
    {
        sort_three(stack_a);
        return;
    }
    
    sorted = create_sorted_array(stack_a);
    if (!sorted)
        return;
    
    median = sorted[stack_a->size / 2];
    free(sorted);
    
    // Push smaller elements to stack B
    i = 0;
    while (i < stack_a->size && stack_b->size < 2)
    {
        if (stack_a->top->nbr < median)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    
    // Sort stack A (3 elements)
    sort_three(stack_a);
    
    // Sort stack B (2 elements)
    if (stack_b->size == 2 && stack_b->top->nbr < stack_b->top->next->nbr)
        sb(stack_b);
    
    // Push everything back to A
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits;
    int i;
    int j;
    int size;
    int *sorted;
    int min;
    int max;
    
    // Find the min and max values to normalize
    sorted = create_sorted_array(stack_a);
    if (!sorted)
        return;
    
    min = sorted[0];
    max = sorted[stack_a->size - 1];
    free(sorted);
    
    // Calculate range to find max bits needed
    max = max - min;
    
    // Calculate max bits needed
    max_bits = 0;
    while ((max >> max_bits) > 0)
        max_bits++;
    
    size = stack_a->size;
    
    // Perform radix sort using bit operations
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            // Subtract min to normalize
            int normalized = stack_a->top->nbr - min;
            
            // If bit at position i is 0, push to B
            if ((normalized >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        
        // Push all from B back to A
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
}

/* debug.c */
#include "push_swap.h"

void stack_print(t_stack *stack)
{
    t_node *current;

    if (!stack)
    {
        printf("(null stack)\n");
        return;
    }
    
    current = stack->top;
    printf("Stack [%d elements]: ", stack->size);
    
    while (current)
    {
        printf("%d", current->nbr);
        current = current->next;
        if (current)
            printf(" -> ");
    }
    
    printf("\n");
}