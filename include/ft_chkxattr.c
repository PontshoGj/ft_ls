#include "ft_ls.h"

char    chkxattr(char *path)
{
    size_t retvalue;

    retvalue = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    if (retvalue > 0)
        return ('@');
    //else if ()
    //    return ('+');
    return (' ');
}