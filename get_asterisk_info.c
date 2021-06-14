/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asterisk_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:31:14 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/14 14:00:53 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width_len(va_list ap, t_lidx *strs)
{
	char	*lens;
	int		len;

	if (strs->opts.flags == strs->opts.width)
		return (0);
	if (strs->txt[strs->opts.width] == '*')
		len = va_arg(ap, int);
	else
	{
		lens = ft_substr(strs->txt, strs->opts.flags + 1,\
				strs->opts.width - strs->opts.flags);
		len = ft_atoi(lens);
		free(lens);
		lens = NULL;
	}
	return (len);
}

int		get_precision_len(va_list ap, t_lidx *strs)
{
	char	*lens;
	int		len;

	if (strs->opts.width == strs->opts.precision)
		return (-1);
	if (strs->txt[strs->opts.precision] == '*')
		len = va_arg(ap, int);
	else
	{
		lens = ft_substr(strs->txt, strs->opts.width + 2,\
				strs->opts.precision - strs->opts.width + 1);
		len = ft_atoi(lens);
		free(lens);
		lens = NULL;
	}
	return (len);
}
