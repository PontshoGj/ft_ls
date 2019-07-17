#include "ft_ls.h"
/*
int  lstdir(char *str)
{
    if (stat(str, &fileStat) < 0)
        return 0;
    if (S_ISDIR(fileStat.st_mode))
        return (1);
    else
        return (-1);
}
*/
t_list      *newlst(char *str)
{
    t_list	*elem;
	t_list	*adds;

	if (!(elem = ft_lstnew(str, sizeof(str))))
		return (0);
	if (!(adds = ft_lstnew(str, sizeof(str))))
		return (0);
	ft_lstadd(&elem, adds);
    //ft_lstdelone(&adds, &ft_dellst);
    return (elem);
}

void  dirlist(char *str)
{
    DIR *d;
    struct dirent *dir;
    t_list *ss;

    d = opendir(str);
    ss = ft_lstnew(0, 0);
    //ss = ft_lstnew(str, ft_strlen(str));
    if (d)
    {
        printf("%s\n", str);
        while ((dir = readdir(d)) != 0)
        {
            if (dir->d_type == DT_DIR)
            {
                ft_lstadd(&ss, newlst(dir->d_name));
            }
            printf("%s\t", dir->d_name);
        }
        closedir(d);
    }
    if (ss->next != 0)
    {
        printf("\n");
        dirlist(ss->content);
        //printf("\n");
        //printf("%s", ss->content);
        printf("\n");
        ss = ss->next;
        printf("%s", ss->content);
    }
}
/*
void    ft_rdirec(char *str)
{
    DIR *d;
    struct dirent *dir;
    char *s;

    s = 0;
    d = opendir(str);
    
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
            if (s[0] != '.')
                printf("%s\t", s);
        }
        printf("\n");
        closedir(d);
    }
}
*/
int main(void) {
    //ft_rdirec(".");
    dirlist(".");
    return 0;
}