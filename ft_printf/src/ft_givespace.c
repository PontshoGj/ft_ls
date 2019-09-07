#include "ft_printf.h"

void    givespace(int i, int space)
{
    if (i < space)
    {
        space -= i;
        while (space-- > 0)
            ft_putchar(' ');
    }
}