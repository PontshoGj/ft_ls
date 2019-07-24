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
char    *pathname(char *str,char *dirname)
{
    char *s;
    char *temp;

    s = ft_strnew(1);
    temp = s;    
	s = ft_strjoin(s, str);
    //ft_strdel(&temp);
	s = ft_strcat(s, "/");
	s = ft_strcat(s, dirname);
    s = ft_strcat(s, "/");
    return (s);
}
void  ft_display_recursive(const char *str)
{
    DIR *d;
    struct dirent *dir;
    t_list *ss;
    char *s;

    if (!(d = opendir(str)))
    {
        printf("Not dir\n");
        printf("%s", str);
        return ;
    }
    ss = ft_lstnew(0, 0);
    if (d)
    {
        
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] == '.')
                continue;
            if (dir->d_type == DT_DIR && ft_strcmp(dir->d_name , ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
                    ft_lstadd(&ss, newlst(pathname((char *)str, s)));
	        printf("%s\t\t\t\t", s);
        }
        closedir(d);
    }
    while (ss->next != 0)
    {
        printf("\n\n%s\n", ss->content);
        ft_display_recursive((const char *)ss->content);
	    ss = ss->next;
        if (ss->content == 0)
            return ;
    }
}

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
}