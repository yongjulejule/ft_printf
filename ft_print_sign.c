/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/14 22:06:06 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_sign(va_list ap, t_lidx *strs)
{
	va_list cp_ap;
	int		nbr;

	va_copy(cp_ap, ap);
	nbr = va_arg(cp_ap, int);
	va_end(cp_ap);
	if (nbr < 0)
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
