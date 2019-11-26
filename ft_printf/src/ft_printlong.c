/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:25:22 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/17 16:25:08 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printlong2(char **s, va_list args, int space)
{
	char	*str;
	char	*strhold;

	strhold = ft_strsub(*s, 0, 3);
	str = ft_strtrim(strhold);
	if (ft_strspn(str, "lld") == 3 || ft_strspn(str, "lli") == 3)
	{
		*s += 2;
		ft_outputlong(args, space, *s[0]);
	}
	else if (ft_strspn(str, "llx") == 3 || ft_strspn(str, "llX") == 3)
	{
		*s += 2;
		ft_outputlonghex(args, space, *s[0], ' ');
	}
	else if (ft_strspn(str, "llu") == 3)
	{
		*s += 2;
		ft_outputlong(args, space, *s[0]);
	}
	else if (ft_strspn(str, "llo") == 3)
	{
		*s += 2;
		ft_outputunsignedlonghex(args, space, *s[0], str[2]);
	}
	free(str);
	free(strhold);
}

void		ft_printlong(char **s, va_list args, int space)
{
	char	*str;
	char	*strhold;

	strhold = ft_strsub(*s, 0, 3);
	str = ft_strtrim(strhold);
	if (ft_strspn(str, "lldxXiou") == 3)
		ft_printlong2(s, args, space);
	else if (ft_strspn("ld", str) == 2 || ft_strspn("li", str) == 2)
	{
		ft_outputlong(args, space, *s[0]);
		*s += 1;
	}
	else if (ft_strspn("lx", str) == 2 || ft_strspn("lX", str) == 2)
	{
		*s += 1;
		ft_outputlonghex(args, space, *s[0], str[2]);
	}
	else if (ft_strspn("lu", str) == 2)
	{
		ft_outputlong(args, space, *s[0]);
		*s += 1;
	}
	else if (ft_strspn("lo", str) == 2)
	{
		*s += 1;
		ft_outputunsignedlonghex(args, space, *s[0], str[2]);
	}
	free(str);
	free(strhold);
}
