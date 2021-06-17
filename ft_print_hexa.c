/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:23 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 11:04:12 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		width_in_hexa(va_list ap, t_lidx *strs)
{
	int	width_len;

	width_len = get_width_len(ap, strs);
	if (ft_memchr(strs->txt, '#', (size_t)(strs->opts.flags + 1)))
	{
		if (width_len < 0)
			width_len += 2;
		else
			width_len -= 2;
	}
	return (width_len);
}

static	int		precision_in_hexa(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	int		len;
	int		tmplen;

	len = get_precision_len(ap, strs);
	va_copy(cp_ap, ap);
	tmplen = get_nbr_len(cp_ap, strs, 16);
	if (len < tmplen)
		len = tmplen;
	va_end(cp_ap);
	return (len);
}

static	void	print_dgt(va_list ap, t_lidx *strs, int len)
{
	va_list	cp_ap;
	int		dgt_len;
	int		idx;

	idx = 0;
	if (!(ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags + 1))
			&& ((strs->opts.precision == strs->opts.width)\
			|| (strs->txt[strs->opts.spec] == 'p'))))
		ft_print_hash(strs);
	va_copy(cp_ap, ap);
	dgt_len = get_nbr_len(ap, strs, 16);
	while (dgt_len < len)
	{
		ft_putchar_fd('0', 1);
		dgt_len++;
	}
	ft_print_hexa_nbr(cp_ap, strs);
	va_end(cp_ap);
	strs->info += dgt_len;
}

void			ft_print_hexa(va_list ap, t_lidx *strs)
{
	int		precision_len;
	int		width_len;

	width_len = width_in_hexa(ap, strs);
	precision_len = precision_in_hexa(ap, strs);
	if (ft_memchr(strs->txt, '-', strs->opts.flags + 1) || width_len < 0)
	{
		if (width_len < 0)
			width_len *= -1;
		print_dgt(ap, strs, precision_len);
		ft_print_width(strs, ' ', width_len - precision_len);
	}
	else
	{
		if ((ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags + 1))
			&& strs->opts.precision == strs->opts.width))
		{
			ft_print_hash(strs);
			ft_print_width(strs, '0', width_len - precision_len);
		}
		else
			ft_print_width(strs, ' ', width_len - precision_len);
		print_dgt(ap, strs, precision_len);
	}
}
