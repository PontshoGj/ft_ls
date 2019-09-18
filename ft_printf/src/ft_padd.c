/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:06:54 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:08:54 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		padd2(char **str, va_list args, int i, int j)
{
	if (ft_strspn(&(*str[0]), "scdi"))
		prints(i, *str, args, j);
	else if (*str[0] == 'f')
		outdoub(*str[0], args, i, 0);
	else if (*str[0] == 'h')
		ft_printshort(str, args, i);
	else if (*str[0] == 'l')
		ft_printlong(str, args, i);
}

void		padd(char **str, va_list args)
{
	char	*s;
	char	*temp;
	char	j;

	s = *str;
	j = ' ';
	if (*str[0] == '0')
		j = '0';
	if (s[0] == '0' && s[1] == '-')
		*str += 1;
	s = "";
	while (!(ft_strspn(&(*str[0]), "hlscdif.")))
	{
		temp = s;
		s = ft_strjoin(s, &(*str[0]));
		free(s);
		*str += 1;
	}
	padd2(str, args, ft_atoi(s), j);
}
