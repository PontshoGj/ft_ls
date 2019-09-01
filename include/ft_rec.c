#include "ft_ls.h"

static void    ft_printdir(char **str, char *flag, char *path)
{
    size_t i;

    i = 0;
    while (str[i] != NULL)
        ft_display_all(str[i++], flag, path);
}

static void    ft_recd(char **str, char *s, char *flag)
{
    size_t i;
    
    i = 1;
    while (str[i] != 0)
    {
        if (isdir(ft_pathname(s, str[i])) && ft_strcmp(str[i], ".") != 0 && ft_strcmp(str[i], "..") != 0 && str[i][0] != '.' && ft_islink(ft_pathname(s, str[i])) == 0)
        {
            printf("\n\n%s:\n", ft_pathname(s, str[i]));
            ft_displayrec(ft_pathname(s, str[i]), flag);
        }
        i++;
    }
}

void    ft_displayrec(char *ss, char *flag)
{
    char **s;

    s = ft_arrydirlist(ss, ft_chksort(flag));
    if (ft_strspn("atr", flag) == 3)
            s =  ft_sortarryr(s);
    ft_printdir(s, flag, ss);
    ft_recd(s, ss, flag);
}