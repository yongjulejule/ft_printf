/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:15:21 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/13 15:06:46 by yongjule         ###   ########.fr       */
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

void			ft_print_str(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	int		precision_len;
	int		width_len;

	precision_len = get_precision_len(ap, strs);
	va_copy(cp_ap, ap);
	if (precision_len < 0)
		precision_len = ft_strlen(va_arg(cp_ap, char*));
	va_end(cp_ap);
	width_len = get_width_len(ap, strs);
	if (ft_memchr(strs->txt, '-', (size_t)(strs->opts.flags)) != NULL || width_len < 0)
	{
		width_len *= -1;
		print_str(ap, strs, precision_len);
		ft_print_width(strs, ' ', width_len - precision_len);
	}
	else
	{
		if (ft_memchr(strs->txt, '0', (size_t)(strs->opts.flags)) != NULL)
			ft_print_width(strs, '0', width_len - precision_len);
		else
			ft_print_width(strs, ' ', width_len - precision_len);
		print_str(ap, strs, precision_len);
	}
}
