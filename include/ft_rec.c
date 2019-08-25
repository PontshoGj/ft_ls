#include "ft_ls.h"

/*void    fcallme(char *s)
{
    t_list *temp;
    t_list hol;
    char *str;
    
    temp = ft_dirlstname(s);
    while(temp->next != NULL)
    {
        str = (char *)temp->content;
        if (str[0] != '.' && ft_islink(ft_pathname(s, str)))
            ft_display_dir(ft_pathname(s, str), "R");
            ///disp(ft_pathname(s, str));
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
}*/
void    printlst(char **str, char *s);
void    pp(char **str)
{
    size_t i = 0;

    while (str[i] != NULL)
    {
        //printf("%-20s", str[i++]);
        ft_display_all(str[i++], "a");
        //free(str[i++]);
    }
}
void    disp(char *ss)
{
    char **s;
    s = ft_arrydirlist(ss);
    pp(s);
    printlst(s, ss);
}
void    printlst(char **str, char *s)
{
    size_t i = 1;
    
    printf("\n\n%s:\n\n", s);
    while (str[i] != 0)
    {
        if (isdir(ft_pathname(s, str[i])) && ft_strcmp(str[i], ".") != 0 && ft_strcmp(str[i], "..") != 0 && str[i][0] != '.' && ft_islink(ft_pathname(s, str[i])) == 0)
        {
            printf("\n\n%s:\n\n", ft_pathname(s, str[i]));
            disp(ft_pathname(s, str[i]));
        }
        i++;
    }
}