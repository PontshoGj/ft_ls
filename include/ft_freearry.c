#include "ft_ls.h"

void    ft_freearry(char **s)
{
    while (*s)
        free(*s++);
}