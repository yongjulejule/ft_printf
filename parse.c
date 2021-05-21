/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:12:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/21 17:45:08 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		get_flags(t_lidx **str)
{
	t_lidx *tmp;

	tmp = *str;
	while (tmp)
	{
		check_n_opt(tmp);
		tmp = (tmp)->next;
	}
	return 0;
}

static	int		free_splited(char **line)
{
	int	idx;

	idx = 0;
	while (*(line + idx))
	{
		free(*(line + idx));
		idx++;
	}
	free(*(line + idx));
	free(line);
	return (ERROR_FLAG);
}

int				parsing(char *formet, t_lidx **strs)
{
	char	**line;
	int		idx;

	line = ft_split(formet, '%');
	if (!line)
		return (free_splited(line));
	(*strs) = ft_lidxnew(*line, IS_CHRS);
	if (*formet == '%')
		(*strs)->order = 0;
	idx = 1;
	while (*(line + idx))
	{
		ft_lidxadd_back(strs, ft_lidxnew(*(line + idx), idx));
		idx++;
	}
	free_splited(line);
	get_flags(strs);
	return (ERROR_FLAG);
}
