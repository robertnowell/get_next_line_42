/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:04:04 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:04:07 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_cpy;
	unsigned char const *src_cpy;

	dest_cpy = (unsigned char*)dest;
	src_cpy = (const unsigned char*)src;
	while (n--)
	{
		*dest_cpy = *src_cpy;
		if (*dest_cpy == (unsigned char)c)
			return (++dest_cpy);
		dest_cpy++;
		src_cpy++;
	}
	return (NULL);
}
