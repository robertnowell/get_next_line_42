/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:25:08 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/29 16:25:10 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zero(char *res)
{
	int			i;

	i = 0;
	res[i] = '0';
	res[++i] = '\0';
	return (res);
}

char			*ft_itoa_base(int nbr, int base)
{
	int			rem;
	char		*res;
	long		n;
	int			i;

	i = 0;
	n = nbr;
	n *= (nbr < 0) ? -1 : 1;
	if (!(res = ft_strnew(ft_count_digits(nbr, base))))
		return (NULL);
	if (n == 0)
		return (ft_zero(res));
	while (n != 0)
	{
		rem = n % (long)base;
		n /= (long)base;
		res[i++] = (rem + '0');
	}
	if (nbr < 0)
	{
		res[i] = '-';
		return (ft_strrev(res));
	}
	return (ft_strrev(res));
}
