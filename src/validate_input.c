#include "../push_swap.h"

int is_valid_int(const char *str)
{
    if (!str || !*str)
        return (0);
    if (*str == '0' && *(str + 1) != '\0')
        return (0);
    if ((*str == '-' || *str == '+') && *(str + 1) == '0' && *(str + 2) != '\0')
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return (0);   
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

char **split_arg(const char *str)
{
    char **nbrs;

    nbrs = ft_split(str, ' ');
    if (!nbrs)
        return (NULL);
    return (nbrs);
}

static int ft_atol(const char *str, long *result)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        res = res * 10 + (*str - '0');
        if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
            return (0);
        str++;
    }
    *result = res * sign;
    return (1);
}

int parse_number(const char *str, int *num)
{
    long result;
    
    if (!is_valid_int(str))
        return (0);
    if (!ft_atol(str, &result))
        return (0);
    *num = (int)result;
    return (1);
}

int check_dup(t_stack *stack, int num)
{
    t_node *current;

    if (!stack)
        return (0);
    current = stack->top;
    while (current)
    {
        if (current->nbr == num)
            return (1);
        current = current->next;
    }
    return (0);
}

void free_split(char **split)
{
    int i;
    
    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}