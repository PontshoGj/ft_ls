#include "ft_ls.h"

char    *ft_getlink(char *path)
{
    char *buff;
    
    buff = (char *)malloc(sizeof(char) * 2024);
	readlink(path, buff, 2024);
    return (buff);
}