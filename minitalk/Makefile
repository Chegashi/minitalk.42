# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 16:23:40 by mochegri          #+#    #+#              #
#    Updated: 2021/06/26 18:29:55 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

flags = -Wall -Wextra -Werror

SRCS =	lib_standar.c \
		lib_standar_2.c \
		lib_standar_3.c

all : $(NAME)

$(NAME): $(SRCS)
	@gcc $(flags) server.c $(SRCS) -o server
	@gcc $(flags) client.c $(SRCS) -o client

clean:
	@rm -f $(SRCS:.c=.o) client server

fclean:	clean
	@rm -rf *.o

re:		fclean all

bonus:	
	@gcc $(flags) client_bonus.c $(SRCS) -o client
checker: re

# push_swap : re
# 	./push_swap
.PHONY : bonus clean fclean re