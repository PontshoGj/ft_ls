/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:14:41 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 12:15:43 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_nbrstr(int n, int num)
{
	char	*s;
	char	*str;
	int		i;

	i = 0;
	s = ft_itoa(n);
	if (n < 0)
		num++;
	str = (char *)malloc(sizeof(char) * num + 1);
	while (*s && num-- > 0)
		str[i++] = *s++;
	str[i] = 0;
	return (str);
}
