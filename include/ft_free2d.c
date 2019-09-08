#include "ft_ls.h"

void    ft_free2d(char **s)
{
    while (*s)
        free(*s++);
}