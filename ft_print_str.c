/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:15:21 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/14 23:04:57 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_str(va_list ap, t_lidx *strs, int len)
{
	char	*s;
	int		idx;

	idx = 0;
	s = va_arg(ap, char*);
	while (idx < len)
	{
		ft_putchar_fd(s[idx], 1);
		idx++;
	}
	strs->opts.precision = len;
}

static	int		precision_in_str(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	int		len;
	int		tmplen;

	len = get_precision_len(ap, strs);
	va_copy(cp_ap, ap);
	tmplen = ft_strlen(va_arg(cp_ap, char*));
	if (len < 0 || len > tmplen)
		len = tmplen;
	va_end(cp_ap);
	return (len);
}

/*
** print string with flags
*/

void			ft_print_str(va_list ap, t_lidx *strs)
{
	int		precision_len;
	int		width_len;

	width_len = get_width_len(ap, strs);
	precision_len = precision_in_str(ap, strs);
	if (ft_memchr(strs->txt, '-', (size_t)(strs->opts.flags + 1))\
			|| width_len < 0)
	{
		if (width_len < 0)
			width_len *= -1;
		print_str(ap, strs, precision_len);
		ft_print_width(strs, ' ', width_len - precision_len);
	}
	else
	{
		if (ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags + 1)))
			ft_print_width(strs, '0', width_len - precision_len);
		else
			ft_print_width(strs, ' ', width_len - precision_len);
		print_str(ap, strs, precision_len);
	}
}
