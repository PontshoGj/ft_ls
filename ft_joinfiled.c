#include "ft_ls.h"

char    *ft_display_longs(char *str)
{
    char *s;
    
    s = "";
    s = ft_strjoin(s, ft_permission(str));
    s = ft_strcat(s, "\t");
    s = ft_strjoin(s, ft_itoa(ft_filelink(str)));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, ft_filename(str));
    s = ft_strcat(s, "\t");
    s = ft_strjoin(s, ft_itoa(ft_filesize(str)));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, ft_filetimes(str));
    s = ft_strcat(s, "\t");
    s = ft_strcat(s, str);
    return (s);
}


void    ft_joinfiled(char *str, char *flag)
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
            if (s[0] != '.' || ft_strcmp(flag, ".") == 0)
            {
			    printf("%s\n", ft_display_longs(dir->d_name));
            }
        }
        closedir(d);
    }
}
