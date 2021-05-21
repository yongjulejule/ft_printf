/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:21:01 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/21 16:31:36 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_length(t_lidx *str)
{
	int idx;

	idx = str->opts.precision;
	idx++;
	if (str->txt[idx] == 'h')
	{
		idx++;
		if (str->txt[idx] == 'h')
			idx++;
	}
	else if (str->txt[idx] == 'l')
	{
		idx++;
		if (str->txt[idx] == 'l')
			idx++;
	}
	idx--;
	str->opts.length = idx;
	check_specifier(str);
}

static void	check_precision(t_lidx *str)
{
	int idx;

	idx = str->opts.width;
	idx++;
	if (str->txt[idx] == '.')
	{
		idx++;
		while (ft_isdigit(str->txt[idx]))
			idx++;
	}
	idx--;
	str->opts.precision = idx;
	check_length(str);
}

static void	check_width(t_lidx *str)
{
	int idx;

	idx = str->opts.flags;
	idx++;
	if (str->txt[idx] > '0' && str->txt[idx] <= '9')
		while (ft_isdigit(str->txt[idx]))
			idx++;
	else if (str->txt[idx] == '*')
		idx++;
	idx--;
	str->opts.width = idx;
	check_precision(str);
}

static void	check_flags(t_lidx *str)
{
	int idx;

	idx = str->opts.n_opt;
	idx++;
	while (str->txt[idx] == '-'
			|| str->txt[idx] == '+'
			|| str->txt[idx] == ' '
			|| str->txt[idx] == '0')
//			|| str->txt[idx] == '#')
		idx++;
	idx--;
	str->opts.flags = idx;
	check_width(str);
}

void	check_n_opt(t_lidx *str)
{
	int idx;

	idx = 0;
	while (ft_isdigit(str->txt[idx]) && str->txt[idx] != '\0')
		idx++;
	if (str->txt[idx] == '$')
		str->opts.n_opt = idx;
	check_flags(str);
}
