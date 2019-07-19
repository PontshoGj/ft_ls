#include "ft_ls.h"

t_list      *newlst(char *str)
{
    t_list	*elem;
	t_list	*adds;

	if (!(elem = ft_lstnew(str, ft_strlen(str))))
    {
        printf("Error");
		return (0);
    }
	if (!(adds = ft_lstnew(str, ft_strlen(str))))
    {
        printf("Error");
		return (0);
    }
	ft_lstadd(&elem, adds);
    return (elem);
}

void  dirlist(const char *str)
{
    DIR *d;
    struct dirent *dir;
    t_list *ss;
    char *s;

    if (!(d = opendir(str)))
    {
        printf("Not dir\n");
        return ;
    }
    ss = ft_lstnew(0, 0);
    if (d)
    {
        printf("%s\n", str);
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] == '.')
                continue;
            if (dir->d_type == DT_DIR && ft_strcmp(dir->d_name , ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
            {
	    s = "";    
	    s = ft_strjoin(s, str);
	    s = ft_strcat(s, "/");
	    s = ft_strjoin(s, dir->d_name);
	    ft_lstadd(&ss, newlst(s));
	    }
	    printf("%s\t", dir->d_name);
        }
        closedir(d);
    }
    printf("\n\n");
    while (ss->next != 0)
    {
        dirlist((const char *)ss->content);
//        printf("\n");
	ss = ss->next;
    }
}

