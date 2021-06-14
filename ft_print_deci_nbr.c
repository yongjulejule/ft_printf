/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 02:20:31 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/15 05:06:20 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_4bit_nbr(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
		if (is_this_length(strs) == 1)
			ft_putnbr_short_fd(va_arg(ap, int), 1);
		else if (is_this_length(strs) == 2)
			ft_putnbr_char_fd(va_arg(ap, int), 1);
		else
			ft_putnbr_abs_fd(va_arg(ap, int), 1);
	else
	{
		if (is_this_length(strs) == 1)
			ft_putnbr_ushort_fd(va_arg(ap, int), 1);
		else if (is_this_length(strs) == 2)
			ft_putnbr_uchar_fd(va_arg(ap, int), 1);
		else
			ft_putnbr_ui_fd(va_arg(ap, int), 1);
	}
	va_end(ap);
}

static	void	put_8bit_nbr(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opts.spec] == 'i')
	{
		if (is_this_length(strs) == 3)
			ft_putnbr_l_fd(va_arg(ap, long), 1);
		else if (is_this_length(strs) == 4)
			ft_putnbr_ll_fd(va_arg(ap, long), 1);
	}
	else
	{
		if (is_this_length(strs) == 3)
			ft_putnbr_ul_fd(va_arg(ap, long), 1);
		else if (is_this_length(strs) == 4)
			ft_putnbr_ull_fd(va_arg(ap, long), 1);
	}
	va_end(ap);
}

void	ft_print_deci_nbr(va_list ap, t_lidx *strs)
{
	if (strs->opts.length >= 0
			&& (strs->opts.length != strs->opts.precision
			|| strs->txt[strs->opts.length] == 'l'))
		put_8bit_nbr(ap, strs);
	else
		put_4bit_nbr(ap, strs);
}
