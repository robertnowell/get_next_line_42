/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 01:54:02 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/13 01:54:04 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#define NEWL '\n'

void	ft_set_values(char **line, char **current, char **tmp, char **index)
{
	*line = ft_strdup_until(*current, '\n');
	*tmp = ft_strdup(*index + 1);
	free(*current);
	*current = ft_strdup(*tmp);
}

int		read_line(int fd, char **current)
{
	char		buf[BUFF_SIZE + 1];
	int			bytes;
	char		*new;

	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes > 0)
	{
		buf[bytes] = '\0';
		new = current ? ft_strjoin(*current, buf) : buf;
		if (!new)
			return (-1);
		free(*current);
		*current = new;
	}
	return (bytes);
}

int		get_next_line(int const fd, char **line)
{
	static char *current = NULL;
	char		*index;
	char		*tmp;
	int			ret;

	if (!line || fd == -1)
		return (-1);
	index = current ? ft_strchr(current, NEWL) : NULL;
	while (index == NULL)
	{
		ret = read_line(fd, &current);
		if (ret == 0)
		{
			if ((index = ft_strchr(current, '\0')) == current)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			index = ft_strchr(current, NEWL);
	}
	ft_set_values(line, &current, &tmp, &index);
	free(tmp);
	return (1);
}
