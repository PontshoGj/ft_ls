#include "ft_ls.h"

char    *ft_getlink(char *path)
{
    char *buff;
    
    buff = (char *)malloc(sizeof(char) * 4049);
	readlink(path, buff, 4049);
    return (buff);
}