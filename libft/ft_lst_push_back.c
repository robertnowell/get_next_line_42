/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:24:46 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 11:24:47 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_struct **l, char *s, int fd, char *s2)
{
	t_struct *list;

	list = *l;
	if (!*l)
		*l = ft_create_elem(s, fd, s2);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(s, fd, s2);
	}
}
