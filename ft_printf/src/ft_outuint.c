/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:03:03 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:06:07 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			printx(char s, char hex)
{
	if (hex != 0 && s == 'x')
		ft_putstr("0x");
	else if (hex != 0 && s == 'X')
		ft_putstr("0X");
	else if (hex != 0 && s == 'o')
		ft_putstr("0");
}

void				printout(int space, char *str, int length)
{
	if (space > 0)
	{
		givespace((int)ft_strlen(str), space, ' ');
		ft_putstrc(str, length);
	}
	else if (space < 0)
	{
		ft_putstrc(str, length);
		givespace((int)ft_strlen(str), space * -1, ' ');
	}
}

void				outuint(char s, va_list args, char hex, int *j)
{
	char			*str;
	unsigned int	i;
	int				space;
	int				length;

	i = va_arg(args, unsigned int);
	str = (s == 'X' || s == 'x') ? ft_itoa_base((int)i, 16, s) :\
	ft_itoa_base((int)i, 8, s);
	space = j[0];
	length = j[1];
	if (length == 0)
		length = (int)ft_strlen(str);
	else
		space += (int)ft_strlen(str) - length;
	if (space != 0)
	{
		if (i != 0)
			printx(s, hex);
		printout(space, str, length);
	}
	if (i != 0)
		printx(s, hex);
	ft_putstr(str);
}
