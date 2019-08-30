#include "ft_ls.h"
# include <sys/xattr.h>

char chkxattr(char *path)
{
  size_t retvalue;

  retvalue = listxattr(path, NULL, 0, XATTR_NOFOLLOW);

  if (retvalue > 0)
    return ('@');
  return (' ');
}

char    ft_filetype(char *path)
{
    char	str;
	struct stat fileStat;

    if (stat(path, &fileStat) < 0)
		return (0);
    str = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
    str = (S_ISLNK(fileStat.st_mode)) ? 'l' : str;
    str = (S_ISFIFO(fileStat.st_mode)) ? 'p' : str;
    str = (S_ISSOCK(fileStat.st_mode)) ? 's' : str;
    str = (S_ISCHR(fileStat.st_mode)) ? 'c' : str;
    str = (S_ISBLK(fileStat.st_mode)) ? 'b' : str;
    return (str);
}
/*int main(void)
{
  //"../../Library/Messages"
  //"../../Library/LaunchAgents"
  char x[10];
  ssize_t a = getxattr("../../Library/Logs", "Logs", 0, 0, 0, XATTR_NOFOLLOW);
  printf("%zu", a);
  return 0;
}*/