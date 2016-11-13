/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:04:49 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/27 20:04:51 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nonwhitespace_len(char const *s)
{
	int		len;

	len = 0;
	while (*s != '\0')
	{
		if (*s > ' ')
			break ;
		s++;
	}
	while (*s)
	{
		s++;
		len++;
	}
	s--;
	while (*s <= ' ')
	{
		len--;
		s--;
	}
	return (len);
}

static int			ft_check_empty(const char *s)
{
	while (*s != '\0')
	{
		if (*s++ > ' ')
			return (0);
	}
	return (1);
}

char				*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	if (ft_check_empty(s))
		return ("");
	len = ft_nonwhitespace_len(s);
	if (!(new = malloc(len + 1)))
		return (NULL);
	while (*s <= ' ')
		s++;
	while (len)
	{
		new[i] = *s;
		s++;
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
