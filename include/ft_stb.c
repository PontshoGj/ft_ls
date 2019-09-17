/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:48:29 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 13:48:59 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_stb(struct stat filestat)
{
	if (filestat.st_mode & S_ISUID)
		return ('S');
	else if (filestat.st_mode & S_IXUSR)
		return ('x');
	return ('-');
}
