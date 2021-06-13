/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:22:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/13 02:36:41 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_decimal(va_list ap, t_lidx *strs)
{
	strs->txt[0]='a';
	ap = 0;
	return (0);
}

static	int	print_hex(va_list ap, t_lidx *strs)
{
	strs->txt[0]='a';
	ap = 0;
	return (0);
}

static	int	print_chrs(va_list ap, t_lidx *strs)
{
	//	handle_chrs_flag(strs);
	if (strs->txt[strs->opts.spec] == '%')
		ft_putchar_fd('%', 1);
	else //va_arg로 인자 가져와서 최종 print
		if (strs->txt[strs->opts.spec] == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		else
			ft_putstr_fd(va_arg(ap, char*), 1);
	return (1);
}

static	int	handle_spec(va_list ap, t_lidx *strs)
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


int go_print(va_list ap, t_lidx *strs)
{
	int len;

	len = 0;
	while (strs)
	{
		if (strs->order == IS_NOT_FLAG)
		{
			ft_putstr_fd(strs->txt, 1);
			//			len += ft_strlen(strs->txt);
		}
		else
			handle_spec(ap, strs);
		strs = strs->next;
	}
	return (len);
}
