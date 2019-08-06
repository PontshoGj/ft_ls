#include "ft_ls.h"

void    ft_printdir(char *str, char *flag)
{
    ft_display_dir(str, flag);
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
        ft_display_dir(".", s);
        //ft_printdir(argv[1], 0);
    }
    return (0);
}
