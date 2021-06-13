/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:22 by yongjule          #+#    #+#             */
/*   Updated: 2021/05/11 21:59:41 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*go_to_digit(char *str, int *sign)
{
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		*sign = -1;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	sign = 1;
	num = 0;
	str = go_to_digit((char*)str, &sign);
	if (ft_strlen(str) >= 20 && *(str + 20) >= '0' && *(str + 20) <= '9')
	{
		if (sign < 0)
			return (0);
		else
			return (-1);
	}
	while (*str >= '0' && *str <= '9')
		num = 10 * num + (*str++ - '0');
	if (num > 9223372036854775807)
	{
		if (sign < 0)
			return (0);
		else
			return (-1);
	}
	return (sign * num);
}
