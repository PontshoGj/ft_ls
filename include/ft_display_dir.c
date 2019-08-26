#include "ft_ls.h"

static void    displaysl(char *s, char *flag)
{
    if (ft_strcmp("l", flag) == 0 && s[0] != '.')
        ft_display_long(s);
    else if (ft_strspn("la", flag) == 2)
        ft_display_long(s);
    else if (ft_strspn("lar", flag) == 3)
        return ;
    else if (ft_strspn("lat", flag) == 3)
        return ;
    else if (ft_strspn("lt", flag) == 2 && s[0] != '.')
        return ;
    else if (ft_strspn("lr", flag) == 2 && s[0] != '.')
        return ;
    else if (ft_strspn("ltr", flag) == 3 && s[0] != '.')
        return ;
}

static void    displaysR(char *s, char *flag)
{
    if (ft_strcmp("R", flag) == 0)
        ft_displayrec(s, flag);
    else if (ft_strspn("Ra", flag) == 2)
        return ;
    else if (ft_strspn("Rar", flag) == 3)
        return ;
    else if (ft_strspn("Rat", flag) == 3)
        return ;
    else if (ft_strspn("Ratl", flag) == 4)
        return ;
    else if (ft_strspn("Rl", flag) == 2)
        return ft_displayrec(s, flag);
    else if (ft_strspn("Rt", flag) == 2)
        return ;
    else if (ft_strspn("Rr", flag) == 2)
        return ;
    else if (ft_strspn("Rtr", flag) == 3)
        return ;
    else if (ft_strspn("Rtrl", flag) == 4)
        return ;
}

static void    displaysa(char *s, char *flag)
{
    if (ft_strcmp("a", flag) == 0)
		ft_display_all(s, "", "");
    else if (ft_strspn("ar", flag) == 2)
        printf("%s\t", s);
    else if (ft_strspn("at", flag) == 2)
        return ;
    else if (ft_strspn("atr", flag) == 3)
        return ;
}

static void    displays(char *s, char *flag)
{
    //printf("%zu", ft_strspn("l",flag));
    if (ft_strcmp("", flag) == 0 && s[0] != '.')
        ft_display_all(s, flag, "");
    else if (ft_strspn("r", flag) && s[0] != '.')
        return ;
    else if (ft_strspn("t", flag) && s[0] != '.')
        return ;
    else if (ft_strspn("l", flag) == 1)
        displaysl(s, flag);
    else if (ft_strspn("a", flag) == 1)
        displaysa(s, flag);
}

void    ft_display_dir(char *str, char *flag)
{
    DIR *d;
    struct dirent *dir;
    char *s;
    
    s = 0;
    d = 0;
    if (ft_strspn("R",  flag) == 1 && isdir(str))
        displaysR(str, flag);
    else if (isfile(str))
        ft_display_all(str, flag, "");
    else if ((d = opendir(str)) && isdir(str))
    {
        while ((dir = readdir(d)) != 0)
            displays((char *)dir->d_name, flag);
        closedir(d);
    }
}