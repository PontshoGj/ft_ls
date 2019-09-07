#include "ft_printf.h"

void    printstr(char s, va_list args)
{
    (ft_strspn(&s , "dic")) ? outint(s, args, 0) : 0;
    (s == 's') ? outcharst(s, args, 0, 0) : 0;
    (ft_strspn(&s , "oxXu")) ? outuint(s, args, 0, 0, 0) : 0;
    (ft_strspn(&s, "fFeEaAgG")) ? outdoub(s, args, 0, 0) : 0;
}