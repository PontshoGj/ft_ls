#include "ft_ls.h"

char    *ft_pathname(char *str,char *dirname)
{
    char *s;
    char *temp;

    s = ft_strnew(1);
    temp = s;    
    s = ft_strjoin(s, str);
    if (s[ft_strlen(s) - 1] != '/')
	    s = ft_strcat(s, "/");
	s = ft_strcat(s, dirname);
    s = ft_strcat(s, "/");
    return (s);
}