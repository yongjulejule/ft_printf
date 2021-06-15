/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:45:17 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/15 09:57:14 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

/*
** MY MECRO
*/

# define IS_ERR -2
# define IS_NOT_FLAG -1
# define IS_FLAGS 1
# define ERROR_FLAG 0
# define SUCCESS_FLAG 1
# define ASTERISK -2
# define SPECS "diunpxXcs%"

/*
** Define Types
*/

typedef long long	t_ll;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef unsigned long long	t_ull;

/*
** HANDLE OPTIONS
*/

typedef struct	s_opts
{
	int	flags;
	int	width;
	int precision;
	int length;
	int spec;
}				t_opts;

/*
** LINKED LIST WITH OPTIONS
*/

typedef struct	s_lidx
{
	int				order;
	char			*txt;
	struct s_lidx	*next;
	struct s_opts	opts;
}				t_lidx;

int				ft_printf(const char *formet, ...);

/*
** PARSING
*/

int				parsing(char *formet, t_lidx **strs);
void			check_flags(t_lidx *str);

/*
** HANDLE LISTS
*/

void			ft_lidxadd_back(t_lidx **lst, t_lidx *newnode);
void			ft_lidxclear(t_lidx **lst, void (*del)(void*));
void			ft_lidxdelone(t_lidx *lst, void (*del)(void*));
t_lidx			*ft_lidxnew(void *txt, int order);
t_lidx			*ft_lidxlast(t_lidx *lst);

/*
** PRINTING
*/

int				go_print(va_list ap, t_lidx *strs);
int				get_width_len(va_list ap, t_lidx *strs);
int				get_precision_len(va_list ap, t_lidx *strs);
void			ft_print_sign(va_list ap, t_lidx *strs);
void			ft_print_str(va_list ap, t_lidx *strs);
void			ft_print_width(t_lidx *strs, char c, int len);
void			ft_print_char(va_list ap, t_lidx *strs);
void			ft_print_deci(va_list ap, t_lidx *strs);
void			ft_print_deci_nbr(va_list ap, t_lidx *strs);

/*
** TO HANDLE TYPE
*/

void			ft_putnbr_abs_fd(int n, int fd);
void			ft_putnbr_char_fd(char n, int fd);
void			ft_putnbr_uchar_fd(unsigned char n, int fd);
void			ft_putnbr_l_fd(long n, int fd);
void			ft_putnbr_ll_fd(t_ll n, int fd);
void			ft_putnbr_short_fd(short n, int fd);
void			ft_putnbr_ushort_fd(unsigned short n, int fd);
void			ft_putnbr_ul_fd(t_ul n, int fd);
void			ft_putnbr_ull_fd(t_ull n, int fd);
void			ft_putnbr_ui_fd(t_ui n, int fd);
int				ft_dgt_char_len(char nbr, unsigned int base);
int				ft_dgt_uchar_len(unsigned char nbr, unsigned int base);
int				ft_dgt_l_len(long nbr, unsigned int base);
int				ft_dgt_ll_len(t_ll nbr, unsigned int base);
int				ft_dgt_short_len(short nbr, unsigned int base);
int				ft_dgt_ushort_len(unsigned short nbr, unsigned int base);
int				ft_dgt_ul_len(t_ul nbr, unsigned int base);
int				ft_dgt_ull_len(t_ull nbr, unsigned int base);
int				ft_dgt_ui_len(t_ui nbr, unsigned int base);
int				get_nbr_len(va_list ap, t_lidx *strs, int base);
int				is_this_length(t_lidx *strs);
int			get_sign(va_list ap, t_lidx *strs);
#endif
