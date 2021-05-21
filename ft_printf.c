/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:25:28 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/21 16:18:59 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*void	printstrings(char *str, ...)
{
	va_list	ap;
	int		idx;
	char	*tmp;
	idx = 0;
	tmp = str;
	va_start(ap, str);
	while (idx < 8)
	{
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
		idx++;
		tmp = va_arg(ap, char*);
	}
}*/


int		ft_printf(const char *formet , ...)
{
//	va_list ap;
//	t_lidx	*arg;
	t_lidx *strs;

	if (!parsing((char*)formet, &strs))
		return (ERROR_FLAG);
/*	arg = ft_lidxnew(NULL, IS_FLAGS);
	arg->next;
		va_start(ap, formet);
*/	return (1);
}

#include <stdio.h>
int main()
{
	ft_printf("really%2$-+0 *.123dbc");
	printf("%c",(char)-200);
}
