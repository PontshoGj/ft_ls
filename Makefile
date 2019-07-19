NAME=ft_ls.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c -I .

RM=rm -f

SRC=ft_dellst.c ft_filesize.c ft_filetimes.c ft_filename.c ft_joinfiled.c ft_rdirec.c ft_permission.c ft_filelink.c

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
