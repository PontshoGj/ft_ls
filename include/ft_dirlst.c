#include "ft_ls.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

t_list *ft_dirlst(char *path)
{
    DIR *d;
    struct dirent *dir;
    t_list *newlst;
    t_list *add;

    newlst = ft_lstnew(0,0);
    add = 0;
    
    d = opendir(path);
    
    if (d)
    {
        
        while ((dir = readdir(d)) != 0)
        {
            add = ft_newlstelem((char *)dir->d_name);
            ft_lstadd(&newlst, add);
        }
        closedir(d);
        return (newlst);
    }
    //ft_lstsort(&newlst);
    //printf("%s\n", (char *)newlst->content);
    return (0);
}
