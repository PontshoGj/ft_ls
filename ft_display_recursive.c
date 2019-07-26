#include "ft_ls.h"

t_list      *newlst(char *str)
{
    t_list	*elem;
	//t_list	*adds;

	if (!(elem = ft_lstnew((const char *)str, ft_strlen(str))))
    {
        printf("Error");
		return (0);
    }
	//if (!(adds = ft_lstnew((const char *)str, ft_strlen(str))))
    //{
    //    printf("Error");
	//	return (0);
    //}
    printf("%s\n", elem->content);
	//ft_lstadd(&elem, adds);
 
    return (elem);
}
char    *pathname(char *str,char *dirname, char c)
{
    char *s;
    char *temp;

    s = ft_strnew(1);
    temp = s;    
    s = ft_strjoin(s, str);
    //ft_strdel(&temp);
    if (ft_isalpha(s[ft_strlen(s)]) == 0)
    if (c == 'a')
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
    static char c;
    
    if (c == 0)
        c = 'a';
    if (!(d = opendir(str)))
    {
        printf("Not dir\n");
        //printf("%s", str);
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
                    ft_lstadd(&ss, newlst(pathname((char *)str, s, c)));
	        //printf("%s\t", s);
        }
        closedir(d);
    }
    while (ss->next != 0)
    {
        //printf("\n\n%s\n", (char *)ss->content);
        c = 's';
        ft_display_recursive((const char *)ss->content);
	    ss = ss->next;
        if (ss->content == 0)
            return ;
    }
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