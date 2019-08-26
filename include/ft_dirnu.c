/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirnu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:23:47 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:26:14 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t				ft_dirnum(char *path)
{
	DIR				*d;
	struct dirent	*dir;
	size_t			i;

	i = 0;
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != 0)
			i++;
		closedir(d);
	}
	return (i);
}
