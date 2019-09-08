#include "ft_ls.h"

void  block(char *str, char *flag)
{
    char **arrlist;
    int i;
    long long filetime;
	struct stat fileStat;

	i = 0;
    filetime = 0;
    arrlist = ft_arrydirlist(str, ft_chksort(flag));
    while (arrlist[i] != 0)
    {
        if (lstat(ft_pathname(str, arrlist[i]), &fileStat) < 0)
		    return ;
        if (ft_strspn("a", flag) == 1)
            filetime += fileStat.st_blocks;
        else if (arrlist[i][0] != '.')
            filetime += fileStat.st_blocks;
        i++;
    }
    ft_free2d(arrlist);
    ft_printf("total %lld\n", filetime);
}

void    ft_longdisplay(char *path, char *flag)
{
    char **arrlist;
    int i;

	i = 0;
    block(path, flag);
    arrlist = ft_arrydirlist(path, ft_chksort(flag));
    while (arrlist[i] != 0)
    {
        if (ft_strspn("a", flag) == 1)
            ft_display_long(arrlist[i], path);
        else if (arrlist[i][0] != '.')
            ft_display_long(arrlist[i], path);
        //free(arrlist[i]);
        i++;
    }
    //ft_free2d(arrlist);
}