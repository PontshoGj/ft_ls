#include "ft_ls.h"

void    ft_printdir(char *str, char *flag)
{
    DIR *d;
    struct dirent *dir;
    char *s;

    s = 0;
    d = opendir(str);
    if (d)
    {
        if (flag == 0)
        {
            while ((dir = readdir(d)) != 0)
            {
                s = dir->d_name;
                if (s[0] != '.')
                    printf("%s\t%d\t%d\t%s\t%s\n", ft_permission(s), ft_filelink(s), ft_filesize(s), ft_filetimes(s), s);
            }
            closedir(d);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        (void)argv;
        ft_printdir(".", 0);
    }
    if (argc > 1)
        ft_printdir(argv[1], 0);
    return (0);
}