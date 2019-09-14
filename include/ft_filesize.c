/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:43:53 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:12:45 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_filesize(char *str)
{
	int			filesize;
	struct stat filestat;

	if (lstat(str, &filestat) < 0)
		return (1);
	filesize = filestat.st_size;
	return (filesize);
}
