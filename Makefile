# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 15:07:17 by jugingas          #+#    #+#              #
#    Updated: 2023/03/16 11:24:26 by jugingas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

CFLAGS		+=	-Wall -Werror -Wextra -I./include

SRC			=	src/push_swap.c		\
				src/utils.c			\
				src/utils2.c		\
				src/ft_atoi.c		\
				src/moves_sp.c		\
				src/moves_r.c		\
				src/algo.c			\
				src/algo2.c			\
				src/debug.c

OBJ			=	$(SRC:.c=.o)

NAME		=	push_swap

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
