/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:06:33 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:06:37 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *one;
	const unsigned char *two;

	one = (const unsigned char *)s1;
	two = (const unsigned char *)s2;
	while (n)
	{
		if (*one != *two)
			return (*one - *two);
		n--;
		one++;
		two++;
	}
	return (0);
}
