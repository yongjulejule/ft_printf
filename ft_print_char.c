/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:38:05 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/16 22:19:44 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_char(va_list ap, t_lidx *strs, int len)
{
	char	c;
	wchar_t	wc;

	if (get_length_flag(strs) == 3 || get_length_flag(strs) == 4)
	{
		wc = va_arg(ap, int);
		ft_putchar_utf_fd(wc, 1);
	}
	else
	{
		c = va_arg(ap, int);
		ft_putchar_fd(c, 1);
	}
	strs->opts.precision = len;
}

static	int		width_in_char(va_list ap, t_lidx *strs, int width_len)
{
	int	len;

	len = ft_utf_byte_chr_len(ap);
	if (width_len < len)
		return (0);
	if (get_length_flag(strs) == 3 || get_length_flag(strs) == 4)
	{
		if (width_len > 0)
			width_len -= len;
		else
			width_len += len;
	}
	return (width_len);
}

void			ft_print_char(va_list ap, t_lidx *strs)
{
	int		width_len;
	int		precision_len;

	width_len = get_width_len(ap, strs);
	precision_len = get_precision_len(ap, strs);
	width_len = width_in_char(ap, strs, width_len);
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
