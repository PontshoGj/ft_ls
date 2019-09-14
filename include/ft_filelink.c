/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:45:29 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 11:12:22 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_filelink(char *str)
{
	int			link;
	struct stat	filestat;

	if (lstat(str, &filestat) < 0)
		return (1);
	link = filestat.st_nlink;
	return (link);
}
