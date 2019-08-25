#include "ft_ls.h"

char    **ft_arrydirlist(char *p)
{
    DIR *d;
    struct dirent *dir;
    size_t i;
    char **s;

    i = 0;
    if (!(s = (char **)malloc(sizeof(char *) * ft_dirnum(p))))
        return (0);
    d = opendir(p);
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            //if (ft_strcmp(s[i], ".") != 0 && ft_strcmp(s[i], "..") != 0)
                s[i++] = ft_strdup(dir->d_name);   
        }
        closedir(d);
        s[i] = NULL;
        return (ft_sortarry(s));
    }
    else
        return 0;
}