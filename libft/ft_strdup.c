/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:18:35 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/24 15:18:36 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = (char *)malloc(ft_strlen(s) + 1)))
	{
		return (result);
	}
	if (!s)
	{
		result = ft_strnew(1);
		ft_bzero(result, 1);
	}
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
