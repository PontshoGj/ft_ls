/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkxattr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:44:17 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 10:29:24 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		chkxattr(char *path)
{
	size_t	retvalue;

	retvalue = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (retvalue > 0)
		return ('@');
	return (' ');
}
