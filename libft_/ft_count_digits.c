/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:10:14 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/29 17:10:15 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(int nbr, int base)
{
	int			digits;
	long		num;

	digits = 1;
	num = nbr;
	if (num < 0)
	{
		num = -num;
		digits++;
	}
	while (num / base >= 1)
	{
		num = num / base;
		digits++;
	}
	return (digits);
}
