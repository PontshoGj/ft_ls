#include "ft_ls.h"

char    ft_chksort(char *flag)
{
    if (ft_strspn("t", flag) == 1)
        return ('t');
    else if (ft_strspn("r", flag) == 1)
        return ('r');
    return (' ');
}