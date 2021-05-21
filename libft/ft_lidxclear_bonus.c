/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxclear_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:41:38 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 11:20:05 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lidxclear(t_lidx **lst, void (*del)(void*))
{
	t_lidx *tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	if (tmp->next == NULL)
		ft_lidxdelone(tmp, del);
	else
	{
		while (tmp->next != NULL)
		{
			*lst = tmp;
			tmp = tmp->next;
			del((*lst)->txt);
			free(*lst);
			*lst = NULL;
			if (tmp->next == NULL)
			{
				ft_lidxdelone(tmp, del);
				return ;
			}
		}
	}
}
