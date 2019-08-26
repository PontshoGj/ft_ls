/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:45:29 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 12:46:13 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_filelink(char *str)
{
	int	link;

	if (stat(str, &fileStat) < 0)
		return (1);
	link = fileStat.st_nlink;
	return (link);
}
