#include "ft_ls.h"

void    fcallme(char *s)
{
    t_list *temp;
    char *str;
    
    temp = ft_dirlstname(s);
    while(temp->next != 0)
    {
        str = (char *)temp->content;
        if (isdir(ft_pathname(s, str)) && str[0] != '.' && ft_strcmp(str, ".") != 0 && ft_strcmp(str, "..") != 0)
        {
            printf("\n%s:\n", ft_pathname(s ,str));
            disp(ft_pathname(s, str));
        }
        temp = temp->next;  
    }
}

void    disp(char *s)
{
    ft_display_long_all(s);
    fcallme(s);
}