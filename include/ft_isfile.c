#include "ft_ls.h"

int isfile(char *s)
{
    int i;
    struct stat kk;
    stat(s, &kk);
    i = (S_ISDIR(kk.st_mode)) ? 0 : 1;
    return (i);
}