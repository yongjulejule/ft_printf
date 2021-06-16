/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:22:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 01:04:21 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_decimal(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == 'n')
		ft_putnbr_fd(-1, 1);
	else
	{
		ft_print_deci(ap, strs);
	}
	return (0);
}

static	int	print_hex(va_list ap, t_lidx *strs)
{
	ft_print_hexa()
	return (0);
}

static	int	print_chrs(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == '%')
		ft_putchar_fd('%', 1);
	else
	{
		if (strs->txt[strs->opts.spec] == 'c')
			ft_print_char(ap, strs);
		else
			ft_print_str(ap, strs);
	}
	return (1);
}

static	int	print_args(va_list ap, t_lidx *strs)
{
	int idx;
	int len;

	idx = 0;
	len = 0;
	while (idx < (int)ft_strlen(SPECS))
	{
		if (strs->txt[strs->opts.spec] == SPECS[idx])
		{
			if (idx < 4)
				len = print_decimal(ap, strs);
			else if (idx < 7)
				len = print_hex(ap, strs);
			else
				len = print_chrs(ap, strs);
			break ;
		}
		idx++;
	}
	return (len);
}

/*
** print arguments and strings
*/

int			go_print(va_list ap, t_lidx *strs)
{
	int len;

	len = 0;
	while (strs)
	{
		if (strs->order == IS_NOT_FLAG)
		{
			ft_putstr_fd(strs->txt, 1);
			len += ft_strlen(strs->txt);
		}
		else
			print_args(ap, strs);
		strs = strs->next;
	}
	return (len);
}
