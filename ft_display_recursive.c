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
char *createpath(char *path, char *dirname)
{
    char *s;

    s = "";    
	s = ft_strjoin(s, path);
	s = ft_strcat(s, "/");
	s = ft_strjoin(s, dirname);
    return (s);
}
t_list  *ft_display_recursive(const char *str)
{
    DIR *d;
    struct dirent *dir;
    t_list *ss;
    char *s;

    if (!(d = opendir(str)))
    {
        printf("Not dir\n");
        return 0;
    }
    //ss = ft_lstnew(0, 0);
    ss = 0;
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            s = createpath((char *)str, s);
            if (dir->d_type == DT_DIR)
            {
	            ss = ft_display_recursive(s);
	            ft_lstadd(&ss, newlst(s));
            }
        }
        closedir(d);
    }
    return (ss);
}
/*
int main(int argc, char **argv) {
    if (argc == 1)
        ft_display_recursive(".");
    else
    {
        (void)argc;
        ft_display_recursive(argv[1]);
    }
    printf("\n");
    return 0;
}*/
int main()
{
    t_list	*elem = ft_display_recursive(".");
    while (elem)
	{
		ft_putendl(elem->content);
		elem = elem->next;
	}
    return (0);
}