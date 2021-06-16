/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 02:20:31 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 01:38:04 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_4bit_hexa_nbr(va_list ap, t_lidx *strs)
{
	if (get_length_flag(strs) == 1)
		ft_putnbr_ushort_hexa_fd(strs, va_arg(ap, int), 1);
	else if (get_length_flag(strs) == 2)
		ft_putnbr_uchar_hexa_fd(strs, va_arg(ap, int), 1);
	else
		ft_putnbr_ui_hexa_fd(strs, va_arg(ap, int), 1);
	va_end(ap);
}

static	void	put_8bit_hexa_nbr(va_list ap, t_lidx *strs)
{
	if (get_length_flag(strs) == 3)
		ft_putnbr_ul_hexa_fd(strs, va_arg(ap, long), 1);
	else if (get_length_flag(strs) == 4)
		ft_putnbr_ull_hexa_fd(strs, va_arg(ap, long), 1);
	va_end(ap);
}

void			ft_print_hexa_nbr(va_list ap, t_lidx *strs)
{
	if (strs->opts.length >= 0
			&& (strs->txt[strs->opts.length] == 'l'))
		put_8bit_hexa_nbr(ap, strs);
	else
		put_4bit_hexa_nbr(ap, strs);
}
