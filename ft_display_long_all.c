#include "ft_ls.h"

void    ft_display_long_all(char *str)
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
			//printf("%s\n", ft_joinfiled(dir->d_name));
        }
        closedir(d);
    }
}