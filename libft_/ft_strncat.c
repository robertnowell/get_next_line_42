/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:19:26 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:19:28 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		l;

	l = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (dest);
}
