#include "ft_ls.h"

int isfile(char *s)
{
    struct stat kk;
    stat(s, &kk);
    return ((S_ISREG(kk.st_mode)) ? 1 : 0);
}