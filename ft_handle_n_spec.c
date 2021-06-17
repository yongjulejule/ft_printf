/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_n_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:51:00 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 14:45:38 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_n_spec(va_list ap, t_lidx *strs, t_ull total_len)
{
	int	flag;

	flag = get_length_flag(strs);
	if (flag == 1)
		get_uchar_byte(ap, total_len);
	else if (flag == 2)
		get_ushort_byte(ap, total_len);
	else if (flag == 3)
		get_ul_byte(ap, total_len);
	else if (flag == 4)
		get_ull_byte(ap, total_len);
	else
		get_ui_byte(ap, total_len);
}
