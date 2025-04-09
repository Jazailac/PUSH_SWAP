#include "../LIBFT/libft.h"
#include "push_swap.h"
#include <limits.h>

int is_nbr(char *str)
{
    int i;

    i = 0;
    if (!str || !*str)
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '0' && str[i + 1] != '\0')
        return (0);
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int has_duplicates(t_stack *stack, int num)
{
    t_node *current;
     
    current = stack->top;
    while (current)
    {
        if (current->value == num)
            return (1);
        current = current->next;
    }
    return (0);
}

char **parse_args(int ac, char **av)
{
    char *str;
    char *tmp;
    char **args;
    int i;
    
    str = ft_strdup("");
    i = 1;
    while (i < ac)
    {
        tmp = str;
        str = ft_strjoin(str, av[i]);
        free(tmp);
        if (!str)
            return (NULL);
        if (i < ac - 1)
        {
            tmp = str;
            str = ft_strjoin(str, " ");
            free(tmp);
            if (!str)
                return (NULL);
        }
        i++;
    }
    args = ft_split(str, ' ');
    free(str);
    return (args);
}

long ft_atol(char *str)
{
    int i;
    int sign;
    long result;
    
    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int check_and_fill(t_stack *stack, char **args)
{
    int i;
    long num;
    int count;

    count = 0;
    while (args[count])
        count++;
    i = count - 1;
    while (i >= 0)
    {
        if (!is_nbr(args[i]))
            return (0);
        num = ft_atol(args[i]);
        if ((num > INT_MAX || num < INT_MIN))
            return (0);
        if (has_duplicates(stack, (int)num))
            return (0);
        // add_to_stack_end(stack, (int)num);
        push(stack, num);
        i--;
    }
    return (1);
}