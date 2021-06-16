/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_uft_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:14:41 by yongjule          #+#    #+#             */
/*   Updated: 2021/06/16 12:42:55 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	putchar_utf_4(t_ui uni, int fd)
{
	unsigned char	bits[4];
	int				idx;

	idx = 0;
	while (idx < 3)
	{
		bits[idx] = (unsigned char)(UTF_MASK_0 | uni);
		uni >>= 6;
		idx++;
	}
	bits[3] = (unsigned char)(UTF_MASK_3 | uni);
	idx = 0;
	while (idx < 4)
	{
		write(fd, &bits[idx], 1);
		idx++;
	}
}

static void	putchar_utf_3(t_ui uni, int fd)
{
	unsigned char	bits[3];
	int				idx;

	idx = 0;
	while (idx < 2)
	{
		printf("%x\n", uni);
		bits[idx] = (unsigned char)(UTF_MASK_0 | (uni & 0x3F));
		uni >>= 6;
		idx++;
	}
	printf("%x\n", uni);
	bits[2] = (unsigned char)(UTF_MASK_3 | uni);
	idx = 0;
	while (idx < 3)
	{
		printf("bits idx %d : %x\n", idx,  bits[idx]);
		write(fd, &bits[idx], 1);
		idx++;
	}
}

static void	putchar_utf_2(t_ui uni, int fd)
{
	unsigned char	bits[2];

	bits[0] = (unsigned char)(UTF_MASK_0 | uni);
	uni >>= 6;
	bits[1] = (unsigned char)(UTF_MASK_2 | uni);
	write(fd, &bits[0], 1);
	write(fd, &bits[1], 1);
}

static void	putchar_utf_1(t_ui uni, int fd)
{
	write(fd, &uni, 1);
}

void	ft_putchar_utf_fd(t_ui uni, int fd)
{
	if (uni <= UTF_8_1)
		putchar_utf_1(uni, fd);
	else if (uni <= UTF_8_2)
		putchar_utf_2(uni, fd);
	else if (uni <= UTF_8_3)
		putchar_utf_3(uni, fd);
	else if (uni <= UTF_8_4)
		putchar_utf_4(uni, fd);
	else
		ft_putchar_fd(uni, fd);
}

int main()
{
	ft_putchar_utf_fd(0x6C24, 1);
}
