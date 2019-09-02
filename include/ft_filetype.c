/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:28:57 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/02 12:36:09 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_filetype(char *path)
{
	char		str;
	struct stat	fileStat;

	if (lstat(path, &fileStat) < 0)
		return (0);
	str = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
	str = (S_ISLNK(fileStat.st_mode)) ? 'l' : str;
	str = (S_ISFIFO(fileStat.st_mode)) ? 'p' : str;
	str = (S_ISSOCK(fileStat.st_mode)) ? 's' : str;
	str = (S_ISCHR(fileStat.st_mode)) ? 'c' : str;
	str = (S_ISBLK(fileStat.st_mode)) ? 'b' : str;
	return (str);
}
