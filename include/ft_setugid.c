/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setugid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:49:23 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:50:36 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			setugid(char *path)
{
	struct stat	filestat;

	if (lstat(path, &filestat) < 0)
		return ;
	printf("%d", filestat.st_mode & S_BLKSIZE);
	printf("%d", filestat.st_mode & S_ISUID);
}

int				main(void)
{
	setugid(".");
	return (0);
}
