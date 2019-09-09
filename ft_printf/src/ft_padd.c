#include "ft_printf.h"

void        padd(const char **str, va_list args)
{
    char *s;

    s = "";
    while (!(ft_strspn(&(*str[0]), "scdif.")))
    {
        s = ft_strjoin(s,&(*str[0]));
        *str += 1;
    }
    if (ft_strspn(&(*str[0]), "scdi"))
        prints(ft_atoi(s), (char *)(*str), args);
    else if (*str[0] == 'f')
        outdoub(*str[0], args, ft_atoi(s), 0);   
}