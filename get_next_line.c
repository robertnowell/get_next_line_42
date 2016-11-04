/*
	Make sure that your function behaves well when it reads from a file, 
		from the standard output, from a redirection etc

    when there is an empty line in a file, my file won't read anything after that
    when the buffer size is very large.


struct: string, fd, file index, and #bytes read.
*/

#include <fcntl.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line.h"

#define ENDL '\n'

// int	read_line(int  fd, char **stock)
// {
// 	char	buf[BUFF_SIZE+1] = { ENDL };
// 	int			bytes;
//     char        *new;
//     // printf("entering read_line\n");
//     bytes = read(fd, buf, BUFF_SIZE);
//     // printf("buf=%s", buf);
//     // printf("=buf\n");
//     // printf("bytes: %d\n", bytes);
//     if (bytes > 0)
//     {
//     	buf[bytes] = '\0';
//     	new = ft_strjoin(*stock, buf);
//     	if (!new)
//     		return (-1);
//     	free(*stock);
//     	*stock = new;
//     }
//     return (bytes);
// }

// int get_next_line(int const fd, char **line)
// {
// 	static char	*stock = NULL;
// 	char		*endl_index;
//     char        *tmp;
//     int         ret;
//     int         a;
//     if (!stock && (!(stock = (char *)ft_memalloc(sizeof(char)))))
//         return (-1);
//     if (!line || fd == -1)
//         return(-1);

//     // when would stock ever start with a value != NULL?
//     //if endl_index == NULL instead of ft_strchr(stock, ENDL), then occasionally a 
//     //loop will be entered for buffsize 16 or 32

//     //this allows us to, if our previous run through caught more than one new line,
//     //skip a read this time.
//     // if (fd == prev_fd)
//     //     endl_index == NULL;
// 	endl_index = ft_strchr(stock, ENDL);
//     // endl_index = ft_strdup(ft_strchr(stock, ENDL));

//     // printf("stock1=%s", stock);
//     // printf("=stock1\n");
//     // printf("endl found in stock? %d\n", endl_index != NULL);
// 	while (endl_index == NULL)
// 	{
//         ret = read_line(fd, &stock);
//         // printf("stock2=%s", stock);
//         // printf("=stock2\n");
//         if (ret == 0)
//         {
//             if ((endl_index = ft_strchr(stock, '\0')) == stock)
//             {
//                 // printf("stock[0] == '/0'? %d\n", stock[0] == '\0');
//                 return (0);
//         	}
//         }
//         else if (ret < 0)
//         {
//             return (-1);
//         }
//         else
//         {
//             endl_index = ft_strchr(stock, ENDL);
//         }
//     }
//     // printf("endl_index+1=%s", endl_index + 1);
//     // printf("=endl_index+1\n");
//     a = 0;

//     *line = ft_strnew(100000);
// 	while (stock[a])
// 	{
//        if (stock[a] == '\n')
//            break;
// 		(*line)[a] = stock[a];
// 		a++;
// 	}

//     tmp = ft_strdup(endl_index+1);
//     free(stock);
//     stock = ft_strdup(tmp);
//     // printf("stock3=%s", stock);
//     // printf("=stock3\n");
//     // a = 1;
//     // while (endl_index[a])
//     // {
//     //     stock[a] = endl_index[a];
//     //     a++;
//     // }
//     //if the following is not done, then either one gets stuck in a loop or skips empty lines.

//     // free(endl_index);
// 	return (1);
// }

t_struct *ft_create_elem(char *content, int fd, char *endl_index)
{
    t_struct *list;

    if (!(list = (t_struct *)malloc(sizeof(t_struct))))
        return (0);
    // if (!content)
    // {
    //     list->s = ft_strnew(1);
    //     ft_bzero(list->s, 1);
    // }
    // else
        list->s = content;
    list->fdesc = fd;
    // if (!endl_index)
    // {
    //     list->index = ft_strnew(1);
    //     ft_bzero(list->index, 1);
    // }
    // else
        list->index = endl_index;
    list->next = NULL;
    return (list);
}

void ft_list_push_back(t_struct **begin_list, char *content, int fd, char*endl_index)
{
    t_struct *list = *begin_list;
    if (!*begin_list)
        *begin_list = ft_create_elem(content, fd, endl_index);
    else
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem(content, fd, endl_index);
    }
}

