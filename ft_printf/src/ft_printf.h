#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void    outint(char s, va_list args, int i);
void    outcharst(char s, va_list args, int i, int length);
void    outuint(char s, va_list args, char hex, int space, int length);
void    outdoub(char s, va_list args, int size, int z);
void    printstr(char s, va_list args);
void    printxx(char *s, va_list args);
void    prints(int i, char *str, va_list args);
void    printhandler( const char **str, va_list args);
void    padd(const char **str, va_list args);
void    paddfloat(const char **str, va_list args);
void    floatpre(const char **str, va_list args, int i);
void    givespace(int i, int space);
#endif
