#include    "ft_printf.h"

void    ft_printlong(char **s, va_list args)
{

    if (ft_strspn("lld", *s) == 3 || ft_strspn("lli", *s) == 3)
    {
        *s += 2; 
        ft_outputlong(args, 0);
    }
    else if (ft_strspn("llx", *s) == 3 || ft_strspn("llX", *s) == 3)
    {
        *s += 2;
        ft_outputlonghex(args, 0, *s[0]);
    }
}