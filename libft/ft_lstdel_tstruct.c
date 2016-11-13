/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_tstruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:52:07 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 10:52:10 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_tstruct(t_struct **alst)
{
	t_struct *next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone_tstruct(alst);
		*alst = next;
	}
}
