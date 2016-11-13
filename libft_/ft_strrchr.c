/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:20:17 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:20:19 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = ft_strlen(s) - 1;
	if (str[i + 1] == c)
		return (&str[i + 1]);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
