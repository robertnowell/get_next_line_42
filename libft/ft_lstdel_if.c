/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:00:19 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 11:00:21 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_if(t_struct **begin_list, int fd)
{
	t_struct *list;
	t_struct *prev;
	t_struct *next;

	list = *begin_list;
	prev = NULL;
	next = NULL;
	while (list)
	{
		next = list->next;
		if (list->fdesc == fd)
		{
			ft_lstdelone_tstruct(&list);
			if (!prev)
			{
				*begin_list = next;
				return ;
			}
			list = prev;
			prev->next = next;
			return ;
		}
		prev = list;
		list = list->next;
	}
}

/*
**void	ft_lstdel_if(t_struct **begin_list, int fd)
**{
**	t_struct *list;
**	t_struct *prev;
**	t_struct *next;
**
**	list = *begin_list;
**	prev = NULL;
**	next = NULL;
**	while (list)
**	{
**		next = list->next;
**		if (list->fdesc == fd)
**		{
**			if (!prev)
**			{
**				ft_lstdelone_tstruct(&list);
**				*begin_list = next;
**				return ;
**			}
**			ft_lstdelone_tstruct(&list);
**			list = prev;
**			prev->next = next;
**			return ;
**		}
**		prev = list;
**		list = list->next;
**	}
**}
*/
