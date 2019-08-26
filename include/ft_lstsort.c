/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:15:39 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/26 13:20:37 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstsort(t_list **lst)
{
	t_list	*lfirst;
	t_list	*lsecond;
	int		i;
	int		j;

	lfirst = *lst;
	lsecond = *lst;
	i = 1;
	j = 0;
	while (lfirst->next != 0)
	{
		lsecond = *lst;
		while (lsecond->next != 0)
		{
			j++;
			if (ft_strcmp((char *)lfirst->content, \
						(char *)lsecond->content) < 0)
				ft_swaplst(lst, i, j);
			lsecond = lsecond->next;
		}
		j = 0;
		i++;
		lfirst = lfirst->next;
	}
}
