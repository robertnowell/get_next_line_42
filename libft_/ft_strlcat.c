/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:19:02 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:19:04 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_copy(const char *src_cpy, char *dst_cpy, int count)
{
	while (*src_cpy)
	{
		if (count != 1)
		{
			*dst_cpy++ = *src_cpy;
			count--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (src_cpy);
}

size_t				ft_strlcat(char *dst, char const *src, size_t size)
{
	char		*dst_cpy;
	const char	*result;
	const char	*src_cpy;
	size_t		count;
	size_t		max;

	dst_cpy = dst;
	src_cpy = src;
	count = size;
	max = 0;
	while (count && *dst_cpy)
	{
		max++;
		dst_cpy++;
		count--;
	}
	if (!(count = size - max))
		return (max + ft_strlen(src_cpy));
	result = ft_copy(src_cpy, dst_cpy, count);
	return (max + (result - src));
}
