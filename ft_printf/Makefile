NAME=ft_printf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -c -I .

RM=rm -f

SRC=src/ft_outint.c src/ft_outstr.c src/ft_outuint.c src/ft_outdoub.c src/ft_printf.c src/ft_printstr.c \
src/ft_printhexa.c src/ft_printpadd.c src/ft_printhandler.c src/ft_padd.c src/ft_paddfloat.c \
src/ft_floatpre.c src/ft_givespace.c src/ft_printlong.c src/ft_outputlong.c src/ft_printshort.c \
src/ft_outputshort.c src/ft_addplus.c src/ft_outputunsignedlong.c src/ft_outputunsignedshort.c \
src/ft_outputshortun.c src/ft_nbr.c src/ft_nbrstr.c src/ft_nbr2.c src/ft_outputshorthex.c \
src/ft_outputshortoct.c \

OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC)
	cp *.o src/
	ar rc $(NAME) $(OBJ)
	cp ft_printf.a src/
	rm -f src/*.o
all: $(NAME)

clean:
	$(RM) $(OBJ) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all