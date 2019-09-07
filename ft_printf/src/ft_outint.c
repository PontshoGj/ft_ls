#include "ft_printf.h"

void    outint(char s, va_list args, int space)
{
    int i;
    
    i = va_arg(args, int);
    if (space > 0)
    {
        givespace((int)ft_intlen(i), space);
        if (s == 'c')
        ft_putchar(i);
        else
        ft_putnbr(i);
    }
    if (space < 0)
    {
        if (s == 'c')
        ft_putchar(i);
        else
        ft_putnbr(i);
        givespace((int)ft_intlen(i), space);
    }    
}