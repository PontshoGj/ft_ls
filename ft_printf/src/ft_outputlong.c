#include "ft_printf.h"

void    ft_outputlong(va_list args, int space)
{
    (void)space;
    long long i;

    i = va_arg(args, long long);
    ft_putnbrlong(i);
}

void    ft_outputlonghex(va_list args, int space, char hex)
{
    (void)space;
    (void)hex;
    long long i;

    i = va_arg(args, long long);
    (void)i;
    ft_putstr(ft_longtoa_base(i, 16, hex));
}