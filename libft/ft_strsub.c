/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 19:59:43 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/27 19:59:44 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = ft_strnew(len);
	if (!result)
		return (NULL);
	while (len--)
		result[len] = s[start + len];
	return (result);
}
