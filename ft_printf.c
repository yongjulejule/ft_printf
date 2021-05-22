/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:25:28 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/22 11:35:15 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *formet, ...)
{
	va_list	ap;
	t_lidx	*arg;
	t_lidx	*strs;

	if (!parsing((char*)formet, &strs))
		return (ERROR_FLAG);
	arg = ft_lidxnew(NULL, IS_FLAGS);
	va_start(ap, formet);
	return (1);
}
