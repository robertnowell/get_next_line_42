#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 40

// typedef struct	s_struct
// {
// 	char	*s;
// 	int		fdesc;
// 	char 	*index;
// 	struct	s_struct *next;
// }				t_struct;

int get_next_line(const int fd, char **line);

#endif
