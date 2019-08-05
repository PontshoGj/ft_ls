#include "ft_ls.h"

t_list *ft_dirlst(char *path)
{
    DIR *d;
    struct dirent *dir;
    t_list *newlst;
    t_list *add;

    newlst = 0;
    add = 0;
    d = opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            add = ft_lstnew((char *)dir->d_name, ft_strlen((const char *)dir->d_name));
            ft_lstadd(&newlst, add);
        }
        closedir(d);
    }
    ft_lstsort(&newlst);
    return (newlst);
}