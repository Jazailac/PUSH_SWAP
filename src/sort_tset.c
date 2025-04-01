#include "../push_swap.h"

/* 
 * Get the maximum number of bits needed to represent the largest number in the stack
 */
static int get_max_bits(t_stack *stack)
{
    t_node *current;
    int max;
    int max_bits;
    
    if (!stack || !stack->top)
        return (0);
    
    current = stack->top;
    max = current->nbr;
    
    // Find the maximum number in the stack
    while (current)
    {
        if (current->nbr > max)
            max = current->nbr;
        current = current->next;
    }
    
    // Find how many bits are needed to represent the max number
    max_bits = 0;
    while (max >> max_bits)
        max_bits++;
        
    return (max_bits);
}

/*
 * Normalize the stack values to make them all positive
 * This is needed for the radix sort to work properly with negative numbers
 * Returns an array of indices that map stack positions to sorted array positions
 */
static int *normalize_stack(t_stack *stack, int *sorted_arr)
{
    t_node *current;
    int *index_arr;
    int i;
    int j;
    
    if (!stack || !sorted_arr)
        return (NULL);
        
    index_arr = malloc(stack->size * sizeof(int));
    if (!index_arr)
        return (NULL);
        
    // Map each number in the stack to its index in the sorted array
    current = stack->top;
    i = 0;
    while (current)
    {
        j = 0;
        while (j < stack->size)
        {
            if (current->nbr == sorted_arr[j])
            {
                index_arr[i] = j;
                break;
            }
            j++;
        }
        current = current->next;
        i++;
    }
    
    // Update stack values with normalized indices
    current = stack->top;
    i = 0;
    while (current)
    {
        current->nbr = index_arr[i];
        current = current->next;
        i++;
    }
    
    return (index_arr);
}

/*
 * Restore original values from the normalized values
 */
static void restore_original_values(t_stack *stack, int *sorted_arr, int *index_arr)
{
    t_node *current;
    int i;
    
    if (!stack || !sorted_arr || !index_arr)
        return;
        
    current = stack->top;
    i = 0;
    while (current)
    {
        current->nbr = sorted_arr[current->nbr];
        current = current->next;
        i++;
    }
    
    free(index_arr);
}

/*
 * Perform radix sort on the stack
 */
void radix_sort(t_stack *stack_a, t_stack *stack_b, int *sorted_arr)
{
    int max_bits;
    int size;
    int i;
    int j;
    int *index_arr;
    
    if (!stack_a || !stack_b || !sorted_arr)
        return;
        
    size = stack_a->size;
    if (size <= 1)
        return;
        
    // Normalize the stack values to handle negative numbers
    index_arr = normalize_stack(stack_a, sorted_arr);
    if (!index_arr)
        return;
        
    max_bits = get_max_bits(stack_a);
    
    // Sort for each bit position
    for (i = 0; i < max_bits; i++)
    {
        // Check each number in stack A
        for (j = 0; j < size; j++)
        {
            // If the bit at position i is 0, push to B
            if (((stack_a->top->nbr >> i) & 1) == 0)
                pb(stack_a, stack_b);
            // Otherwise, rotate A to check the next number
            else
                ra(stack_a);
        }
        
        // Push all numbers back from B to A
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
    
    // Restore original values
    restore_original_values(stack_a, sorted_arr, index_arr);
}