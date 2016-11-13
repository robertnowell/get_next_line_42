/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:24:08 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 11:24:09 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**this function prints the ascii numbers in a string
*/

void	ft_putstr_digits(char *s)
{
	while (*s)
		ft_putnbr(*s++);
}
