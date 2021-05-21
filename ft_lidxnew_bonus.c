/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxnew_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:51:53 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/21 16:02:03 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lidx	*ft_lidxnew(void *txt, int order)
{
	t_lidx	*newlst;

	if (!(newlst = (t_lidx*)malloc(sizeof(t_lidx))))
		return (NULL);
	if (!(newlst->txt = ft_strdup(txt)))
	{
		free(newlst);
		return (NULL);
	}
	newlst->order = order;
	newlst->next = NULL;
	newlst->opts.n_opt = 0;
	newlst->opts.flags = 0;
	newlst->opts.width = 0;
	newlst->opts.precision = 0;
	newlst->opts.length = 0;
	newlst->opts.specifier = 0;
	return (newlst);
}
