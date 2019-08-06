#include "ft_ls.h"

static void    displaysl(char *s, char *flag)
{
    if (ft_strcmp(flag, "l") && s[0] != '.')
        printf("%s\n", ft_display_long(s));
    else if (ft_strspn(flag, "la") == 2)
        printf("%s\n", ft_display_long(s));
    else if (ft_strspn(flag, "lar") == 2)
        return ;
    else if (ft_strspn(flag, "lat") == 2)
        return ;
    else if (ft_strspn(flag, "lt") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "lr") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "ltr") == 2 && s[0] != '.')
        return ;
}

static void    displaysR(char *s, char *flag)
{
    if (ft_strcmp(flag, "R") == 0 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "Ra") == 2)
        return ;
    else if (ft_strspn(flag, "Rar") == 2)
        return ;
    else if (ft_strspn(flag, "Rat") == 2)
        return ;
    else if (ft_strspn(flag, "Ratl") == 2)
        return ;
    else if (ft_strspn(flag, "Rl") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "Rt") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "Rr") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "Rtr") == 2 && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "Rtrl") == 2 && s[0] != '.')
        return ;
}

static void    displaysa(char *s, char *flag)
{
    if (ft_strcmp(flag, "a") == 0)
		printf("%s\t", s);
    else if (ft_strspn(flag, "ar"))
        printf("%s\t", s);
    else if (ft_strspn(flag, "at"))
        return ;
    else if (ft_strspn(flag, "atr"))
        return ;
}

static void    displays(char *s, char *flag)
{
    if (ft_strcmp(flag, "") == 0 && s[0] != '.')
		printf("%s\t", s);
    else if (ft_strspn(flag, "r") && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "t") && s[0] != '.')
        return ;
    else if (ft_strchr(flag, 'R') != 0)
        displaysR(s, flag);
    else if (ft_strchr(s, 'a') != 0)
        displaysa(s,flag);
    else if (ft_strchr(s, 'l') != 0)
        displaysl(s, flag);
}

void    ft_display_dir(char *str, char *flag)
{
    DIR *d;
    struct dirent *dir;
    char *s;
    t_list *lst;

    s = 0;

    lst = ft_dirlst(str);
    while (lst != 0)
    {
        if ((d = opendir(ft_pathname(str,(char *)lst->content))))
        {
            while ((dir = readdir(d)) != 0)
                displays((char *)dir->d_name, flag);
            closedir(d);
        }
        lst = lst->next;
    }
}