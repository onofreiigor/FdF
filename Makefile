NAME = fdf
FL = -Wall -Werror -Wextra
XFL = -lmlx -framework OpenGL -framework AppKit
#XFL = -lmlx -lXext -lX11 -lm

SRC = main.c \
	ft_*.c \
	get_next_line.c
OBJ = $(SRC:.c=.o)

all:
	make -C libft/
	gcc -c $(SRC) $(FL) -I libft/ 
	gcc -o fdf $(OBJ) $(FL) $(XFL) -L libft/ -lft
clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
.PHONY: all clean fclean re