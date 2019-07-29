#include "ft_ls.h"

void    ft_printdir(char *str, char *flag)
{
    if (ft_strcmp(flag, "l") == 0)
        ft_joinfiled(str, "");
    else if (ft_strcmp(flag, "a") == 0)
        ft_display_all(str);
    else if (ft_strcmp(flag, "R") == 0)
        ft_display_recursive(str);
    else if (ft_strcmp(flag, "al") == 0 || ft_strcmp(flag, "la") == 0)
        ft_joinfiled(str, ".");
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
        ft_printdir(".", "");
    }
    
    if (argc > 1)
    {
        while (i < argc)
        {
            if(ft_isflag(argv[i]) == 1)
                s = ft_strjoin(s, ++argv[i]);     
            else
            {
                printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", argv[i][1]);
                exit(1);
            }
            i++;
        }
        ft_printdir("ft_filelink.c", s);
        //ft_printdir(argv[1], 0);
    }
    //sleep(90);
    return (0);
}
