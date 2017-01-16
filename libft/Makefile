# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ionofrei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/24 18:13:28 by ionofrei          #+#    #+#              #
#    Updated: 2016/10/24 18:13:48 by ionofrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a
SRC = ft_*.c
FL = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
$(NAME):
	gcc $(FL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean
	gcc $(FL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
.PHONY: clean
