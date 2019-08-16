#include "ft_ls.h"

static void    displaysl(char *s, char *flag)
{
    if (ft_strcmp(flag, "l") == 0 && s[0] != '.')
        ft_display_long(s);
    else if (ft_strspn(flag, "la") == 2)
        ft_display_long(s);
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
    if (ft_strcmp(flag, "R") == 0)
        disp(s);
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
		ft_display_all(s, "");
    else if (ft_strspn(flag, "ar"))
        printf("%s\t", s);
    else if (ft_strspn(flag, "at"))
        return ;
    else if (ft_strspn(flag, "atr"))
        return ;
}

static void    displays(char *s, char *flag)
{
    //printf("%s", flag);
    if (ft_strcmp(flag, "") == 0 && s[0] != '.')
        ft_display_all(s, flag);
    else if (ft_strspn(flag, "r") && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "t") && s[0] != '.')
        return ;
    else if (ft_strspn(flag, "l") == 1)
        displaysl(s, flag);
    else if (ft_strspn(flag, "a") == 1)
        displaysa(s, flag);
    else if (ft_strspn(flag, "R") == 1)
        displaysR(s, flag);
}

void    ft_display_dir(char *str, char *flag)
{
    DIR *d;
    struct dirent *dir;
    char *s;
    
    s = 0;
    d = 0;
    if (ft_strchr(flag, 'R') && isdir(str))
        disp(str);
    else if (isfile(str))
        ft_display_all(str, flag);
    else if ((d = opendir(str)) && isdir(str))
    {
        while ((dir = readdir(d)) != 0)
            displays((char *)dir->d_name, flag);
        closedir(d);
    }
}