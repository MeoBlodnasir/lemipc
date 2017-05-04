# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduban <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 12:05:34 by aduban            #+#    #+#              #
#    Updated: 2016/04/29 16:48:40 by aduban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lemipc

SRC=\
	main.c		\
	shm.c		\
	sem.c		\
	mq.c		\
	player.c	\
	utils.c		\
	ia.c	\

.PHONY: libft.a

OBJ = $(SRC:.c=.o)

all : libft.a $(NAME)

libft.a:
		@$(MAKE) -C ./libft

$(NAME) : $(OBJ)
		@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L./libft/ -lftprintf -I ./libft -lpthread -lrt -lm

%.o: %.c
		@gcc -Wall -Wextra -Werror -I./libft/ -o $@ -c $^

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
