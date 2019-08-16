#include "ft_ls.h"

static int    checkfl(char *str)
{
    char s;
    if(!(s = ft_isflag(str)))
        return (1);     
    printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] [file ...]\n", s);
    exit(1);
}

static int     checkfiledir(char *s)
{
    if (isdir(s) || isfile(s))
        return (1);
    printf("ls: %s: No such file or directory\n", s);
    exit(1);
}

int main(int argc, char **argv)
{
    int i;
    char *s;

    i = 1;
    s = "";
    if (argc == 1)
    {
        (void)argv;
        ft_display_dir(".", "");
    }
    if (argc > 1)
    {
        while (i < argc)
        {
            if(argv[i][0] == '-' && checkfl(argv[i]))
                s = ft_strjoin(s, ++argv[i]);
            else if (checkfiledir(argv[i]) == 1)
            {
                ft_display_dir(argv[i], s);
                i++;
                continue;
            }
            i++;
        }
        //printf("%zu", ft_strspn(s, "l"));
        ft_display_dir(".", s);
    }
    return (0);
}
