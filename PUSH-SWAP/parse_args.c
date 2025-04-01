// #include "LIBFT/libft.h"
// #include "push_swap.h"

// int is_valid_nbr(char *str)
// {
//     if (!str || !*str)
//         return (1);
//     if ((*str == '-' || *str == '+') && *(str + 1) == '0' && *(str + 2) != '\0')
//         return (1);
//     if (*str == '-' || *str == '+')
//         str++;
//     if (!*str)
//         return (1);
//     while (*str)
//     {
//         if (!ft_isdigit(*str))
//             return (1);
//         str++;
//     }
//     return (0);
// }

// char **join_slpit_args(char **av, int ac)
// {
//     char **nbrs;
//     char **tmp;
//     int i;
//     int j;
//     int k;

//     nbrs = malloc(ac * sizeof(char *));
//     if (!nbrs)
//         return (NULL);
//     i = 1;
//     j = 0;
//     while (i < ac - 1)
//     {
//         nbrs[j] = ft_strjoin(av[i], av[i + 1]);
//         i++;
//         j++;
//     }
//     nbrs[j] = NULL;
//     i = 0;
//     tmp = malloc(ac * sizeof(char *));
//     while (nbrs[i])
//     {
//         tmp = ft_split(nbrs[i], ' ');
//         if (!tmp)
//         {
//             free_strs(nbrs);
//             return (NULL);
//         }
//         i++;
//     }
//     return (free(nbrs), tmp);
// }

// int main(int ac, char **av)
// {
//     char **nbrs;
//     int i;

//     if (ac < 2)
//         return (1);
//     nbrs = join_slpit_args(av, ac);
//     if (!nbrs)
//         return (1);
//     i = 0;
//     while (nbrs[i])
//     {
//         if (is_valid_nbr(nbrs[i]))
//         {
//             free_strs(nbrs);
//             return (1);
//         }
//         printf("%s\n", nbrs[i]);
//         i++;
//     }
//     free_strs(nbrs);
//     return (0);
// }
/* parse.c */
#include "push_swap.h"

int is_valid_nbr(char *str)
{
    if (!str || !*str)
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

// void free_strs(char **strs)
// {
//     int i;
    
//     if (!strs)
//         return;
    
//     i = 0;
//     while (strs[i])
//     {
//         free(strs[i]);
//         i++;
//     }
//     free(strs);
// }

char **join_split_args(char **av, int ac)
{
    char *joined;
    char **result;
    int i;
    
    joined = ft_strdup("");
    if (!joined)
        return (NULL);
    
    for (i = 1; i < ac; i++)
    {
        char *tmp = joined;
        joined = ft_strjoin(joined, av[i]);
        free(tmp);
        if (!joined)
            return (NULL);
        
        if (i < ac - 1)
        {
            tmp = joined;
            joined = ft_strjoin(joined, " ");
            free(tmp);
            if (!joined)
                return (NULL);
        }
    }
    
    result = ft_split(joined, ' ');
    free(joined);
    
    return (result);
}

long ft_atol(const char *str)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}

int check_dup(t_stack *stack, int num)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        if (current->nbr == num)
            return (1);
        current = current->next;
    }
    return (0);
}

int parse_args(t_stack *stack_a, char **nbrs)
{
    int     i;
    long    num;
    t_node  *new_node;
    
    i = 0;
    while (nbrs[i])
    {
        if (!is_valid_nbr(nbrs[i]))
            return (0);
        
        num = ft_atol(nbrs[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (0);
        
        if (check_dup(stack_a, (int)num))
            return (0);
        
        new_node = create_node((int)num);
        if (!new_node)
            return (0);
        
        stack_append(stack_a, new_node);
        i++;
    }
    return (1);
}