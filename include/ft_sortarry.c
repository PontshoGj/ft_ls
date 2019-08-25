#include "ft_ls.h"

char    **ft_sortarry(char **s)
{
    char *str;
    size_t i;
    size_t j;

    str = 0;
    i = 0;
    j = 0;
    while (s[j] != 0)
    {
        while (s[i] != 0)
        {
            if (ft_strcmp(s[j], s[i]) < 0)
            {
                str = s[j];
                s[j] = s[i];
                s[i] = str;
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (s);
}