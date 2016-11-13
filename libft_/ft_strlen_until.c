/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:39:27 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:39:30 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_until(char *s, char c)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			return (len);
		len++;
	}
	return (len);
}
