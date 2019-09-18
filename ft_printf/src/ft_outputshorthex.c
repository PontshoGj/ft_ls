/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputshorthex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:38:02 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 17:15:55 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_nbrstrhex(char *s1, int num)
{
	char		*str;
	int			i;
	int			j;

	i = ft_strlen(s1) - num;
	j = 0;
	str = (char *)malloc(sizeof(char) * num + 1);
	while (s1[i] != 0 && num-- > 0)
		str[j++] = s1[i++];
	str[j] = 0;
	return (str);
}

static void		ft_outpsh(long long i, int space, char hex)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, ' ');
		ft_putstr(ft_longtoa_base(i, 16, hex));
	}
	else
	{
		ft_putstr(ft_longtoa_base(i, 16, hex));
		givespace(ft_intlen(i), space, ' ');
	}
}

static void		ft_outpshh(long long i, int space, char hex)
{
	if (space >= 0)
	{
		givespace(ft_intlen(i), space, ' ');
		ft_putstr(ft_nbrstrhex(ft_longtoa_base(i, 16, hex), 2));
	}
	else
	{
		ft_putstr(ft_nbrstrhex(ft_longtoa_base(i, 16, hex), 2));
		givespace(ft_intlen(i), space, ' ');
	}
}

void			ft_outputshorthex(va_list args, int space, char hex, char c)
{
	long long	i;

	if (c == 'h')
	{
		i = va_arg(args, long);
		ft_outpshh(i, space, hex);
		return ;
	}
	i = va_arg(args, long long);
	ft_outpsh(i, space, hex);
}
