/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:35:36 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:35:39 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	ft_result(const char *str, int sign)
{
	int			count;
	long long	rs;

	rs = 0;
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		count++;
		rs = rs * 10 + *str - '0';
		str++;
	}
	if (count >= 19 && sign == 1)
		return (-1);
	if (count >= 19 && sign == -1)
		return (0);
	return (rs);
}

static	int		ft_checkspecial(const char *str)
{
	if (ft_isprint(*str) || *str == '\t' || *str == '\v' || *str == '\f' \
							|| *str == '\r' || *str == '\n')
		return (0);
	else
		return (1);
}

int				ft_atoi(char const *str)
{
	int			sign;
	long long	rs;

	if (!*str)
		return (0);
	rs = 0;
	sign = 1;
	if (ft_checkspecial(str))
		return (0);
	while (*str <= ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			return (0);
	}
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	rs = ft_result(str, sign);
	return (rs * sign);
}
