#include "ft_ls.h"

int isfile(char *s)
{
    struct stat kk;
    stat(s, &kk);
    return ((S_ISDIR(kk.st_mode)) ? 0 : 1);
}