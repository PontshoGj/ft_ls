#include "ft_ls.h"

int ft_islink(char *s)
{
    struct stat kk;
    lstat(s, &kk);
    if (kk.st_mode & S_IFLNK)
        return 1;
    return (0);
}