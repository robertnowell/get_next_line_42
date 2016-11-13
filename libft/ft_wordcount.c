/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:10:07 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/29 17:10:08 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(char const *str, char c)
{
	int i;
	int wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (wc == 0)
				wc++;
			else if (str[i - 1] == c)
				wc++;
		}
		i++;
	}
	return (wc);
}
