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
    return (0);
}

void ls(int argc, char **argv)
{
    int i;
    int j;
    char *s;
    char **temp;

    i = 1;
    j = 0;
    s = " ";
    temp = argv;
    if (argc == 1)
        ft_display_dir(".", s);
    if (argc > 1)
    {
        while (i < argc && argv[i][0] == '-')
        {
            if(argv[i][0] == '-' && checkfl(argv[i]))
            {
                //temp = s;
                //free(s);
                s = ft_strjoin(s, ++argv[i]);
            }
            i++;
        }
        while (i <= argc)
        {
            if (j == 0 && i == argc)
                ft_display_dir(".", s);
            else if (i != argc && (j = j + 1) && checkfiledir(argv[i]) == 1)
                ft_display_dir(argv[i], s);
            i++;
        }
    }
    //ft_free2d(temp);
}

int main(int ac, char **av)
{
    ls(ac, av);
    sleep(10);
    return (0);
}
