/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:12:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/19 19:35:27 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static	int		split_lst(t_lidx **str)
//{
//	char	*backup;
//	t_lidx	*newnode;
//	t_lidx	*cur;
//
//	cur = *str;
//	while (1)
//	{
//		backup = ft_substr((cur->txt), cur->opts.spec + 1, ft_strlen(cur->txt));
//		if (!backup)
//			return (ERROR_FLAG);
//		newnode = ft_lidxnew(backup, IS_NOT_FLAG);
//		free(backup);
//		if (!newnode)
//		{
//			ft_lidxclear(str, free);
//			return (ERROR_FLAG);
//		}
//		newnode->next = cur->next;
//		cur->next = newnode;
//		cur = newnode->next;
//		if (!cur)
//			return (SUCCESS_FLAG);
//	}
//}

static	int		get_flags(t_lidx **str)
{
	t_lidx *tmp;

	tmp = *str;
	while (tmp)
	{
		check_flags(tmp);
		tmp = (tmp)->next;
	}
	return (SUCCESS_FLAG);
}

int				parsing(char *format, t_lidx **strs)
{
	if (!ft_split_for_pf(format, strs))
		return (ERROR_FLAG);
	if (!get_flags(strs))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
