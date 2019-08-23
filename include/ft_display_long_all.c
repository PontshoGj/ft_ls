#include "ft_ls.h"

void    ft_display_long_all(char *s)
{
    t_list *temp;
    t_list hol;
    char *str;
    
    temp = ft_dirlst(s);
    while(temp->next != 0)
    {
        str = (char *)temp->content;
        if (str[0] != '.')
            ft_display_all(str, "");
        hol = *temp;
        temp = temp->next;
        ft_dellst(hol.content, hol.content_size); 
    }
    //printf("<----->\n");
    printf("\n");
}