/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:46:10 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 11:03:59 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_width(t_lidx *strs, char c, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		ft_putchar_fd(c, 0);
		idx++;
		strs->info++;
	}
}
