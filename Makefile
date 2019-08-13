NAME=ft_ls.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c

RM=rm -f

SRC= include/ft_dellst.c include/ft_filesize.c include/ft_filetimes.c include/ft_filename.c include/ft_display_recursive.c include/ft_permission.c include/ft_filelink.c \
	include/ft_display_all.c include/ft_display_dir.c include/ft_lstsort.c include/ft_swaplst.c include/ft_isflag.c include/ft_lstrevsort.c include/ft_dirlst.c \
	include/ft_newlstelem.c include/ft_pathname.c include/ft_display_long.c include/ft_isdir.c include/ft_rec.c include/ft_isfile.c \

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	mv *.o include/
	ar rc $(NAME) $(OBJ)
	mv ft_ls.a include
	cd libft && make re && make clean
	$(CC) -o ft_ls include/ft_ls.c include/ft_ls.a libft/libft.a
	rm -f include/*.o

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
