/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islnk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:49:27 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:50:00 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_islink(char *s)
{
	struct stat kk;

	lstat(s, &kk);
	if (kk.st_mode & S_IFLNK)
		return (1);
	return (0);
}