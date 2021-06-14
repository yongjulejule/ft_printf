/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 00:43:57 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/15 04:57:32 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_4bit_len(va_list ap, t_lidx *strs, int base)
{
	int nbr;
	int cnt;

	nbr = va_arg(ap, int);
	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
	{
		if (is_this_length(strs) == 1)
			cnt = ft_dgt_short_len(nbr, base);
		else if (is_this_length(strs) == 3)
			cnt = ft_dgt_char_len(nbr, base);
		else
			cnt = ft_dgtlen(nbr, base);
	}
	else
	{
		if (is_this_length(strs) == 1)
			cnt = ft_dgt_ushort_len(nbr, base);
		else if (is_this_length(strs) == 3)
			cnt = ft_dgt_uchar_len(nbr, base);
		else
			cnt = ft_dgt_ui_len(nbr, base);
	}
	va_end(ap);
	return (cnt);
}

static	int	get_8bit_len(va_list ap, t_lidx *strs, int base)
{
	int nbr;
	int cnt;

	nbr = va_arg(ap, long);
	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
		if (is_this_length(strs) == 1)
			cnt = ft_dgt_l_len(nbr, base);
		else
			cnt = ft_dgt_ll_len(nbr, base);
	else
	{
		if (is_this_length(strs) == 3)
			cnt = ft_dgt_ul_len(nbr, base);
		else
			cnt = ft_dgt_ull_len(nbr, base);
	}
	va_end(ap);
	return (cnt);
}

int			get_nbr_len(va_list ap, t_lidx *strs, int base)
{
	int cnt;

	if ((strs->opts.length != strs->opts.precision
			&& strs->txt[strs->opts.precision + 1] == 'l'))
		cnt = get_8bit_len(ap, strs, base);
	else
		cnt = get_4bit_len(ap, strs, base);
	return (cnt);
}
