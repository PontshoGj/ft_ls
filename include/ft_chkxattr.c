/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkxattr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:44:17 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/02 12:44:56 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		chkxattr(char *path)
{
	size_t	retvalue;
	//size_t retgetxatr;
	//char buff[5];

	retvalue = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	//retgetxatr = getxattr("Desktop", "Desktop", 0,0,0, XATTR_NOFOLLOW);
	if (retvalue > 0)
		return ('@');
	//else if (retgetxatr > 1)
	//    return ('+');
	return (' ');
}
