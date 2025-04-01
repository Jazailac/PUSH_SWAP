#include "push_swap.h"

void free_strs(char **strs)
{
    int i;

    if (!strs)
        return;
    i = 0;
    while (strs[i])
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}