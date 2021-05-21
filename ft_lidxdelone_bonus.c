/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxdelone_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:15:49 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/21 15:29:13 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lidxdelone(t_lidx *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->txt);
	free(lst);
	lst = NULL;
}
