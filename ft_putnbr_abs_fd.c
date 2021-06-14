/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_abs_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:31:31 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/15 02:30:10 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_nbr(int n, int fd)
{
	int		digit;
	char	c;

	if (n == 0)
		return ;
	digit = n % 10;
	if (digit < 0)
		digit *= -1;
	c = digit + '0';
	n /= 10;
	make_nbr(n, fd);
	write(fd, &c, 1);
}

void		ft_putnbr_abs_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	make_nbr(n, fd);
}
