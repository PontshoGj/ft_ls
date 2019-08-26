#include "ft_ls.h"

void    ft_display_long(char *str)
{
    printf("%s", ft_permission(str));
    printf("%4d ", ft_filelink(str));
    printf("%4s", ft_filename(str));
    printf("%7d", ft_filesize(str));
    printf("%13s", ft_filetimes(str));
    printf(" %s\n", str);
}