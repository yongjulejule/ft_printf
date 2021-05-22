/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:14:10 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/22 11:05:08 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(t_lidx *str)
{
	int idx;
	int jdx;

	jdx = 0;
	idx = str->opts.length;
	idx++;
	while (jdx < 12)
	{
		if (str->txt[idx] == "cspdiuxXfge%"[jdx])
		{
			str->opts.specifier = idx;
			return ;
		}
		jdx++;
	}
	idx--;
	str->opts.specifier = idx;
	str->order = IS_CHRS;
}
