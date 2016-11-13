/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:05:10 by rnowell           #+#    #+#             */
/*   Updated: 2016/09/27 20:05:11 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen2(char const *str, int stri, char c)
{
	int len;

	len = 0;
	while (str[stri++] != c)
		len++;
	return (len);
}

static int		ft_find_ith_word(char const *s, int i, char c)
{
	int stri;

	stri = 0;
	if (i == 0)
	{
		while (s[stri] == c)
			stri++;
		return (stri);
	}
	while (s[stri])
	{
		if ((s[stri] != c) && ((s[stri - 1] == c) || (stri == 0)))
		{
			if (i == 0)
				return (stri);
			i--;
		}
		stri++;
	}
	return (-1);
}

static char		*ft_replace_word(int stri, char const *str, char *word, char c)
{
	int wordi;

	wordi = 0;
	while (str[stri] != c)
		word[wordi++] = str[stri++];
	word[wordi] = '\0';
	return (word);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**res;
	char	*word;
	int		i;
	int		stri;
	int		wc;

	wc = ft_wordcount(str, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	stri = 0;
	i = 0;
	while (i < wc)
	{
		word = 0;
		stri = ft_find_ith_word(str, i, c);
		word = (char *)malloc(ft_strlen2(str, stri, c) * sizeof(char) + 1);
		if (!word)
			return (NULL);
		word = ft_replace_word(stri, str, word, c);
		res[i] = word;
		i++;
	}
	res[i] = 0;
	return (res);
}