t_struct *find_fd(t_struct **begin_list, int fd)
{
    t_struct *list = *begin_list;
    while (list)
    {
        if (list->fdesc == fd)
            return (list);
        list = list->next;
    }
    return (NULL);
}

t_struct *ft_clone(t_struct *node)
{
    t_struct *res;

    if (node == NULL)
        return (NULL);
    res = ft_create_elem(node->s, node->fdesc, node->index);
    res->next = ft_clone(node->next);
    return (res);
}

int read_line(int  fd, t_struct **list)
{
    char    buf[BUFF_SIZE+1] = { ENDL };
    int         bytes;
    char        *new;
    bytes = read(fd, buf, BUFF_SIZE);
    if (bytes > 0)
    {
        buf[bytes] = '\0';
        if ((*list)->s)
            new = ft_strjoin((*list)->s, buf);
        else
            new = buf;
        if (!new)
            return (-1);
        if ((*list)->s)
            free((*list)->s);
        (*list)->s = ft_strnew(ft_strlen(new));
        (*list)->s = ft_strcpy((*list)->s, new);
    }
    return (bytes);
}

int get_next_line(int const fd, char **line)
{
    static t_struct *list = NULL;
    t_struct *node;
    t_struct *temporary;
    char        *tmp;
    int         ret;
    int         a;

    if (!list && (!(list = ft_create_elem(NULL, fd, NULL))))
        return (-1);
    if (!line || fd == -1)
        return(-1);
    if (!(node = (t_struct *)malloc(sizeof(t_struct))))
        return (-1);
    if (!(temporary = (t_struct *)malloc(sizeof(t_struct))))
        return (-1);
    node = list;
    temporary = find_fd(&node, fd);
    if (!temporary)
    {
        ft_list_push_back(&node, NULL, fd, NULL);
        temporary = find_fd(&node, fd);
    }
    list->s = (temporary->s);
    list->index = (temporary->index);
    list->fdesc = temporary->fdesc;
    // free(temporary);
    if (temporary->s)
        printf("temporary->s=%d", *(temporary->s));
    printf("=s\n");
    if (list->s)
        printf("list->s=%d", *(list->s));
    printf("=s\n");

    printf("fd=%d\n", list->fdesc);

    //if endl_index == NULL instead of ft_strchr(stock, ENDL), then occasionally a 
    //loop will be entered for buffsize 16 or 32

    //the next lines allow us to, if our previous run through caught more than one new line,
    //skip a read this time.
    list->index = list->s ? ft_strchr(list->s, ENDL) : NULL;
    // if (list->s)
    //     list->index = ft_strchr(list->s, ENDL);

    while (list->index == NULL)
    {
        ret = read_line(fd, &list);
        if (ret == 0)
        {
            printf("test\n");

            if ((list->index = ft_strchr(list->s, '\0')) == list->s)
            {
                list = node;
                return (0);
            }

        }
        else if (ret < 0)
            return (-1);
        else
        {
            list->index = ft_strchr(list->s, ENDL);
        }
    }
    a = 0;
    *line = ft_strnew(1000000);
    while ((list->s)[a])
    {
       if ((list->s)[a] == '\n')
           break;
        (*line)[a] = (list->s)[a];
        a++;
    }
    tmp = ft_strdup(list->index+1);
    free(list->s);
    if (tmp)
        list->s = ft_strdup(tmp);
    free(tmp);
    list = ft_clone(node);
    if (node)
        ft_lstdel(&node);
    return (1);
}

void mt_assert(int n)
{
    if (n == 0)
    {
        printf("strcmp != 0\n");
    }
    else
        printf("strcmp == 0\n");
}

// int main(void)
// {

//     char    *line;
//     int     out;
//     int     p[2];
//     char    *str;
//     int     len = 50;

//     str = (char *)malloc(1000 * 1000);
//     *str = '\0';
//     while (len--)
//         strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
//     out = dup(1);
//     pipe(p);
//     dup2(p[1], 1);
//     if (str)
//         write(1, str, strlen(str));
//     close(p[1]);
//     dup2(out, 1);
//     get_next_line(p[0], &line);
//     printf("%s\n", line);
//     mt_assert(strcmp(line, str) == 0);
// }
