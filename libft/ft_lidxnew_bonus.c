/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxnew_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:51:53 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 13:46:38 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lidx	*ft_lidxnew(void *txt, int order)
{
	t_lidx	*newlst;

	if (!(newlst = (t_lidx*)malloc(sizeof(t_lidx))))
		return (NULL);
	newlst->order = order;
	newlst->txt = txt;
	newlst->next = NULL;
	return (newlst);
}
