#include "ft_ls.h"

static void    displaysl(char *s, char *flag, char *path)
{
    if (ft_strcmp(" l", flag) == 0 && s[0] != '.')
        ft_display_long(s, path);
}

static void    displaysR(char *s, char *flag)
{
    if (ft_strspn("R", flag) == 1)
        ft_displayrec(s, flag);
}

static void    displaysa(char *s, char *flag)
{
    if (ft_strcmp(" a", flag) == 0)
		ft_display_all(s, "", "");
}

static void    displays(char *s, char *flag,char *path)
{
    if (ft_strspn("l", flag) == 1)
        displaysl(s, flag, path);
    else if (ft_strspn("a", flag) == 1)
        displaysa(s, flag);
    else if (s[0] != '.')
        ft_display_all(s, flag, ".");       
 }

void    ft_display_dir(char *str, char *flag)
{
    int i;
    char **arrlist;
    static int j;
    
    i = 0;
    if (!j)
        j = 0;
    arrlist = 0;
    if (ft_strspn("R",  flag) == 1 && isdir(str))
    {
        displaysR(str, flag);
        j++;
        ft_printf("\n\n");    
    }
    else if (ft_strspn("l", flag) == 1 && isdir(str))
    {
        ft_longdisplay(str, flag);
        j++;
    }
    else if (isfile(str))
    {
        ft_display_all(str, flag, ".");
        //printf("\n");
        j++;
    }
    else if (isdir(str))
    {
        arrlist = ft_arrydirlist(str, ft_chksort(flag));
        if (ft_strspn("tr", flag) == 2)
            ft_sortarryr(arrlist);
        if (j != 0)
            ft_printf("\n%s:\n", str);
        while (arrlist[i] != 0)
        {
            displays(arrlist[i], flag, str);
            free(arrlist[i++]);
        }
        //free(flag);
        //free(str);
        //ft_free2d(arrlist);
        ft_printf("\n");
    }
}