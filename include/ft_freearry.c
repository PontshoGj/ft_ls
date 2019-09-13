#include "ft_ls.h"

void    ft_freearry(char **s)
{
    char **str;

    str =  s;
    while (*s)
        free(*s++);
    free(str);
}