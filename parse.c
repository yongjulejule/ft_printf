/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:12:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/11 22:47:58 by yongjule         ###   ########.fr       */
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
		backup = ft_substr((cur->txt), cur->opts.spec + 1,
				ft_strlen(cur->txt));
		if (!backup)
			return (ERROR_FLAG);
		newnode = ft_lidxnew(backup, IS_CHRS);
		if (!newnode)
		{
			free(backup);
			return (ERROR_FLAG);
		}
		cur->txt[cur->opts.spec + 1] = '\0';
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

int				parsing(char *formet, t_lidx **strs)
{
	char	**line;
	int		idx;

	line = ft_split(formet, '%');
	if (!line)
		return (ERROR_FLAG);
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
	if (!get_flags(strs))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
