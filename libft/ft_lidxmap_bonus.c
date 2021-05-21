/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxmap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:55:59 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 11:28:10 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lidx	*ft_lidxmap(t_lidx *lst, void *(*f)(void *), void (*del)(void*))
{
	t_lidx *newlst;
	t_lidx *root_newlst;

	if (lst == NULL)
		return (NULL);
	if (!(newlst = ft_lidxnew(f(lst->txt))))
		return (NULL);
	root_newlst = newlst;
	while (lst->next != NULL)
	{
		if (!(newlst->next = ft_lidxnew(f(lst->next->txt))))
		{
			ft_lidxclear(&root_newlst, del);
			return (NULL);
		}
		if (lst->next != NULL)
			lst = lst->next;
		newlst = newlst->next;
	}
	return (root_newlst);
}
