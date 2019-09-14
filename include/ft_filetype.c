/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:28:57 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 10:46:44 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_filetype(char *path)
{
	char		str;
	struct stat	filestat;

	if (lstat(path, &filestat) < 0)
		return (0);
	str = (S_ISDIR(filestat.st_mode)) ? 'd' : '-';
	str = (S_ISLNK(filestat.st_mode)) ? 'l' : str;
	str = (S_ISFIFO(filestat.st_mode)) ? 'p' : str;
	str = (S_ISSOCK(filestat.st_mode)) ? 's' : str;
	str = (S_ISCHR(filestat.st_mode)) ? 'c' : str;
	str = (S_ISBLK(filestat.st_mode)) ? 'b' : str;
	return (str);
}
