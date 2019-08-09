#include "ft_ls.h"
/*
void    disp(char *s)
{
    t_list *lst;
    t_list *temp;
    char *str;

    lst = ft_dirlst(s);
    temp = ft_dirlst(s);
    str = 0;
    while (lst != 0)
    {
        printf("%s\t", (char *)lst->content);
        //ft_display_all((char *)lst->content);
        lst = lst->next;
    }
    printf("\n\n");
    while(temp != 0)
    {
        str = (char *)temp->content;
        printf("%s\n", str);
        if (isdir(ft_pathname(s, str)) && str[0] != '.' && ft_strcmp(str, ".") != 0 && ft_strcmp(str, "..") != 0)
        {
            printf("%s:\n", ft_pathname(s ,str));
            disp(ft_pathname(s, str));
        }
        temp = temp->next;
    }
}
*/
void    disp(char *s)
{
    t_list *temp;
    //char *str;

    temp = ft_dirlst(s);
    //printf("%s", s);
    /*while(temp != 0)
    {
        str = (char *)temp->content;
        if (isdir(ft_pathname(s, str)) && str[0] != '.' && ft_strcmp(str, ".") != 0 && ft_strcmp(str, "..") != 0)
        {
            printf("%s\n", ft_pathname(s ,str));
            disp(ft_pathname(s, str));
        }
        temp = temp->next;
    }*/
}