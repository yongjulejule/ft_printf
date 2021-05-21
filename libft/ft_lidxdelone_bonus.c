/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxdelone_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:15:49 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 11:19:16 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lidxdelone(t_lidx *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->txt);
	free(lst);
	lst = NULL;
}
