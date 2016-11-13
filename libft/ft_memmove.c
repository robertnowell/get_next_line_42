/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:54:43 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:54:46 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	src = (char *)s2;
	dest = (char *)s1;
	if (dest <= src)
	{
		while (n--)
		{
			*dest++ = *src++;
		}
	}
	else
	{
		src += n;
		dest += n;
		while (n--)
		{
			*--dest = *--src;
		}
	}
	return (s1);
}
