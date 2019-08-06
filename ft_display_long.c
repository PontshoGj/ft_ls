#include "ft_ls.h"

void    ft_display_long(char *str)
{
    printf("%s", ft_permission(str));
    printf("%*.*s%d ", 4 - ft_intlen(ft_filelink(str)), 4 - ft_intlen(ft_filelink(str)), " ", ft_filelink(str));
    printf("%s%*.*s", ft_filename(str), 4 - ft_intlen(ft_strlen(ft_filename(str))), 4 - ft_intlen(ft_strlen(ft_filename(str))), " ");
    printf("%*.*s%d", 5 - ft_intlen(ft_filesize(str)), 5 - ft_intlen(ft_filesize(str)), " ", ft_filesize(str));
    printf("%*.*s%s", 3 - ft_intlen(ft_strlen(ft_filetimes(str))), 3 - ft_intlen(ft_strlen(ft_filetimes(str))), " ", ft_filetimes(str));
    printf(" %s\n", str);
}