/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:20:12 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:21:16 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 			ft_islink(char *s)
{
	struct stat kk;

	lstat(s, &kk);
	if (kk.st_mode & S_IFLNK)
		return (1);
	return (0);
}

int				isfile(char *s)
{
	struct stat	kk;

	stat(s, &kk);
	return ((S_ISREG(kk.st_mode)) ? 1 : 0);
}

int	isdir(char *s)
{
	struct stat kk;

	stat(s, &kk);
	return ((S_ISDIR(kk.st_mode)) ? 1 : 0);
}
