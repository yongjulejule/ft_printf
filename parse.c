/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:12:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/19 04:25:54 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		split_lst(t_lidx **str)
{
	char	*backup;
	t_lidx	*newnode;
	t_lidx	*cur;

	cur = *str;
	while (1)
	{
		backup = ft_substr((cur->txt), cur->opts.spec + 1, ft_strlen(cur->txt));
		if (!backup)
			return (ERROR_FLAG);
		newnode = ft_lidxnew(backup, IS_NOT_FLAG);
		free(backup);
		if (!newnode)
		{
			ft_lidxclear(str, free);
			return (ERROR_FLAG);
		}
		newnode->next = cur->next;
		cur->next = newnode;
		cur = newnode->next;
		if (!cur)
			return (SUCCESS_FLAG);
	}
}

static	int		get_flags(t_lidx **str)
{
	t_lidx *tmp;

	tmp = *str;
	while (tmp)
	{
		check_flags(tmp);
		tmp = (tmp)->next;
	}
	if (!split_lst(str))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}

static	void	free_splited(char **line)
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
}

int				parsing(char *format, t_lidx **strs)
{
	char	**line;
	int		idx;

	if (*format == '%')
		line = ft_weak_split(format + 1, '%');
	else
		line = ft_weak_split(format, '%');
	if (!line)
		return (ERROR_FLAG);
	(*strs) = ft_lidxnew(*line, IS_NOT_FLAG);
	if (*format == '%')
		(*strs)->info = 0;
	idx = 1;
	while (*(line + idx))
	{
		if (line[idx - 1][0] == '%' && (idx > 1 && line[idx - 2][0] == '%'))
			ft_lidxadd_back(strs, ft_lidxnew(*(line + idx), IS_NOT_FLAG));
		else
			ft_lidxadd_back(strs, ft_lidxnew(*(line + idx), 0));
		idx++;
	}
	free_splited(line);
	if (!get_flags(strs))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
