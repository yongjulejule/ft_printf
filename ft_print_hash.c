/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/19 02:11:16 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hash(t_lidx *strs)
{
	if (!ft_memchr(strs->txt, '#', (size_t)(strs->opts.flags + 1)))
		if (strs->txt[strs->opts.spec] != 'p')
			return ;
	if (strs->txt[strs->opts.spec] == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
	strs->info += 2;
}
