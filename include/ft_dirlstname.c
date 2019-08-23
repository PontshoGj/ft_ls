#include "ft_ls.h"

t_list *ft_dirlstname(char *path)
{
    DIR *d;
    struct dirent *dir;
    t_list *newlst;
    t_list *add;
    char *str;

    newlst = ft_lstnew(0,0);
    add = 0;
    
    d = opendir(path);
    str = 0;
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            str = (char *)dir->d_name;
            if (isdir(ft_pathname(path, str)) && str[0] != '.')
            {
                //printf("--->%s\n", (char *)dir->d_name);
                add = ft_newlstelem((char *)dir->d_name);
                ft_lstadd(&newlst, add);   
            }
        }
        closedir(d);
        //ft_lstsort(&newlst);
        return (newlst);
    }
    return (0);
}