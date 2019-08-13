#include "ft_ls.h"

char    *ft_filename(char *str)
{
    char *s;
    int i;

    if (stat(str, &fileStat) < 0)
        return 0;
    struct group *grp;
    struct passwd *name;
    if ((name = getpwuid(fileStat.st_uid)) == 0)
        return 0;
    if ((grp = getgrgid(fileStat.st_gid)) == 0)
        return 0;
    i = ft_strlen(name->pw_name) + ft_strlen(grp->gr_name) + 1;
    s = (char *)malloc(sizeof(char) * i);
    s[i] = 0;
    s = ft_strjoin(name->pw_name, "  ");
    s = ft_strcat(s, grp->gr_name);
    
    return (s);
}