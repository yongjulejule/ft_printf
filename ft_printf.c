/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:25:28 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/11 12:49:47 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_printf(const char *formet, ...)
{
	va_list	ap;
//	t_lidx	*arg;
	t_lidx	*strs;

	if (!parsing((char*)formet, &strs))
		return (ERROR_FLAG);
	va_start(ap, formet);
	go_print(ap, strs);
	return (1);
}
