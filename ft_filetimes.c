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
char        *ft_filetimes(char *str)
{
    char    **strarray;
    char    *strtime;
    char    *temp;
    int     i[3];
    int     j;

    j = 0;
    strarray = ft_strsplit(ftime(str), ' ');
    strtime = ft_strcat(strarray[2], " ");
    strtime = ft_strjoin(strtime, strarray[1]);
    strtime = ft_strcat(strtime, " ");
    strtime = ft_strjoin(strtime, ft_strsub(strarray[3], 0, 5));
    //printf("%s", strtime);
    //printf("%s", temp);
    //ft_strdel(strtime);
    /*i[0] = 2;
    i[1] = 1;
    while(j < 3)
    { //need to free 
        *strtime = ft_strjoin(*strtime, strrea(strarray[i[j++]]));
        //printf("%s", *strtime);
    }
    *strtime = ft_strjoin(*strtime, temp);
    temp = *strtime;
    //printf("%s", *strtime);
    ft_strdel(strtime);*/
    return (strtime);
}
/*
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        (void)argv;
        printf("%s", ft_filetime("ft_ls.c"));       
    }
    return (0);
}*/