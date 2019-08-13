#include "ft_ls.h"

int isdir(char *s)
{
    int i;
    struct stat kk;
    stat(s, &kk);
    i = (S_ISDIR(kk.st_mode)) ? 1 : 0;
    return (i);
}