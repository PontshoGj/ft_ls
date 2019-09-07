#include "ft_printf.h"

void	printx(char s, char hex)
{
	if (hex != 0 && s == 'x')
		ft_putstr("0x");
	else if (hex != 0 && s == 'X')
		ft_putstr("0X");
	else if (hex != 0 && s == 'o')
		ft_putstr("0");
}

void    outuint(char s, va_list args, char hex, int space,int length)
{
    char *str;
    unsigned int i;
    int j;

    i = va_arg(args, unsigned int);
    str = (s == 'X' || s == 'x') ? ft_itoa_base((int)i, 16, s) : ft_itoa_base((int)i, 8, s);
    j = (int)ft_strlen(str);
    if (length == 0)
        length = (int)ft_strlen(str);
    else
        space += (int)ft_strlen(str) - length;
    if (space != 0)
    {
        if (space > 0)
        {
            givespace(j, space);
            if (i != 0)
    	        printx(s, hex);
            ft_putstrc(str, length);
        }
        else if (space < 0)
        {
            if (i != 0)
    	        printx(s, hex);
            ft_putstrc(str, length);
            givespace(j, space * -1);
        }
    }
    if (i != 0)
    	printx(s, hex);
    ft_putstr(str);
}
