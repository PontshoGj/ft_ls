#include "ft_ls.h"

void    ft_printdir(char *str, char *flag)
{
    if (ft_strcmp(flag, "-l") == 0)
        ft_display_long(str);
    else if (ft_strcmp(flag, "-a") == 0)
        ft_display_all(str);
    else if (ft_strcmp(flag, "-R") == 0)
        ft_display_recursive(str);
    else if (ft_strcmp(flag, "-al") == 0 || ft_strcmp(flag, "-la") == 0)
        ft_display_long_all(str);
}

int     checkflags(char c)
{
    int i;
    char s[5];

    i = 0;
    s[0] = 'l';
    s[1] = 'R';
    s[2] = 'a';
    s[3] = 't';
    s[4] = 'r';
    while (i < 5)
    {
        if (c == s[i++])
            return (1);
    }
    return (0);
}

int     isflag(char *s)
{
    int i;

    i = 1;
    if (s[0] == '-')
    {
        if (ft_strlen(s) > 1)
        {
            while (s[i])
            {
                if (checkflags(s[i++]) == 0)
                    return (0);
            }
            return (1);
        }
    }
    return (0);
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
        ft_printdir(".", 0);
    }
    if (argc > 1)
    {
        while (i < argc)
        {
            if(isflag(argv[i]) == 1)
                s = ft_strjoin(s, argv[i]);     
            else
            {
                printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", argv[i][1]);
                exit(1);
            }
            i++;
        }
        ft_printdir("..", s);
        //ft_printdir(argv[1], 0);
    }
    //sleep(90);
    return (0);
}
