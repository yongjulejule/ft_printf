/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:45:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/22 11:08:14 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

# define IS_ERR -2
# define IS_CHRS -1
# define IS_FLAGS 1
# define ERROR_FLAG 0
# define SUCCESS_FLAG 1
# define ASTERISK -1

typedef struct	s_opts
{
	int	n_opt;
	int	flags;
	int	width;
	int precision;
	int length;
	int specifier;
}				t_opts;

typedef struct	s_lidx
{
	int				order;
	char			*txt;
	struct s_lidx	*next;
	struct s_opts	opts;
}				t_lidx;
int	parsing(char *formet, t_lidx **strs);
int	ft_printf(const char *formet, ...);
void	check_specifier(t_lidx *str);
void	check_n_opt(t_lidx *str);

/*
** handle lists
*/

void			ft_lidxadd_back(t_lidx **lst, t_lidx *newnode);
void			ft_lidxclear(t_lidx **lst, void (*del)(void*));
void			ft_lidxdelone(t_lidx *lst, void (*del)(void*));
t_lidx			*ft_lidxnew(void *txt, int order);
t_lidx	*ft_lidxlast(t_lidx *lst);

#endif
