#include "ft_ls.h"

char        *ftime(char *str)
{
    char *filetime;

    if (stat(str, &fileStat) < 0)
        return (0);
    filetime = ctime(&fileStat.st_mtime);
    return (filetime);
}
char        *strrea(char *str)
{
    char    *strhold;
    char    *temp;
    
    strhold = ft_strjoin(temp, str);
    temp = strhold;
    strhold = ft_strjoin(strhold, "  ");
    ft_strdel(&temp);
    return (strhold);
}
char        *ft_filetime(char *str)
{
    char    **strarray;
    char    **strtime;
    char    *temp;
    int     i[3];
    int     j;

    j = 0;
    strarray = ft_strsplit(ftime(str), ' ');
    strtime = ft_strsplit(strarray[3], ':');
    temp = ft_strjoin(strarray[0], strarray[1]);
    ft_strdel(strtime);
    i[0] = 2;
    i[1] = 1;
    while(j < 3)
    { //need to free 
        strtime = ft_strjoin(*strtime, strrea(strarray[i[j++]]));
    }
    strtime = ft_strjoin(*strtime, temp);
    ft_strdel(&temp);
    return (*strtime);
}