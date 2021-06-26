# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 16:23:40 by mochegri          #+#    #+#              #
#    Updated: 2021/06/26 15:59:43 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

flags = -Wall -Wextra -Werror

SRCS =	lib_standar.c \
		lib_standar_2.c \
		lib_standar_3.c

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS)
	@ar -rc minitalk.a *.o
	@ranlib minitalk.a
	@gcc $(flags) server.c minitalk.a -o server
	@gcc $(flags) client.c minitalk.a -o client
	@rm minitalk.a

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) client server

fclean:	clean
	@rm -rf client
	@rm -rf server
	@rm -rf *.o
	@rm -rf minitalk.a

re:		fclean all

checker: re

# push_swap : re
# 	./push_swap