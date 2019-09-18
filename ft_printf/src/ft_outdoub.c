/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outdoub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:16:31 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:21:44 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			rnum(double i, int z)
{
	int				count;
	int				j;

	count = 1;
	if (z != 0)
		j = z;
	else
		j = 6;
	while (i > 0 && j-- > 0)
	{
		count = i * 10;
		if (j == 0)
		{
			if (i * 10 > 5)
				count += 1;
		}
		i *= 10;
	}
	return (count);
}

static void			floatspace(int i, int c, int sizes)
{
	char			*s;

	s = ft_itoa(i);
	s = ft_strjoin(s, ft_itoa(c));
	givespace((int)ft_strlen(s), sizes, ' ');
}

void				outdoub(char s, va_list args, int sizes, int z)
{
	double			i;
	double			j;
	int				c;

	i = 0;
	j = 0;
	c = 0;
	if (s == 'f' || s == 'F')
	{
		i = va_arg(args, double);
		j = i;
		j = i - (int)j;
		c = rnum(j, z);
		floatspace((int)i, c, sizes);
		ft_putnbrlong((int)i);
		ft_putchar('.');
		ft_putnbrlong((long)c);
	}
}
