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
            
            add = ft_newlstelem((char *)dir->d_name);
            ft_lstadd(&newlst, add);
            ft_putstr(newlst->content);
        }
        closedir(d);
    }
    ft_lstsort(&newlst);
    return (newlst);
}
