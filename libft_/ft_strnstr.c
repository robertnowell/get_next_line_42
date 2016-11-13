/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:19:55 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:19:56 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	if (!*haystack && !*needle)
		return ("");
	while (*haystack)
	{
		if (n < ft_strlen(needle))
			break ;
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
