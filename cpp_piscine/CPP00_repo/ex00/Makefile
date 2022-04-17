# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 07:40:38 by jgalian-          #+#    #+#              #
#    Updated: 2021/09/29 07:44:48 by jgalian-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone
CC =		clang++
CPPFLAGS =	-Wall -Wextra -Werror -c
SRCS =		megaphone.cpp utils.cpp
OBJS =		$(SRCS:.cpp=.o)
OBJ_PATH = 	./obj

all: $(NAME)

$(NAME): $(SRCS)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CPPFLAGS) $^
	mv $(OBJS) $(OBJ_PATH)
	$(CC) $(OBJ_PATH)/* -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
