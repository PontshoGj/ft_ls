/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printshort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:31:42 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:49 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printshort2(char **s, va_list args, int space)
{
	char		*str;

	str = ft_strtrim(ft_strsub(*s, 0, 3));
	if (ft_strspn(str, "hhd") == 3 || ft_strspn(str, "hhi") == 3)
	{
		*s += 2;
		ft_outputshortun(args, space, *s[0]);
	}
	else if (ft_strspn(str, "hhx") == 3 || ft_strspn(str, "hhX") == 3)
	{
		*s += 2;
		ft_outputshorthex(args, space, *s[0], str[1]);
	}
	else if (ft_strspn(str, "hho") == 3)
	{
		*s += 2;
		ft_outputshortoct(args, space, *s[0], str[1]);
	}
	else if (ft_strspn(str, "hhu") == 3)
	{
		*s += 2;
		ft_outputunsignedshort(args, space, str[1]);
	}
}

void			ft_printshort(char **s, va_list args, int space)
{
	char		*str;

	str = ft_strtrim(ft_strsub(*s, 0, 3));
	if (ft_strspn(str, "hhxoXdi") == 3)
		ft_printshort2(s, args, space);
	else if (ft_strspn(str, "hd") == 2 || ft_strspn(str, "hi") == 2)
	{
		ft_outputshortun(args, space, *s[0]);
		*s += 1;
	}
	else if (ft_strspn(str, "hx") == 2 || ft_strspn(str, "hX") == 2)
	{
		*s += 1;
		ft_outputshorthex(args, space, *s[0], str[1]);
	}
	else if (ft_strspn(str, "hu") == 2)
	{
		ft_outputunsignedshort(args, space, str[1]);
		*s += 1;
	}
	else if (ft_strspn(str, "ho") == 2)
	{
		*s += 1;
		ft_outputshortoct(args, space, *s[0], str[1]);
	}
}
