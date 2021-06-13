/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:25:28 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/13 04:55:36 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_lidx	*strs;

	if (!parsing((char*)format, &strs))
		return (ERROR_FLAG);
	va_start(ap, format);
	go_print(ap, strs);
	return (1);
}
