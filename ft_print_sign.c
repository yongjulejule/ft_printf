/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/15 09:55:58 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_sign(va_list ap, t_lidx *strs)
{
	int i;

	if (is_this_length(strs) == 3 || is_this_length(strs) == 4)
		i = (va_arg(ap, long) >> 63);
	else if (is_this_length(strs) == 2)
		i = ((char)va_arg(ap, int) >> 7);
	else if (is_this_length(strs)== 1)
		i = ((short)va_arg(ap, int) >> 15);
	else
		i = (va_arg(ap, int) >> 31);
	return (i);
}

void		ft_print_sign(va_list ap, t_lidx *strs)
{
	va_list	cp_ap;
	int sign;

	if (strs->txt[strs->opts.spec] == 'u')
		return ;
	va_copy(cp_ap, ap);
	sign = get_sign(cp_ap, strs);
	va_end(cp_ap);
	if (sign < 0)
		ft_putchar_fd('-', 1);
	else
	{
		if (ft_memchr(strs->txt, '+', (size_t)(strs->opts.flags + 1)))
			ft_putchar_fd('+', 1);
		else if (ft_memchr(strs->txt, ' ', (size_t)(strs->opts.flags + 1)))
			ft_putchar_fd(' ', 1);
		else
			return ;
	}
}
