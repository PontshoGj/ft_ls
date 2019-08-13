#include "ft_ls.c"

t_list      *newlsts(char *str)
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

char    *createpath(char *str, char *dirname)
{
    char *s;

    if (!str || !dirname)
        return (0);
    s = "";
    s = ft_strjoin(s, str);
	s = ft_strcat(s, "/");
	s = ft_strjoin(s, dirname);
    return (s);
}
t_list  *ft_rec_lst(const char *str, t_list **lst)
{
    DIR *d;
    struct dirent *dir;
    char *s;

    if (!(d = opendir(str)))
    {
        printf("Not dir\n");
        return 0;
    }
    if (lst == 0)
        lst = 0;
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] == '.')
                continue;
            if (dir->d_type == DT_DIR && ft_strcmp(s, ".") != 0 && ft_strcmp(s, "..") != 0)
            {
                s = createpath((char *)str, s);
                ft_lstadd(lst, newlsts(s));
                ft_rec_lst(s, lst);
                continue;
            }
        }
        closedir(d);
    }
    return (*lst);
}

int main(void)
{
    printf("s");
    t_list *s = ft_rec_lst(".", &s);
    while (s->next != 0)
    {
        printf("%s", (char *)s->content);
        s = s->next;
    }
    return 0;
}