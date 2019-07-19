#include "ft_ls.h"

void    ft_display_long(char *str)
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
            if (s[0] != '.')
			    printf("%s\n", ft_joinfiled(s));
        }
        closedir(d);
    }
}