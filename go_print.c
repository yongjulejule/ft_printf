/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:22:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/13 16:57:43 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_decimal(va_list ap, t_lidx *strs)
{
	strs->txt[0]='D';
	ap = 0;
	return (0);
}

static	int	print_hex(va_list ap, t_lidx *strs)
{
	strs->txt[0]='H';
	ap = 0;
	return (0);
}

static	int	print_chrs(va_list ap, t_lidx *strs)
{
	//percent는 초반에 처리해도 될 것 같은디...
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

int go_print(va_list ap, t_lidx *strs)
{
	int len;

	len = 0;
	while (strs)
	{
		if (strs->order == IS_NOT_FLAG)
		{
			ft_putstr_fd(strs->txt, 1);
			//len += ft_strlen(strs->txt);
		}
		else
			print_args(ap, strs);
		strs = strs->next;
	}
	return (len);
}
