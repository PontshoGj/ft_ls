/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:56:44 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:10:19 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_permission(char *filename)
{
	char		*str;
	struct stat	filestat;

	if (!(str = malloc(sizeof(char) * 12)))
		return (0);
	str[11] = 0;
	if (lstat(filename, &filestat) < 0)
		return (0);
	str[0] = ft_filetype(filename);
	str[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = ft_stb(filestat);
	str[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = chkxattr(filename);
	return (str);
}
