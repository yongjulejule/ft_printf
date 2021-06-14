/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:38:05 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/14 23:03:49 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_char(va_list ap, t_lidx *strs, int len)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	strs->opts.precision = len;
}

void			ft_print_char(va_list ap, t_lidx *strs)
{
	int		width_len;
	int		precision_len;

	width_len = get_width_len(ap, strs);
	precision_len = get_precision_len(ap, strs);
	if (ft_memchr(strs->txt, '-', (size_t)(strs->opts.flags + 1))\
			|| width_len < 0)
	{
		if (width_len < 0)
			width_len *= -1;
		print_char(ap, strs, 1);
		ft_print_width(strs, ' ', width_len - 1);
	}
	else
	{
		if (ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags + 1)))
			ft_print_width(strs, '0', width_len - 1);
		else
			ft_print_width(strs, ' ', width_len - 1);
		print_char(ap, strs, 1);
	}
}
