#include "ft_ls.h"

int    checkfl(char *str)
{
    char s;
    if(!(s = ft_isflag(str)))
                return (1);     
    else
    {
        printf("ft_ls: illegal option -- %c\nusage: ft_ls [-Ralrt] [file ...]\n", s);
        exit(1);
    }
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
            if(checkfl(argv[i]))
                s = ft_strjoin(s, ++argv[i]);
            else if (isdir(argv[i]) || isfile(argv[i]))
            {
                if (ft_strlen(s) >= 1)
                    ft_display_dir(argv[i], s);
                else
                    ft_display_dir(argv[i], 0);
            }
                 
            
            i++;
        }
        //ft_display_dir(".", s);
        //ft_printdir(argv[1], 0);
    }
    return (0);
}
