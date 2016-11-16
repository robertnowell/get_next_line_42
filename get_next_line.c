/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnowell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:10:55 by rnowell           #+#    #+#             */
/*   Updated: 2016/11/14 23:10:56 by rnowell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

#define ENDL '\n'

t_struct	*find_fd(t_struct **begin_list, int fd)
{
	t_struct *list;

	list = *begin_list;
	while (list)
	{
		if (list->fdesc == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int			read_line(int fd, t_struct **list)
{
	char		*buf;
	int			bytes;
	char		*new;

	buf = ft_strnew(BUFF_SIZE + 1);
	buf = ft_memset(buf, ENDL, BUFF_SIZE + 1);
	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes > 0)
	{
		buf[bytes] = '\0';
		if ((*list)->s)
			new = ft_strjoin((*list)->s, buf);
		else
			new = ft_strdup(buf);
		if (!new)
			return (-1);
		ft_strdel(&((*list)->s));
		(*list)->s = ft_strdup(new);
		ft_strdel(&new);
		ft_strdel(&buf);
	}
	return (bytes);
}

void		ft_stuffs(char **line, t_struct **l, t_struct **list, t_struct **n)
{
	char		*tmp;

	*line = ft_strdup_until((*l)->s, '\n');
	tmp = *((*l)->index) != 0 ? ft_strdup((*l)->index + 1) : ft_strdup("");
	free((*l)->s);
	(*l)->s = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_lstdel_tstruct(list);
	*list = ft_lst_clone(*n);
	ft_lstdel_tstruct(n);
}

int			ft_doublestuffs(int ret, t_struct **node, int fd, t_struct **list)
{
	t_struct	*l;

	l = find_fd(node, fd);
	if (ret == 0)
	{
		if (((l)->index = ft_strchr((l)->s, '\0')) == (l)->s)
		{
			ft_lstdel_if(node, fd);
			*list = ft_lst_clone(*node);
			ft_lstdel_tstruct(node);
			return (0);
		}
	}
	else if (ret < 0)
		return (-1);
	else
		(l)->index = ft_strchr((l)->s, ENDL);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_struct		*list = NULL;
	t_struct			*node;
	t_struct			*current;
	int					ret;

	if (!line || fd == -1 || (!list && (!(list = ft_create_elem("", fd, "")))))
		return (-1);
	node = ft_lst_clone(list);
	current = find_fd(&node, fd);
	if (!current)
	{
		ft_lst_push_back(&node, "", fd, "");
		current = find_fd(&node, fd);
	}
	current->index = ft_strchr(current->s, ENDL);
	while (current->index == NULL)
	{
		if ((ret = read_line(fd, &current)) == -1)
			return (-1);
		if (ft_doublestuffs(ret, &node, fd, &list) <= 0)
			return (0);
	}
	ft_stuffs(line, &current, &list, &node);
	return (1);
}
