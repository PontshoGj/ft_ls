
#include "ft_printf.h"

void    outcharst(char s, va_list args, int space ,int length)
{
    int i;
    char *str; 
    
    (void)s;
    str = va_arg(args, char *);
    i = ft_strlen(str);
    if (length == 0)
        length = (int)ft_strlen(str);
    else
        space += (int)ft_strlen(str) - length;
    if (space != 0)
    {
        if (space > 0)
        {
            givespace(i, space);
            ft_putstrc(str, length);
        }
        else if (space < 0)
        {
            ft_putstrc(str, length);
            givespace(i, space * -1);
        }
        return;
    }
    ft_putstr(str);
}