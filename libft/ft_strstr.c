/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:22:06 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/25 11:22:07 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*haystack && !*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
