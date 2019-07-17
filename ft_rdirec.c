#include "ft_ls.h"

t_list      *newlst(char *str)
{
    t_list	*elem;
	t_list	*adds;

	if (!(elem = ft_lstnew(str, sizeof(str))))
    {
        printf("Error");
		return (0);
    }
	if (!(adds = ft_lstnew(str, sizeof(str))))
    {
        printf("Error");
		return (0);
    }
	ft_lstadd(&elem, adds);
    return (elem);
}

void  dirlist(char *str)
{
    DIR *d;
    struct dirent *dir;
    t_list *ss;
    char *s;

    d = opendir(str);
    ss = ft_lstnew(0, 0);
    if (d)
    {
        printf("%s\n", str);
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] == '.')
                continue;
            if (dir->d_type == DT_DIR && ft_strcmp(s , ".") != 0 && ft_strcmp(s, "..") != 0)
                ft_lstadd(&ss, newlst(dir->d_name));
            printf("%s\t", dir->d_name);
        }
        closedir(d);
    }
    if (ss->next != 0)
        printf("\n\n");
    while (ss->next != 0)
    {
        dirlist(ss->content);
        ss = ss->next;
    }
}

int main(void) {
    dirlist(".");
    return 0;
}