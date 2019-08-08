NAME=ft_ls.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c

RM=rm -f

SRC=ft_dellst.c ft_filesize.c ft_filetimes.c ft_filename.c ft_display_recursive.c ft_permission.c ft_filelink.c \
	ft_display_all.c ft_display_dir.c ft_lstsort.c ft_swaplst.c ft_isflag.c ft_lstrevsort.c ft_dirlst.c \
	ft_newlstelem.c ft_pathname.c ft_display_long.c ft_isdir.c ft_rec.c \

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	$(CC) ft_ls.c ft_ls.a libft/libft.a

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
