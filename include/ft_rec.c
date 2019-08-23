#include "ft_ls.h"

void    fcallme(char *s)
{
    t_list *temp;
    t_list hol;
    char *str;
    
    temp = ft_dirlstname(s);
    while(temp->next != 0)
    {
        str = (char *)temp->content;
        /*if (isdir(ft_pathname(s, str)) && str[0] != '.' && ft_strcmp(str, ".") != 0 && ft_strcmp(str, "..") != 0)
        {
            //printf("\n%s:\n", ft_pathname(s ,str));
            disp(ft_pathname(s, str));
        }*/
        if (str[0] != '.')
            disp(ft_pathname(s, str));
        hol = *temp;
        temp = temp->next;
        ft_dellst(hol.content, hol.content_size); 
    }
}

void    disp(char *s)
{
    printf("%s:\n", s);
    //ft_display_long_all(s);
    //printf("<--------------------------------------------------------------------------------------------------->");
    fcallme(s);
}