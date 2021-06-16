/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:07:09 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 07:31:20 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hash(t_lidx *strs)
{
	if (!ft_memchr(strs->txt, '#', (size_t)(strs->opts.flags + 1)))
		return ;
	if (strs->txt[strs->opts.spec] == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
}
