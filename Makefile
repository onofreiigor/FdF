NAME = fdf
FL = -Wall -Werror -Wextra
XFL = -lmlx -framework OpenGL -framework AppKit
SRC = main.c \
	ft_*.c \
	get_next_line.c
OBJ = $(SRC:.c=.o)

all:
	make -C libft/
	gcc $(FL) -I libft/ -c $(SRC)
	gcc $(FL) $(XFL) -o fdf $(OBJ) -L libft/ -lft
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean
	gcc $(FL) -I libft/ -c $(SRC)
	gcc $(FL) $(XFL) -o fdf $(OBJ) -L libft/ -lft
.PHONY: all clean fclean re