/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:47:07 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 10:47:39 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_getlink(char *path)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 4049);
	readlink(path, buff, 4049);
	return (buff);
}
