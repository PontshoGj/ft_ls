#include "ft_ls.h"

char        *ftime(char *str)
{
    char *filetime;

    if (stat(str, &fileStat) < 0)
        return (0);
    filetime = ctime(&fileStat.st_mtime);
    return (filetime);
}

char        *ft_filetimes(char *str)
{
    char    **strarray;
    char    *strtime;

    strarray = ft_strsplit(ftime(str), ' ');
    strtime = ft_strcat(strarray[2], " ");
    strtime = ft_strjoin(strtime, strarray[1]);
    strtime = ft_strcat(strtime, " ");
    strtime = ft_strjoin(strtime, ft_strsub(strarray[3], 0, 5));
    return (strtime);
}