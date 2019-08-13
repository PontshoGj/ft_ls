#include "ft_ls.h"

int     ft_filesize(char *str)
{
    int filesize;

    if (stat(str, &fileStat) < 0)
        return 1;
    filesize = fileStat.st_size;
    return (filesize);
}