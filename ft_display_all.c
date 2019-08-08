#include "ft_ls.h"

void    ft_display_all(char *str)
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
    printf("%s%*.*s", str, (int)(24 - ft_strlen(str)), (int)(10 - ft_strlen(str)), " ");
}