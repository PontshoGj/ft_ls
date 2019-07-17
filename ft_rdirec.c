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

void  dirlist(const char *str, const char *string)
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
        //printf("%s\n", str);
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] == '.')
                continue;
            if (dir->d_type == DT_DIR && ft_strcmp(s , ".") != 0 && ft_strcmp(s, "..") != 0)
                ft_lstadd(&ss, newlst(s));
            //printf("%s\t", dir->d_name);
        }
        closedir(d);
    }
    if (ss->next != 0)
        printf("\n\n");
    while (ss->next != 0)
    {
        printf("\n%s\n", string);
        s = (char *)str;
        if (ft_strcmp(str, "."))
        {
            s = ft_strcat(s, "/");
            s = ft_strcat(s, ss->content);
        }
        else
            s = ss->content;
        dirlist((const char *)s, string);
        //str = (char *)str2;
        ss = ss->next;
    }
}

int main(int argc, char **argv) {
    if (argc == 1)
        dirlist(".", "a");
    else
    {
        (void)argc;
        dirlist(argv[1], argv[1]);
    }
    printf("\n");
    return 0;
}