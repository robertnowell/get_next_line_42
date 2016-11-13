/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:57:02 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:57:03 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function dups a string up until a character, c,
** is found in the source string.
*/

char	*ft_strdup_until(char *s, char c)
{
	char		*result;
	int			i;

	i = 0;
	if (!(result = (char *)malloc(ft_strlen_until(s, '\n') + 1)))
	{
		return (result);
	}
	if (!s)
	{
		result = ft_strnew(1);
		ft_bzero(result, 1);
	}
	while (s[i] && s[i] != c)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
