#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    const char *s;

    s = str;
    while (*str != 0)
    {
        if (*str == '%')
        {
            str++;
	        printhandler(&str, args);     
        }
        else
            ft_putchar(*str);
        str++;   
    }
    va_end(args);
    return (0);
    free((char *)s);
}
