#include "ft_ls.h"

void    setugid(char *path)
{
    struct stat	filestat;

	if (lstat(path, &filestat) < 0)
		return ;
    printf("%d", filestat.st_mode & S_BLKSIZE);
    printf("%d", filestat.st_mode & S_ISUID);
}

int main(void)
{
    setugid(".");
    return 0;
}