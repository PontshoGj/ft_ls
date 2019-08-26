/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:43:53 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:44:45 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_filesize(char *str)
{
	int	filesize;

	if (stat(str, &fileStat) < 0)
		return (1);
	filesize = fileStat.st_size;
	return (filesize);
}
