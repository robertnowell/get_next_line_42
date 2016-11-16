/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_tstruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:49:25 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:49:27 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_tstruct(t_struct **alst)
{
	ft_strdel(&((*alst)->s));
	(*alst)->fdesc = 0;
	(*alst)->index = NULL;
	free(*alst);
	*alst = NULL;
}
