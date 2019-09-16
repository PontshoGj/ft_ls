#include "ft_ls.h"

char       ft_stb(struct stat filestat)
{
    if (filestat.st_mode & S_ISUID)
        return ('S');
    else if (filestat.st_mode & S_IXUSR)
        return ('x');
    return ('-');
}