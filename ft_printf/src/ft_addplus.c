/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:08:22 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:09:47 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_addplus(char **s, va_list args)
{
	char	*str;

	str = ft_strtrim(ft_strsub(*s, 0, 2));
	(ft_strspn("di", str)) ? outint(str[0], args, 0, ' ') : 0;
	(ft_strspn("c", str)) ? outint(str[1], args, 0, ' ') : 0;
	*s += 1;
}
