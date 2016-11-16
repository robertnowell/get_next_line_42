NAME = libft.a
SRC =  ft_lstnew.c ft_set_print_color_to.c ft_strncpy.c \
ft_memalloc.c ft_strcat.c ft_strnequ.c \
ft_atoi.c ft_memccpy.c ft_strchr.c ft_strnew.c \
ft_bzero.c ft_memchr.c ft_strclr.c ft_strnstr.c \
ft_memcmp.c ft_strcmp.c ft_strrchr.c ft_memcpy.c ft_strcpy.c \
ft_isalnum.c ft_memdel.c ft_strdel.c ft_strsplit.c \
ft_isalpha.c ft_memmove.c ft_strdup.c ft_strstr.c \
ft_isascii.c ft_memset.c ft_strequ.c ft_strsub.c \
ft_isdigit.c ft_putchar.c ft_striter.c ft_strtrim.c \
ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_tolower.c \
ft_itoa.c ft_putendl.c ft_strjoin.c ft_toupper.c ft_putendl_fd.c \
ft_strlcat.c ft_lstadd.c ft_puterr.c ft_strlen.c	\
ft_lstdel.c ft_putnbr.c ft_strmap.c	 \
ft_lstdelone.c ft_putnbr_fd.c ft_strmapi.c \
ft_lstiter.c ft_putstr.c ft_strncat.c \
ft_lstmap.c ft_putstr_fd.c ft_strncmp.c ft_is_sort.c \
ft_count_digits.c ft_strrev.c ft_wordcount.c ft_itoabase.c ft_set_print_color_to.c \
ft_lst_clone.c ft_lst_push_back.c ft_create_elem.c ft_lstdel_if.c \
ft_strlen_until.c ft_strdup_until.c ft_putstr_digits.c ft_lstdel_tstruct.c \
ft_lstdelone_tstruct.c 


OBJ = $(SRC:.c=.o)

HEADER = /includes/libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all clean
