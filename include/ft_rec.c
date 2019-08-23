#include "ft_ls.h"

void    fcallme(char *s)
{
    t_list *temp;
    t_list hol;
    char *str;
    
    temp = ft_dirlstname(s);
    while(temp->next != NULL)
    {
        str = (char *)temp->content;
        if (str[0] != '.' || str != NULL)
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