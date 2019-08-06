#include "ft_ls.h"

void    ft_display_long(char *str)
{
    printf("%s   ", ft_permission(str));
    printf("%d ", ft_filelink(str));
    printf("%s   ", ft_filename(str));
    printf("%d ", ft_filesize(str));
    printf("%s ", ft_filetimes(str));
    printf("%s\n", str);
}