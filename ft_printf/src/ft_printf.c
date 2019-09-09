#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);

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
}
