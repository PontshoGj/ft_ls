#include "ft_ls.h"

static void    displaysl(char *s, char *flag, char *path)
{
    //printf("s%ss\n", flag);
    if (ft_strcmp(" l", flag) == 0 && s[0] != '.')
        ft_display_long(s, path);
    else if (ft_strspn("la", flag) == 2)
        ft_display_long(s, path);
    else if (ft_strspn("lar", flag) == 3)
        return ;
    else if (ft_strspn("lat", flag) == 3)
        ft_display_long(s, path);
    else if (ft_strspn("lt", flag) == 2 && s[0] != '.')
        ft_display_long(s, path);
    else if (ft_strspn("lr", flag) == 2 && s[0] != '.')
        ft_display_long(s, path);
    else if (ft_strspn("ltr", flag) == 3 && s[0] != '.')
        return ;
}

static void    displaysR(char *s, char *flag)
{
    //printf("%s", flag);
    (void)flag;
    (void)s;
    if (ft_strspn("R", flag) == 1)
        ft_displayrec(s, flag);
    /*else if (ft_strspn("Ra", flag) == 2)
        return ;
    else if (ft_strspn("Rar", flag) == 3)
        return ;
    else if (ft_strspn("Rat", flag) == 3)
        return ;
    else if (ft_strspn("Ratl", flag) == 4)
        return ;
    else if (ft_strspn("Rl", flag) == 2)
        ft_displayrec(s, flag);
    else if (ft_strspn("Rt", flag) == 2)
        return ;
    else if (ft_strspn("Rr", flag) == 2)
        return ;
    else if (ft_strspn("Rtr", flag) == 3)
        return ;
    else if (ft_strspn("Rtrl", flag) == 4)
        return ;*/
}

static void    displaysa(char *s, char *flag)
{
    //printf("%s", s);
    if (ft_strcmp(" a", flag) == 0)
		ft_display_all(s, "", "");
    else if (ft_strspn("ar", flag) == 2)
        ft_display_all(s, "", "");
    else if (ft_strspn("at", flag) == 2)
        ft_display_all(s, "", "");
    else if (ft_strspn("atr", flag) == 3)
        return ft_display_all((s), "", "");
}

static void    displays(char *s, char *flag,char *path)
{
    //printf("%s", flag);
    
    if (ft_strspn("l", flag) == 1)
        displaysl(s, flag, path);
    else if (ft_strspn("a", flag) == 1)
        displaysa(s, flag);
    else if (ft_strspn("tr", flag) == 1 && s[0] != '.')
        ft_display_all(s, "", "");
    else if (s[0] != '.')
        ft_display_all(s, flag, ".");
    (void)s;
    (void)path;
    (void)displaysa;
    (void)displaysl;
}

void    ft_display_dir(char *str, char *flag)
{
    int i;
    char **arrlist;
    
    i = 0;
    arrlist = 0;
    if (ft_strspn("R",  flag) == 1 && isdir(str))
        displaysR(str, flag);
    //else if (ft_strspn("l", flag) == 1 && isdir(str))

    else if (isfile(str))
        ft_display_all(str, flag, ".");
    else if (isdir(str))
    {
        arrlist = ft_arrydirlist(str, ft_chksort(flag));
        if (ft_strspn("tr", flag) == 2)
            arrlist =  ft_sortarryr(arrlist);
        //printf("%s:\n", str);
        while (arrlist[i] != 0)
            displays(arrlist[i++], flag, str);
    }
    (void)str;
    (void)flag;
    (void)displaysR;
    (void)displays;
}