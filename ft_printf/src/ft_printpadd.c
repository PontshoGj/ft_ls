#include "ft_printf.h"

void    prints(int i, char *str, va_list args)
{
    (ft_strspn(&(*str), "dic")) ? outint(*str, args, i) : 0;
    (*str == 's') ? outcharst(*str, args, i, 0) : 0;
}