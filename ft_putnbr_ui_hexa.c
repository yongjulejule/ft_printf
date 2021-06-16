/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 00:20:58 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/17 01:58:25 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dgt_ui_len(t_ui nbr, unsigned int base)
{
	int cnt;

	cnt = 0;
	if (base < 2)
		return (0);
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		nbr /= base;
		cnt++;
	}
	return (cnt);
}

static	void	make_nbr(t_lidx *strs, t_ui n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	if (strs->txt[strs->opts.spec] == 'X')
		c = HEX_L[n % 16];
	else
		c = HEX_S[n % 16];
	n /= 16;
	make_nbr(strs, n, fd);
	write(fd, &c, 1);
}

void			ft_putnbr_ui_hexa_fd(t_lidx *strs, t_ui n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	make_nbr(strs, n, fd);
}
