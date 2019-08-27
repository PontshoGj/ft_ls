#include "ft_ls.h"

char    **ft_sorttype(char **s, char type, char *path)
{
    if (type == 'r')
        return (ft_sortarryr(s));
    else if (type == 't')
        return (ft_sortarryt(s, path));
    return (ft_sortarry(s));
}

char    **ft_arrydirlist(char *p)
{
    DIR *d;
    struct dirent *dir;
    size_t i;
    char **s;

    i = 0;
    if (!(s = (char **)malloc(sizeof(char *) * (ft_dirnum(p) + 1))))
        return (0);
    d = opendir(p);
    if (d)
    {
        while ((dir = readdir(d)))
        {
            if (ft_strcmp(dir->d_name, ".") == 0)
                s[i++]  =  ft_strdup(".");
            else
                s[i++] = ft_strdup((const char *)dir->d_name);    
        }
        closedir(d);
        s[i] = 0;
        return (ft_sorttype(s, ' ', p));
    }
    return (0);
}