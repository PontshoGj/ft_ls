/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatpre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:11:58 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:12:21 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		floatpre(char **str, va_list args, int i)
{
	char	c;

	c = (char)(*str[0]);
	outdoub(c, args, 0, i);
}
