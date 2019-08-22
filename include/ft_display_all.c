#include "ft_ls.h"

void    ft_display_all(char *str, char *flag)
{
    static int i;

    if (!i)
        i = 0;
   
    else if (i == 5)
    {
        i = 0;
        printf("\n");
    }
    i++;
    if (ft_strcmp(flag, "l") == 0)
        ft_display_long(str);
    else
        printf("%s%*.*s", str, (int)(24 - ft_strlen(str)), (int)(10 - ft_strlen(str)), " ");
}