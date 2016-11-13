/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 19:27:52 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/29 19:27:53 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	f(int a, int b)
{
	if (a < b)
		return (-1);
	if (a == b)
		return (0);
	else
		return (1);
}
