/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 01:20:31 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hash(va_list ap, t_lidx *strs)
{
	if (!ft_memchr(strs->txt, '#', (size_t)(strs->opts.flags + 1)))
		return (0);
	if (strs->txt[strs->opts.spec] == 'X')
		ft_putstr_fd("0X", 1);
	else 
		ft_putstr_fd("0x", 1);
	return (2);
}
