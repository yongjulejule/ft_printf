/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lidxadd_back_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:03:20 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/20 11:11:34 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lidxadd_back(t_lidx **lst, t_lidx *new)
{
	t_lidx *start;
	t_lidx *tmp;

	start = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lidxlast(*lst);
	tmp->next = new;
	*lst = start;
}
