#include "ft_ls.h"

char    *ft_joinfiled(char *str)
{
    char *s;
    
    s = "";
    s = ft_strjoin(s, ft_permission(str));
    s = ft_strcat(s, "\t");
    s = ft_strjoin(s, ft_itoa(ft_filelink(str)));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, ft_filename(str));
    s = ft_strcat(s, "\t");
    s = ft_strjoin(s, ft_itoa(ft_filesize(str)));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, ft_filetimes(str));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, str);
    return (s);
}