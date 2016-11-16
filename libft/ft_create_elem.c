/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:27:40 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:27:44 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_struct	*ft_create_elem(char *content, int fd, char *endl_index)
{
	t_struct *list;

	if (!(list = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	list->s = ft_strdup(content);
	list->fdesc = fd;
	list->index = endl_index;
	list->next = NULL;
	return (list);
}
