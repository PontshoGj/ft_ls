#include "ft_ls.h"

int     ft_filelink(char *str)
{
    int link;
    
    if (stat(str, &fileStat) < 0)
        return (1);
    link = fileStat.st_nlink;
    return (link);
}