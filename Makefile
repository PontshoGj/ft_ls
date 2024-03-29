NAME=ft_ls.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c

RM=rm -f

SRC=include/ft_filesize.c include/ft_filetimes.c include/ft_filename.c include/ft_permission.c include/ft_filelink.c \
	include/ft_display_all.c include/ft_display_dir.c include/ft_isflag.c include/ft_filetype.c include/ft_chkxattr.c \
	include/ft_pathname.c include/ft_display_long.c include/ft_isdir.c include/ft_rec.c include/ft_isfile.c \
	include/ft_islnk.c include/ft_sortarry.c include/ft_arrydirlist.c include/ft_dirnu.c include/ft_chksort.c \
	include/ft_longdisplay.c include/ft_getlink.c include/ft_freearry.c include/ft_stb.c include/ft_checkfl.c \
	include/ft_checkfiledir.c include/ft_setugid.c include/ft_chkvali.c include/ft_swap.c include/ft_freepath.c \

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	mv *.o include/
	ar rc $(NAME) $(OBJ)
	mv ft_ls.a include
	cd libft && make re && make clean
	cd ft_printf && make re && make clean
	$(CC) -o ft_ls include/ft_ls.c include/ft_ls.a libft/libft.a ft_printf/src/ft_printf.a
	rm -f include/*.o

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
