/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:20:29 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:20:31 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_struct	*ft_lst_clone(t_struct *node)
{
	t_struct *res;

	if (node == NULL)
		return (NULL);
	res = ft_create_elem(node->s, node->fdesc, node->index);
	res->next = ft_lst_clone(node->next);
	return (res);
}
