#include "ft_ls.h"

void    ft_display_all(char *str, char *flag, char *path)
{
    static int i;

    if (!i)
        i = 0;
    else if (i == 5 && ft_strspn("R", flag) == 0)
    {
        i = 0;
        printf("\n");
    }
    i++;
    if (ft_strspn("l", flag) == 1)
        ft_display_long(ft_pathname(path, str));
    else
        printf("%-24s", str);
}