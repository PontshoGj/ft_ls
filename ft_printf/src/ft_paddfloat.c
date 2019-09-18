/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:13:51 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:14:55 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		paddfloat(char **str, va_list args)
{
	char	*s;

	s = "";
	if (*str[0] == '*')
	{
		*str += 1;
		floatpre(str, args, va_arg(args, int));
	}
	else if (ft_isdigit(*str[0]))
	{
		while (!(ft_strspn(&(*str[0]), "fF")))
		{
			s = ft_strjoin(s, &(*str[0]));
			*str += 1;
		}
		floatpre(str, args, ft_atoi(s));
	}
}
