/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:22:43 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/11 16:02:26 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

"cspdiuxXfge%"

int handle_spec(va_list ap, t_lidx *strs)
{
	if (strs->txt[strs->opts.spec] == 'd' || strs->txt[strs->opt.spec] == 'i')
		print_decimal();
	else if (strs->txt[strs->opts.spec] == )

}


int go_print(va_list ap, t_lidx *strs)
{
	int len;

	len = 0;
	while (strs)
	{
		if (strs->order == IS_CHRS)
		{
			ft_putstr_fd(strs->txt, 1);
			len += ft_strlen(strs->txt);
		}
		else
			handle_spec(ap, strs);
		strs = strs->next;
	}
}
