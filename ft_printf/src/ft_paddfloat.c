#include "ft_printf.h"

void    paddfloat(const char **str, va_list args)
{
    char *s;

    s = "";
    if (*str[0] == '*')
    {
        *str += 1;
        floatpre(str, args, va_arg(args, int));
    }
    else if (ft_isdigit(*str[0]))
    {
        while (!(ft_strspn(&(*str[0]), "fF")))
        {
            s = ft_strjoin(s, &(*str[0]));
            *str += 1;
        }
        floatpre(str, args, ft_atoi(s));
    }
}
