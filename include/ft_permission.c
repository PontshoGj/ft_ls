/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:56:44 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:59:31 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_permission(char *filename)
{
	char	*str;
	struct stat fileStat;

	if (!(str = malloc(sizeof(char) * 12)))
		return (0);
	str[11] = 0;
	if (stat(filename, &fileStat) < 0)
		return (0);
	str[0] = ft_filetype(filename);
	str[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = chkxattr(filename);
	return (str);
}
