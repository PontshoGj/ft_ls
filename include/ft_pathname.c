#include "ft_ls.h"

char    *ft_pathname(char *str,char *dirname)
{
    char *s;
    char *temp;

    s = ft_strnew(1);
    temp = s;    
    s = ft_strjoin(s, str);
    if (s[ft_strlen(s)] != '/')
	    s = ft_strjoin(s, "/");
	s = ft_strjoin(s, dirname);
    //s = ft_strcat(s, "/");
    return (s);
}