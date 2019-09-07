#include "ft_printf.h"

void    printxx(char *s, va_list args)
{
	(ft_strspn(&*s, "oxXu")) ? outuint(*s, args, 'a', 0, 0) : 0;
}