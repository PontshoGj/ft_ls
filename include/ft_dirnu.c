#include "ft_ls.h"

size_t ft_dirnum(char *path)
{
    DIR *d;
    struct dirent *dir;
    size_t i;

    i = 0;
    d = opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != 0)
            i++;
        closedir(d);
    }
    return (i);
}