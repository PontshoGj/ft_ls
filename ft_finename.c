#include "ft_ls.h"

char    *ft_filename(char *str)
{
    char *s;

    if (stat(str, &fileStat) < 0)
        return 0;
    struct group *grp;
    //struct *name;
    struct passwd *name;
    if ((name = getpwuid(fileStat.st_uid)) == 0)
        return 0;
    if ((grp = getgrgid(fileStat.st_gid)) == 0)
        return 0;
    s = ft_strjoin(name->pw_name, " ");
    s = ft_strcat(s, grp->gr_name);
    return (s);
}