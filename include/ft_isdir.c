#include "ft_ls.h"

int isdir(char *s)
{
    struct stat kk;
    stat(s, &kk);
    return ((S_ISDIR(kk.st_mode)) ? 1 : 0);
}