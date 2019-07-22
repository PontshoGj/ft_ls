#include "ft_ls.h"

void    ft_display_all(char *str)
{
    DIR *d;
    struct dirent *dir;
    char *s;

    s = 0;
    d = opendir(str);
    if (d)
    {
        while ((dir = readdir(d)) != 0)
        {
            s = dir->d_name;
			printf("%s\t", s);
        }
        printf("\n");
        closedir(d);
    }
}